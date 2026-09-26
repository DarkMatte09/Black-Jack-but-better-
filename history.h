#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

struct GameEntry {
    std::string result;
    long long bet = 0;
    int utente = 0;
    int banco = 0;
};

class HistoryTracker {
public:
    explicit HistoryTracker(std::string filename = "history.json")
        : filepath(std::move(filename)), win_streak(0), loss_streak(0), best_win_streak(0), best_loss_streak(0) {
        load();
    }

    int get_win_streak() const { return win_streak; }
    int get_loss_streak() const { return loss_streak; }
    int get_best_win_streak() const { return best_win_streak; }
    int get_best_loss_streak() const { return best_loss_streak; }
    const std::vector<GameEntry>& get_games() const { return games; }

    void record(const std::string& result, long long bet, int utente, int banco) {
        games.push_back({result, bet, utente, banco});

        if (result == "win") {
            win_streak++;
            loss_streak = 0;
            best_win_streak = std::max(best_win_streak, win_streak);
        } else if (result == "loss") {
            loss_streak++;
            win_streak = 0;
            best_loss_streak = std::max(best_loss_streak, loss_streak);
        } else {
            win_streak = 0;
            loss_streak = 0;
        }
        save();
    }

    void load() {
        std::ifstream file(filepath);
        if (!file.is_open()) return;

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();
        file.close();

        win_streak = extract_int_field(content, "win_streak", 0);
        loss_streak = extract_int_field(content, "loss_streak", 0);
        best_win_streak = extract_int_field(content, "best_win_streak", 0);
        best_loss_streak = extract_int_field(content, "best_loss_streak", 0);
    }

    void save() const {
        std::ofstream file(filepath);
        if (!file.is_open()) return;

        file << "{\n";
        file << "  \"games\": [\n";
        for (size_t i = 0; i < games.size(); ++i) {
            const auto& g = games[i];
            file << "    {\n";
            file << "      \"result\": \"" << g.result << "\",\n";
            file << "      \"bet\": " << g.bet << ",\n";
            file << "      \"utente\": " << g.utente << ",\n";
            file << "      \"banco\": " << g.banco << "\n";
            file << "    }" << (i + 1 < games.size() ? "," : "") << "\n";
        }
        file << "  ],\n";
        file << "  \"win_streak\": " << win_streak << ",\n";
        file << "  \"loss_streak\": " << loss_streak << ",\n";
        file << "  \"best_win_streak\": " << best_win_streak << ",\n";
        file << "  \"best_loss_streak\": " << best_loss_streak << "\n";
        file << "}\n";
        file.close();
    }

private:
    static int extract_int_field(const std::string& content, const std::string& key, int default_val) {
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

    std::string filepath;
    std::vector<GameEntry> games;
    int win_streak;
    int loss_streak;
    int best_win_streak;
    int best_loss_streak;
};

struct History {
    std::vector<GameEntry> games;
    int win_streak = 0;
    int loss_streak = 0;
    int best_win_streak = 0;
    int best_loss_streak = 0;
};

inline History load_history() {
    HistoryTracker tracker;
    History h;
    h.games = tracker.get_games();
    h.win_streak = tracker.get_win_streak();
    h.loss_streak = tracker.get_loss_streak();
    h.best_win_streak = tracker.get_best_win_streak();
    h.best_loss_streak = tracker.get_best_loss_streak();
    return h;
}

inline void save_history(const History& h) {
    HistoryTracker tracker;
    for (const auto& g : h.games) {
        tracker.record(g.result, g.bet, g.utente, g.banco);
    }
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

    HistoryTracker tracker;
    tracker.record(result, bet, utente, banco);
    return history;
}

#endif
