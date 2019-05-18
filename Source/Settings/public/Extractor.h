#include <nlohmann/json.hpp>

/*
    Safely extract element from json or return defaultValue
*/
template<typename T>
T extract(const nlohmann::json& data, const std::string& element, const T& defaultValue) {
    try {
        return data.at(element).get<T>();
    } catch (...) {
        return defaultValue;
    }
}

/*
    Depth 2 is enough so no need to make some complicate templates with vaargs
*/
template<typename T>
T extract(const nlohmann::json& data, const std::string& element1, const std::string& element2, const T& defaultValue) {
    try {
        return data.at(element1).at(element2).get<T>();
    } catch (...) {
        return defaultValue;
    }
}
