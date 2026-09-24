#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <fstream>
#include <sstream>

inline const std::string MONEY_FILE = "money.json";
inline const long long STARTING_MONEY = 1000;

inline long long load_money() {
    std::ifstream file(MONEY_FILE);
    if (!file.is_open()) {
        return STARTING_MONEY;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    file.close();

    size_t pos = content.find("\"money\"");
    if (pos == std::string::npos) {
        return STARTING_MONEY;
    }

    size_t colon = content.find(':', pos);
    if (colon == std::string::npos) {
        return STARTING_MONEY;
    }

    size_t start = colon + 1;
    while (start < content.size() && (content[start] == ' ' || content[start] == '\t' || content[start] == '\r' || content[start] == '\n')) {
        start++;
    }

    size_t end = start;
    if (end < content.size() && (content[end] == '-' || content[end] == '+')) {
        end++;
    }
    while (end < content.size() && content[end] >= '0' && content[end] <= '9') {
        end++;
    }

    if (start == end) {
        return STARTING_MONEY;
    }

    try {
        return std::stoll(content.substr(start, end - start));
    } catch (...) {
        return STARTING_MONEY;
    }
}

inline void save_money(long long money) {
    std::ofstream file(MONEY_FILE);
    if (file.is_open()) {
        file << "{\n  \"money\": " << money << "\n}\n";
        file.close();
    }
}

#endif
