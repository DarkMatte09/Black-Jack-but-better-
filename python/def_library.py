import time
import random
import os
from ascii import blackjack


def easter_egg():
    if random.random() < 0.01:
        print("Sir, the song of Freddy fazbear saved you")
        print("You unlocked this easter egg final, enjoy your money ;)")
        return True
    else:
        print("You lose sir, your number is lower than the bank's")
        return False


def pulisci_terminale():
    os.system('cls' if os.name == 'nt' else 'clear')


def start_welcome():
    pulisci_terminale()
    print(blackjack)
    time.sleep(1)
    print("Welcome to the BlackJack game! Get ready for EVERYTHING (literaly)")
    time.sleep(2)