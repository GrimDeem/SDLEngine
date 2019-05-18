#include <nlohmann/json.hpp>

/*
    Safely extract element from json or return defaultValue
*/
template<typename T>
T extract(const nlohmann::json& data, const std::string& element, const T& defaultValue) {
    try {
        return data["title"].get<T>();
    } catch (...) {
        return defaultValue;
    }
}
