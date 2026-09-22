import json
import os

MONEY_FILE = "money.json"
STARTING_MONEY = 1000

def load_money():
    if not os.path.exists(MONEY_FILE):
        return STARTING_MONEY
    with open(MONEY_FILE, "r") as f:
        return json.load(f)["money"]

def save_money(money):
    with open(MONEY_FILE, "w") as f:
        json.dump({"money": money}, f)