#include "svg_render.h"
#include <vector>
#include <cassert>
#include "misc.h"

const std::unordered_map<
    std::string,
    std::function<void(const SvgRender*,Svg::Document&)>
> SvgRender::render_table 
    {
        { "bus_lines" , static_cast<BaseRenderFP>(&SvgRender::RenderBuses) },
        { "stop_points" , static_cast<BaseRenderFP>(&SvgRender::RenderStops) },
        { "bus_labels" , static_cast<BaseRenderFP>(&SvgRender::RenderBusLabels) },
        { "stop_labels" , static_cast<BaseRenderFP>(&SvgRender::RenderStopLabels) }
    };

const std::unordered_map<
    std::string,
    std::function<void(const SvgRender*,Svg::Document&,const SvgRender::RouteMap&)>
> SvgRender::render_table_route 
    {
        { "bus_lines" , static_cast<RouteRenderFP>(&SvgRender::RenderBuses) },
        { "stop_points" , static_cast<RouteRenderFP>(&SvgRender::RenderStops) },
        { "bus_labels" , static_cast<RouteRenderFP>(&SvgRender::RenderBusLabels) },
        { "stop_labels" , static_cast<RouteRenderFP>(&SvgRender::RenderStopLabels) }
    };

SvgRender& SvgRender::SetWidth(double x){
    settings.width = x;
    return *this;
}
SvgRender& SvgRender::SetHeight(double x){
    settings.height = x;
    return *this;
}
SvgRender& SvgRender::SetPadding(double x){
    settings.padding = x;
    return *this;
}
SvgRender& SvgRender::SetStopRadius(double x){
    settings.stop_radius = x;
    return *this;
}
SvgRender& SvgRender::SetLineWidth(double x){
    settings.line_width = x;
    return *this;
}
SvgRender& SvgRender::SetStopLabelFontSize(int x){
    settings.stop_label_font_size = x;
    return *this;
}
SvgRender& SvgRender::SetStopLabelOffset(Svg::Point x){
    settings.stop_label_offset = x;
    return *this;
}
SvgRender& SvgRender::SetUnderlayerColor(Svg::Color x){
    settings.underlayer_color = x;
    return *this;
}
SvgRender& SvgRender::SetUnderlayerWidth(double x){
    settings.underlayer_width = x;
    return *this;
}
SvgRender& SvgRender::SetBusLabelFontSize(int x){
    settings.bus_label_font_size = x;
    return *this;
}
SvgRender& SvgRender::SetBusLabelOffset(Svg::Point x){
    settings.bus_label_offset = x;
    return *this;
}
SvgRender& SvgRender::SetColorPalette(std::vector<Svg::Color> x){
    settings.color_palette = move(x);
    return *this;
}

SvgRender& SvgRender::SetLayers(std::vector<std::string> x){
    settings.layers = move(x);
    return *this;
}

SvgRender& SvgRender::SetOuterMargin (double x) {
    settings.outer_margin = x;
    return *this;
}

Svg::Point SvgRender::PointFromLocation(double lat, double lon) const {
    return Svg::Point(lon,lat);
}

struct ColorGenerator {
    ColorGenerator(const std::vector<Svg::Color>& palette)
    : palette(palette),cur_index(0) {}
    Svg::Color operator()() {
        auto res = palette[cur_index++ % palette.size()];
        return res;
    }
    void Reset(void) { cur_index = 0; }
    const std::vector<Svg::Color>& palette;
    size_t cur_index;
};

void SvgRender::AddBusLabel(Svg::Document& doc,const std::string& bus_name, 
                            const std::string& stop, Svg::Color color) const {
    Svg::Text common = Svg::Text{}
        .SetPoint(PointFromLocation(stops_compressed.at(stop).latitude, stops_compressed.at(stop).longtitude))
        .SetOffset(settings.bus_label_offset)
        .SetFontSize(settings.bus_label_font_size)
        .SetFontFamily("Verdana")
        .SetFontWeight("bold")
        .SetData(bus_name);
    Svg::Text underlayer = common;
    doc.Add(
        underlayer
        .SetFillColor(settings.underlayer_color)
        .SetStrokeColor(settings.underlayer_color)
        .SetStrokeWidth(settings.underlayer_width)
        .SetStrokeLineCap("round")
        .SetStrokeLineJoin("round")
    );
    doc.Add(
        common.SetFillColor(color)
    );
}

void SvgRender::RenderBuses(Svg::Document& doc) const {
    for(const auto& [name,bus] : buses) {
        Svg::Polyline bus_line;
        bus_line.SetStrokeColor(bus_to_color.at(name))
                .SetStrokeWidth(settings.line_width)
                .SetStrokeLineCap("round")
                .SetStrokeLineJoin("round");
        for(const auto& stop : bus.route) {
            bus_line.AddPoint(PointFromLocation(stops_compressed.at(stop).latitude, stops_compressed.at(stop).longtitude));
        }
        if(bus.route.size() && bus.route_type == Bus::RouteType::ONEWAY) {
            for(const auto& stop : Range(bus.route.rbegin() + 1,bus.route.rend())) {
                bus_line.AddPoint(PointFromLocation(stops_compressed.at(stop).latitude, stops_compressed.at(stop).longtitude));
            }
        }
        doc.Add(bus_line);
    }
}

void SvgRender::RenderStops(Svg::Document& doc) const {
    for(const auto& [_,stop] : stops_compressed) {
        doc.Add(
            Svg::Circle{}
            .SetFillColor("white")
            .SetRadius(settings.stop_radius)
            .SetCenter(PointFromLocation(stop.latitude, stop.longtitude))
        );
    }
}

void SvgRender::FillBusColors() const {
    ColorGenerator color_generator(settings.color_palette);
    for(const auto& [name,bus] : buses) {
        auto bus_color = color_generator();
        bus_to_color[name] = bus_color;
    }
}

void SvgRender::RenderBusLabels(Svg::Document& doc) const {
    for(const auto& [name,bus] : buses) {
        auto bus_color = bus_to_color.at(name);
        if(bus.route.size()) {
            const auto& start_stop = *bus.route.begin();
            const auto& finish_stop = *prev(bus.route.end());

            AddBusLabel(doc,name,start_stop,bus_color);
            if(start_stop != finish_stop) {
                AddBusLabel(doc,name,finish_stop,bus_color);
            }
        }
    }
}

void SvgRender::RenderStopLabels(Svg::Document& doc) const {
    for(const auto& [name,stop] : stops_compressed) {
        Svg::Text common = Svg::Text{}
            .SetPoint(PointFromLocation(stop.latitude, stop.longtitude))
            .SetOffset(settings.stop_label_offset)
            .SetFontSize(settings.stop_label_font_size)
            .SetFontFamily("Verdana")
            .SetData(std::string(name));
        Svg::Text underlayer = common;
        doc.Add(
            underlayer
            .SetFillColor(settings.underlayer_color)
            .SetStrokeColor(settings.underlayer_color)
            .SetStrokeWidth(settings.underlayer_width)
            .SetStrokeLineCap("round")
            .SetStrokeLineJoin("round")
        );
        doc.Add(
            common.SetFillColor("black")
        );
    }
}

void SvgRender::RenderBuses(Svg::Document& doc, const RouteMap& route_map) const {
    for(auto edge: route_map) {
        std::string_view bus_name = edge->item_name_;
        const auto& stop_names = edge->stops_;
        Svg::Polyline bus_line;
        bus_line.SetStrokeColor(bus_to_color.at(bus_name))
                .SetStrokeWidth(settings.line_width)
                .SetStrokeLineCap("round")
                .SetStrokeLineJoin("round");
        for(auto it = stop_names.begin(); it != stop_names.end(); it++) {
            bus_line.AddPoint(
                PointFromLocation(
                    stops_compressed.at(*it).latitude, 
                    stops_compressed.at(*it).longtitude)
                );
        }
        doc.Add(std::move(bus_line));
    }
}
void SvgRender::RenderStopLabels(Svg::Document& doc, const RouteMap& route_map) const {
    std::unordered_set<std::string_view> drawn;
    for(auto edge : route_map) {
        std::string_view bus_name = edge->item_name_;
        const auto& stop_names = edge->stops_;
        std::string_view stop_begin = *stop_names.begin();
        std::string_view stop_end = *prev(stop_names.end());
        /// TODO: f_add_label would be useful as a method to reuse in other RenderStopLabels overload
        auto f_add_label = [this,&doc](std::string_view stop_name){
             const auto& stop = stops_compressed.at(stop_name);
             Svg::Text common = Svg::Text{}
                .SetPoint(PointFromLocation(stop.latitude, stop.longtitude))
                .SetOffset(settings.stop_label_offset)
                .SetFontSize(settings.stop_label_font_size)
                .SetFontFamily("Verdana")
                .SetData(std::string(stop_name));
            Svg::Text underlayer = common;
            doc.Add(
                underlayer
                .SetFillColor(settings.underlayer_color)
                .SetStrokeColor(settings.underlayer_color)
                .SetStrokeWidth(settings.underlayer_width)
                .SetStrokeLineCap("round")
                .SetStrokeLineJoin("round")
            );
            doc.Add(
                common.SetFillColor("black")
            );
        };
        if(!drawn.count(stop_begin)) {
            f_add_label(stop_begin);
            drawn.insert(stop_begin);
        }
        if(!drawn.count(stop_end)) {
            f_add_label(stop_end);
            drawn.insert(stop_end);
        }
    }
}
void SvgRender::RenderBusLabels(Svg::Document& doc, const RouteMap& route_map) const{
    for(auto edge : route_map) {
        std::string_view bus_name = edge->item_name_;
        const auto& stop_names = edge->stops_;
        std::string_view stop_begin = *stop_names.begin();
        std::string_view stop_end = *prev(stop_names.end());
        auto f_is_terminal = 
        [this] (std::string_view bus_name, std::string_view stop_name) -> bool {
            const auto& bus = buses.at(std::string(bus_name));
            if(*bus.route.begin() == stop_name || *prev(bus.route.end()) == stop_name) {
                return true;
            } else {
                return false;
            }
        };
        if(f_is_terminal(bus_name,stop_begin)) {
            AddBusLabel(doc,std::string(bus_name),std::string(stop_begin),bus_to_color.at(bus_name));
        }
        if(f_is_terminal(bus_name,stop_end)) {
            AddBusLabel(doc,std::string(bus_name),std::string(stop_end),bus_to_color.at(bus_name));
        }
    }
}
void SvgRender::RenderStops(Svg::Document& doc, const RouteMap& route_map) const{
        // std::unordered_set<std::string_view> drawn;
    for(auto edge : route_map) {
        std::string_view bus_name = edge->item_name_;
        const auto& stop_names = edge->stops_;
        /// TODO: Take care of empty stop_names?
        for(auto it = stop_names.begin(); it != stop_names.end(); it++) {
                doc.Add(
                    Svg::Circle{}
                    .SetFillColor("white")
                    .SetRadius(settings.stop_radius)
                    .SetCenter(PointFromLocation(
                        stops_compressed.at(*it).latitude, 
                        stops_compressed.at(*it).longtitude
                    ))
                );
        }
    }
}

bool SvgRender::StopsAreAdjacent(const std::string& one, const std::string& another) const {
    const Stop& lhs = stops.at(one);
    const Stop& rhs = stops.at(another);
    std::unordered_set<std::string> intersection;
    std::set_intersection(lhs.buses.begin(), lhs.buses.end(),
                          rhs.buses.begin(), rhs.buses.end(),
                          std::inserter(intersection,intersection.begin()));
    if(!intersection.size()) {
        return false;
    }
    for(const auto& bus_name : intersection) {
        const Bus& bus = buses.at(bus_name);
        
        for (auto it1 = std::find(bus.route.begin(),bus.route.end(),one); 
                it1 != bus.route.end();
                it1 = std::find(next(it1),bus.route.end(),one)) 
        {
            if((it1 != bus.route.begin() && *prev(it1) == another) || 
                (next(it1) != bus.route.end() && *next(it1) == another)) {
                return true;
            }
        }
    }
    return false;
}

std::vector<std::string_view> SvgRender::GetAdjacentStops(const std::string_view stop_name, const std::unordered_set<std::string_view>& considered) const {
    const Stop& stop = stops.at(std::string(stop_name));
    std::vector<std::string_view> res;
    for(const auto& bus_name : stop.buses) {
        const Bus& bus = buses.at(bus_name);
        for (auto it = std::find(bus.route.begin(),bus.route.end(),stop_name); 
                it != bus.route.end();
                it = std::find(next(it),bus.route.end(),stop_name)) {
            if(it != bus.route.begin() && considered.count(*prev(it))) {
                res.push_back(*prev(it));
            }
            if(it != prev(bus.route.end()) && considered.count(*next(it))) {
                res.push_back(*next(it));
            }
        }
    }
    return res;
}

size_t SvgRender::BundleCoordinates(const std::map<double,std::string_view>& sorted_map, double StopsPos::*field) const {
    size_t idx, max_idx = 0;
    std::unordered_set<std::string_view> considered;
    for(const auto [_,name] : sorted_map) {
        auto neighbours = GetAdjacentStops(name,considered);
        idx = 0;
        for(const std::string_view stop : neighbours) {
            idx = std::max(idx,static_cast<size_t>(stops_compressed.at(stop).*field) + 1);
        }
        stops_compressed[name].*field = idx;
        considered.insert(name);
        max_idx = std::max(idx,max_idx);
    }
    return max_idx;
}

bool SvgRender::StopIsBase(const std::string& stop_name) const {
    const Stop& stop = stops.at(stop_name);
    // ?????? ???????????????????????? ??????????????????, ???? ???????? ????, ?????????? ?????????????? ???????????????? ?????????? ???????????? ????????????????
    if(stop.buses.empty() || stop.buses.size() > 1) {
        return true;
    }
    // ?????? ???????????????? (?????????? ?????????????? ???????????????? ?????????? ????????????????)
    for(const auto& bus_name : stop.buses) {
        const Bus& bus = buses.at(bus_name);
        if(bus.route.empty()) {
            continue;
        }
        if(stop_name == bus.route.front() || stop_name == bus.route.back()) {
            return true;
        }
    }
    //  ?????????? ?????????????? ???????????????? ???????? ??????????????, ???? ?????????? ?????? ???????????? ???? ???????? ??????????????
    const Bus& bus = buses.at(*stop.buses.begin());
    size_t stop_cnt = std::count(bus.route.begin(),bus.route.end(),stop_name);
    if(bus.route_type == Bus::RouteType::ONEWAY) {
        stop_cnt *= 2;
    }
    if(stop_cnt > 2) {
        return true;
    }

    return false;
}

////// TODO: pass by reference? --------------\/\/\/
Svg::Document SvgRender::RenderRoute(RouteMap route) const {
    auto doc = Render();
    doc.Add(
        Svg::Rect{}
        .SetPoint({-settings.outer_margin,-settings.outer_margin})
        .SetDimensions
        (
            settings.width + settings.outer_margin * 2,
            settings.height + settings.outer_margin * 2
        )
        .SetFillColor(settings.underlayer_color)
    );
    for(const auto& layer : settings.layers) {
        render_table_route.at(layer)(this,doc,route);
    }
    return doc;
}

Svg::Document SvgRender::Render() const {
    if(!base_map_cache) {
        std::unordered_map<std::string_view,double> lat;
        std::unordered_map<std::string_view,double> lon;
        std::map<double,std::string_view> lat_sorted;
        std::map<double,std::string_view> lon_sorted;

        for(const auto& [name,bus] : buses) {
            if(bus.route.empty()) continue;

            auto base_it = bus.route.begin(); 
            auto base_it_next = base_it;
            double lon_step, lat_step {.0};
        
            for(auto it = base_it; it != bus.route.end(); it++) {
                const std::string& stop_name = *it;
                if(it == base_it_next) {
                    if(!lat.count(stop_name)) {
                        lat[stop_name] = stops.at(stop_name).latitude;
                        lon[stop_name] = stops.at(stop_name).longtitude;
                    }
                    base_it = base_it_next;
                    base_it_next = std::find_if(next(it),bus.route.end(),
                                        [this](const std::string& stop){
                                            return StopIsBase(stop);
                                        });
                    if(base_it_next != bus.route.end()) {
                        lon_step = (
                            stops.at(*base_it_next).longtitude - stops.at(*base_it).longtitude
                        ) / (base_it_next - base_it);
                        lat_step = (
                            stops.at(*base_it_next).latitude - stops.at(*base_it).latitude
                        ) / (base_it_next - base_it);
                    }
                    continue;
                }
                lat[stop_name] = stops.at(*base_it).latitude + lat_step * (it - base_it);
                lon[stop_name] = stops.at(*base_it).longtitude + lon_step * (it - base_it);
            }
        }

        for(const auto& [name,stop] : stops) {
            if(lat.count(name)) {
                lat_sorted[lat.at(name)] = name;
                lon_sorted[lon.at(name)] = name;
            } else {
                lat_sorted[stop.latitude] = name;
                lon_sorted[stop.longtitude] = name;
            }
        }
        
        size_t x_idx = BundleCoordinates(lon_sorted, &StopsPos::longtitude);
        size_t y_idx = BundleCoordinates(lat_sorted, &StopsPos::latitude);
        
        double x_step = (x_idx == 0) ? 0 : (settings.width - 2 * settings.padding) / (x_idx);
        double y_step = (y_idx == 0) ? 0 : (settings.height - 2 * settings.padding) / (y_idx);

        for(auto& [name,coordinates] : stops_compressed) {
            coordinates.longtitude = coordinates.longtitude * x_step + settings.padding;
            coordinates.latitude = settings.height - settings.padding - (coordinates.latitude * y_step);
        }

        Svg::Document doc;
        FillBusColors();

        for(const auto& layer : settings.layers) {
            render_table.at(layer)(this,doc);
        }

        base_map_cache = std::move(doc);
    }

    return *base_map_cache;
}