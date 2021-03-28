#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>


namespace Svg {


	struct Point {
		double x;
		double y;
		Point() = default;
		Point(double x_, double y_) : x(x_), y(y_) {}
	};

	struct Rgb {
		int red;
		int green;
		int blue;
		Rgb() = default;
		Rgb(int red_, int green_, int blue_) : red(red_), green(green_), blue(blue_) {}
	};

	class Color {
	public:
		Color() {
			data = "none";
		}
		Color(std::string color) : data(color) {}
		Color(Rgb& rgb) {
			std::stringstream ss;
			ss << "rgb(" << rgb.red << ',' << rgb.green << ',' << rgb.blue << ')';
			data = ss.str();
		}
		std::string GetData() {
			return data;
		}

	private:
		std::string data;
	};

	const Color NoneColor = Color();

	std::ostream& operator<<(std::ostream& os, Color& color) {
		os << color.GetData();
		return os;
	}

	class Object {
	public:
		virtual void RenderInd(std::ostream& os) const = 0;

		void RenderGen(std::ostream& os) {
			os << "fill=\"" << fill_color << "\" ";
			os << "stroke=\"" << stroke_color << "\" ";
			os << "stroke-width=\"" << stroke_width << "\" ";
			if (stroke_line_cap.has_value()) {
				os << "stroke-linecap=\"" << stroke_line_cap.value() << "\" ";
			}
			if (stroke_line_cap.has_value()) {
				os << "stroke-linejoin=\"" << stroke_line_join.value() << "\" ";
			}
		}

		Object& SetFillColor(const Color& color) {
			fill_color = color;
			return *this;
		}

		Object& SetStrokeColor(const Color& color) {
			stroke_color = color;
			return *this;
		}

		Object& SetStrokeWidth(double width) {
			stroke_width = width;
			return *this;
		}

		Object& SetStrokeLineCap(const std::string& s) {
			stroke_line_cap = s;
			return *this;
		}

		Object& SetStrokeLineJoin(const std::string& s) {
			stroke_line_join = s;
			return *this;
		}

	private:
		Color fill_color = NoneColor;
		Color stroke_color = NoneColor;
		double stroke_width = 1.0;
		std::optional<std::string> stroke_line_cap;
		std::optional<std::string> stroke_line_join;
	};

	class Circle : public Object {
	public:
		Circle() = default;

		void RenderInd(std::ostream& os) {
			os << "<circle ";
			os << "cx=\"" << cx << "\" ";
			os << "cy=\"" << cy << "\" ";
			os << "r=\"" << r << "\" ";
			RenderGen(os);
			os << "/>";
		}

		Circle& SetCenter(Point& p) {
			cx = p.x;
			cy = p.y;
			return *this;
		}

		Circle& SetRadius(double radius) {
			r = radius;
			return *this;
		}

	private:
		double cx;
		double cy;
		double r;
	};

	class Polyline : public Object {
	public:
		Polyline() = default;

		void RenderInd(std::ostream& os) {
			os << "<polyline ";
			os << "points=\"" << data << "\" ";
			os << RenderGen(os);
			os << "/>";
		}

		Polyline& AddPoint(Point& p) {
			std::stringstream ss;
			ss << p.x << ',' << p.y;
			data += ss.str();
			data += ' ';
			return *this;
		}

	private:
		std::string data = "";
	};

	class Text : public Object {
	public:
		Text() = default;

		void RenderInd(std::ostream& os) {
			os << "<text ";
			os << "x=\"" << x << "\" ";
			os << "y=\"" << y << "\" ";
			os << "dx=\"" << dx << "\" ";
			os << "dy=\"" << dy << "\" ";
			os << "font-size=\"" << font_size << "\" ";
			if (font_family.has_value()) {
				os << "font-family=\"" << font_family.value() << "\" ";
			}
			os << RenderGen(os);
			os << ">";
			os << data;
			os << "</text>";
		}

		Text& SetPoint(Point& p) {
			x = p.x;
			y = p.y;
			return *this;
		}

		Text& SetOffset(Point& p) {
			dx = p.x;
			dy = p.y;
			return *this;
		}

		Text& SetFontSize(uint32_t f_size) {
			font_size = f_size;
			return *this;
		}

		Text& SetFontFamily(const std::string& font_f) {
			font_family = font_f;
			return *this;
		}

		Text& SetData(const std::string& data_) {
			data = data_;
			return *this;
		}
	private:
		double x = 0;
		double y = 0;
		double dx = 0;
		double dy = 0;
		uint32_t font_size = 1;
		std::optional<std::string> font_family;
		std::string data = "";
	};

	class Document {
	public:
		Document() = default;

		void Add(Object& object) {
			data.push_back(object);
		}

		void Render(std::ostream& os) {
			os << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>";
			os << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">";
			for (auto& object : data) {

			}
			os << "</svg>";
		}

	private:
		std::vector<Object> data;
	};
}
