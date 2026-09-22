import json
import os

HISTORY_FILE = "history.json"

def load_history():
    if not os.path.exists(HISTORY_FILE):
        return {"games": [], "win_streak": 0, "loss_streak": 0, "best_win_streak": 0, "best_loss_streak": 0}
    with open(HISTORY_FILE, "r") as f:
        return json.load(f)

def save_history(history):
    with open(HISTORY_FILE, "w") as f:
        json.dump(history, f, indent=2)

def record_result(history, result, bet, utente, banco):
    entry = {"result": result, "bet": bet, "utente": utente, "banco": banco}
    history["games"].append(entry)

    if result == "win":
        history["win_streak"] += 1
        history["loss_streak"] = 0
        history["best_win_streak"] = max(history["best_win_streak"], history["win_streak"])
    elif result == "loss":
        history["loss_streak"] += 1
        history["win_streak"] = 0
        history["best_loss_streak"] = max(history["best_loss_streak"], history["loss_streak"])
    else:
        history["win_streak"] = 0
        history["loss_streak"] = 0

    save_history(history)
    return history