#include <iostream>
#include <map>
#include <string>

struct CompareKeys {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        double lhsValue = std::stod(lhs.substr(0, lhs.find(' ')));
        double rhsValue = std::stod(rhs.substr(0, rhs.find(' ')));
        if (lhs.find("cent") != std::string::npos) {
            lhsValue /= 100;
        }
        if (rhs.find("cent") != std::string::npos) {
            rhsValue /= 100;
        }
        return lhsValue < rhsValue;
    }
};

int main() {
    std::map<std::string, int, CompareKeys> values = {
        {"1 cent", 5},
        {"2 cent", 3},
        {"5 cent", 5},
        {"10 cent", 3},
        {"50 cent", 7},
        {"1 euro", 5},
        {"2 euro", 3},
        {"5 euro", 5},
        {"10 euro", 1},
        {"20 euro", 5},
        {"50 euro", 8},
        {"100 euro", 3}
        };

    for (const auto& [key, value] : values) {
        std::cout << key << ": " << value << " kpl" << std::endl;
    }

    return 0;
}
