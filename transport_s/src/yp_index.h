#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <variant>
#include <optional>
#include "descriptions.h"
#include "misc.h"
#include "database.pb.h"

namespace YP {
    template<typename It>
    auto intersection (It begin_, It end_) {
        using Container = typename It::value_type;
        if(begin_ == end_) {
            return Container{};
        }

        Container last_intersection = *begin_;
        Container curr_intersection;

        for (auto it = begin_ + 1; it != end_; ++it) {
            std::set_intersection(last_intersection.begin(), last_intersection.end(),
                it->begin(), it->end(),
                std::inserter(curr_intersection, curr_intersection.end()));
            std::swap(last_intersection, curr_intersection);
            curr_intersection.clear();
        }
        return last_intersection;
    }

        struct Phone {
        enum class Type {
            PHONE,
            FAX
        };
        std::optional<Type> type;
        std::string formatted;
        std::string country_code;
        std::string local_code;
        std::string number;
        std::string extension;
        std::string description;
    };

    struct RequestItem {
        enum class Type {
            NAMES, URLS, RUBRICS, PHONES
        };
        Type type;
        std::variant<
            std::vector<std::string>,
            std::vector<Phone>
        > data;
    };

    struct NearbyStop {
        NearbyStop(std::string name_, uint32_t meters_)
        : name(name_), meters(meters_) {}
        std::string name;
        uint32_t meters;
    };

    struct CompanyDescription {
        Coords coords;
        std::vector<NearbyStop> nearby_stops;
        std::optional<std::string_view> rubric;
    };

    using Companies = std::unordered_map<std::string_view,CompanyDescription>;

    class YellowPagesIndex {
    public:
        YellowPagesIndex(const YellowPages::Database& proto_db);
        std::vector<std::string_view> Search(const std::vector<RequestItem>& requests) const;
        const std::string& CompanyNameByIdx(size_t idx) const;
        const Companies& GetCompanies() const { return descriptions; }
    private:
        using Index = std::unordered_map<std::string,std::unordered_set<size_t>>;

        std::vector<std::string> company_names;
        Companies descriptions;

        Index names;
        Index urls;
        Index rubrics;

        std::unordered_map<size_t,std::vector<Phone>> company_to_phones;
    };
}
