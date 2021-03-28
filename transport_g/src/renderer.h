#pragma once

#include "descriptions.h"
#include "json.h"
#include "sphere.h"

#include <vector>

	class Renderer {
	public:
		Renderer(const Descriptions::StopsDict& stops_dict,
			     const Descriptions::BusesDict& buses_dict,
			     const Json::Dict& routing_settings_json);
	private:
		struct RenderSettings {
			double width;
			double height;
			double padding;
			double stop_radius;
			double line_width;
			int stop_label_font_size;
			Svg::Point stop_label_offset;
			Svg::Color underlayer_color;
			double underlayer_width;
			vector<Svg::Color> color_palette;
	  };

		RenderSettings MakeRenderSettings(const Json::Dict& json);
		RenderSettings render_settings_;
	};

