import json
import os

MONEY_FILE = "money.json"
STARTING_MONEY = 1000

def load_money():
    if not os.path.exists(MONEY_FILE):
        return STARTING_MONEY
    try:
        with open(MONEY_FILE, "r") as f:
            val = json.load(f).get("money", STARTING_MONEY)
            return STARTING_MONEY if val <= 0 else val
    except Exception:
        return STARTING_MONEY

def save_money(money):
    with open(MONEY_FILE, "w") as f:
        json.dump({"money": money}, f)