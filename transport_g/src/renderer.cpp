#include "renderer.h"



Renderer::RenderSettings Renderer::MakeRenderSettings(const Json::Dict& json) {
	vector<Svg::Color> color_palette;
	for (auto& node : json.at("color_palette").AsArray()) {
		color_palette.push_back(node.AsColor());
	}
	return {
	  json.at("width").AsDouble(),
	  json.at("height").AsDouble(),
	  json.at("padding").AsDouble(),
	  json.at("stop_radius").AsDouble(),
	  json.at("line_width").AsDouble(),
	  json.at("stop_label_font_size").AsInt(),
	  {json.at("stop_label_offset").AsArray()[0], json.at("stop_label_offset").AsArray()[0]},
	  json.at("underlayer_color").AsColor(),
	  json.at("underlayer_widht").AsDouble(),
	  color_palette
  };
}

