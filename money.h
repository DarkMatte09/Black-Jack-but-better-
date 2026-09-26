#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <fstream>
#include <sstream>

class BankrollManager {
public:
    static constexpr long long STARTING_MONEY = 1000;

    explicit BankrollManager(std::string filename = "money.json") 
        : filepath(std::move(filename)), current_balance(STARTING_MONEY) {
        load();
    }

    long long get_balance() const { return current_balance; }
    void set_balance(long long amount) { current_balance = amount; }
    void add_money(long long amount) { current_balance += amount; }
    void deduct_money(long long amount) { current_balance -= amount; }
    bool can_bet(long long bet) const { return bet > 0 && bet <= current_balance; }

    long long load() {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            current_balance = STARTING_MONEY;
            return current_balance;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();
        file.close();

        size_t pos = content.find("\"money\"");
        if (pos == std::string::npos) {
            current_balance = STARTING_MONEY;
            return current_balance;
        }

        size_t colon = content.find(':', pos);
        if (colon == std::string::npos) {
            current_balance = STARTING_MONEY;
            return current_balance;
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
            current_balance = STARTING_MONEY;
            return current_balance;
        }

        try {
            current_balance = std::stoll(content.substr(start, end - start));
        } catch (...) {
            current_balance = STARTING_MONEY;
        }
        return current_balance;
    }

    void save() const {
        std::ofstream file(filepath);
        if (file.is_open()) {
            file << "{\n  \"money\": " << current_balance << "\n}\n";
            file.close();
        }
    }

private:
    std::string filepath;
    long long current_balance;
};

inline long long load_money() {
    BankrollManager mgr;
    return mgr.get_balance();
}

inline void save_money(long long money) {
    BankrollManager mgr;
    mgr.set_balance(money);
    mgr.save();
}

#endif
