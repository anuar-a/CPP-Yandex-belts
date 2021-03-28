#include "ini.h"
#include <sstream>


Ini::Section& Ini::Document::AddSection(string name) {
	return sections[name];
}
const Ini::Section& Ini::Document::GetSection(const string& name) const {
	return sections.at(name);
}
size_t Ini::Document::SectionCount() const {
	return sections.size();
}


Ini::Document Ini::Load(istream& input) {
	Document doc;
	string section_name;
	for (std::string line; std::getline(input, line);) {
		if (line == "") {
			continue;
		} else if (line[0] == '[') {
			section_name = line.substr(1, line.size() - 2);
			doc.AddSection(section_name);
		} else {
			size_t pos = line.find('=');
			string left = line.substr(0, pos);
			doc.AddSection(section_name).insert({left, line.substr(pos + 1)});
		}

	}
	return doc;
}

