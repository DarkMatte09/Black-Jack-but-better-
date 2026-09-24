#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

inline const std::string HISTORY_FILE = "history.json";

struct GameEntry {
    std::string result;
    long long bet = 0;
    int utente = 0;
    int banco = 0;
};

struct History {
    std::vector<GameEntry> games;
    int win_streak = 0;
    int loss_streak = 0;
    int best_win_streak = 0;
    int best_loss_streak = 0;
};

inline int extract_int_field(const std::string& content, const std::string& key, int default_val = 0) {
    size_t pos = content.find("\"" + key + "\"");
    if (pos == std::string::npos) return default_val;
    size_t colon = content.find(':', pos);
    if (colon == std::string::npos) return default_val;
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
    if (start == end) return default_val;
    try {
        return std::stoi(content.substr(start, end - start));
    } catch (...) {
        return default_val;
    }
}

inline History load_history() {
    History h;
    std::ifstream file(HISTORY_FILE);
    if (!file.is_open()) {
        return h;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    file.close();

    h.win_streak = extract_int_field(content, "win_streak", 0);
    h.loss_streak = extract_int_field(content, "loss_streak", 0);
    h.best_win_streak = extract_int_field(content, "best_win_streak", 0);
    h.best_loss_streak = extract_int_field(content, "best_loss_streak", 0);

    return h;
}

inline void save_history(const History& h) {
    std::ofstream file(HISTORY_FILE);
    if (!file.is_open()) return;

    file << "{\n";
    file << "  \"games\": [\n";
    for (size_t i = 0; i < h.games.size(); ++i) {
        const auto& g = h.games[i];
        file << "    {\n";
        file << "      \"result\": \"" << g.result << "\",\n";
        file << "      \"bet\": " << g.bet << ",\n";
        file << "      \"utente\": " << g.utente << ",\n";
        file << "      \"banco\": " << g.banco << "\n";
        file << "    }" << (i + 1 < h.games.size() ? "," : "") << "\n";
    }
    file << "  ],\n";
    file << "  \"win_streak\": " << h.win_streak << ",\n";
    file << "  \"loss_streak\": " << h.loss_streak << ",\n";
    file << "  \"best_win_streak\": " << h.best_win_streak << ",\n";
    file << "  \"best_loss_streak\": " << h.best_loss_streak << "\n";
    file << "}\n";
    file.close();
}

inline History record_result(History& history, const std::string& result, long long bet, int utente, int banco) {
    history.games.push_back({result, bet, utente, banco});

    if (result == "win") {
        history.win_streak += 1;
        history.loss_streak = 0;
        history.best_win_streak = std::max(history.best_win_streak, history.win_streak);
    } else if (result == "loss") {
        history.loss_streak += 1;
        history.win_streak = 0;
        history.best_loss_streak = std::max(history.best_loss_streak, history.loss_streak);
    } else {
        history.win_streak = 0;
        history.loss_streak = 0;
    }

    save_history(history);
    return history;
}

#endif
