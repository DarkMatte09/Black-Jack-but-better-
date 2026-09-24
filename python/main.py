# main.py
# ---------------------------------------------------------------
# --------------------------------------------------------------
#
#           A welcome to all developer who will see this
#         This is a simple project that i made for my self
#                (and maybe a little bit of help)
#
#                ⠀⠀⠀⠀⢀⠠⠤⠀⢀⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
#                ⠀⠀⠐⠀⠐⠀⠀⢀⣾⣿⡇⠀⠀⠀⠀⠀⢀⣼⡇⠀⠀⠀⠀
#                ⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⠀⠀⠀⠀⣴⣿⣿⠇⠀⠀⠀⠀
#                ⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣇⠀⠀⢀⣾⣿⣿⣿⠀⠀⠀⠀⠀
#                ⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠐⠀⡀
#                ⠀⠀⠀⠀⢰⡿⠉⠀⡜⣿⣿⣿⡿⠿⢿⣿⣿⡃⠀⠀⠂⠄⠀
#                ⠀⠀⠒⠒⠸⣿⣄⡘⣃⣿⣿⡟⢰⠃⠀⢹⣿⡇⠀⠀⠀⠀⠀
#                ⠀⠀⠚⠉⠀⠊⠻⣿⣿⣿⣿⣿⣮⣤⣤⣿⡟⠁⠘⠠⠁⠀⠀
#                ⠀⠀⠀⠀⠀⠠⠀⠀⠈⠙⠛⠛⠛⠛⠛⠁⠀⠒⠤⠀⠀⠀⠀
#                ⠨⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠀⠀⠀⠀⠀⠀
#                ⠁⠃⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ---------------------------------------------------------------
# ----------------------------------------------------------------

import time
import os
import sys
import random
import atexit
from ascii import blackjack
from def_library import pulisci_terminale, start_welcome, easter_egg
from history import load_history, record_result
from money import load_money, save_money

money = load_money()
history = load_history()
atexit.register(lambda: save_money(money))

pulisci_terminale()
print(blackjack)
print()
print()

luck_start = input("Are you feeling lucky (y/n): ")

if luck_start == "y" or luck_start == "Y":
    luck_start_coin = random.randint(1, 2)
    print("I'll trow a coin you have 50%")
    time.sleep(1)
    print("suspence")
    if luck_start_coin == 2:
        print("Not your day...")
        time.sleep(1)
        if os.name == 'nt':
            os.system('exit')
        else:
            os.system('kill -HUP $PPID')
        sys.exit()
    else:
        print("What a lucky man")
        time.sleep(2)

pulisci_terminale()
print(blackjack)
print()
print()
# welcome/decision
decision = input("want to play? (y/n): ")
if decision == "y" or decision == "Y":
    print("Sure? You can't comeback after this decision")
elif decision == "n" or decision == "N":
    print("Nice decision sir")
    sys.exit()
else:
    print("You have to choose between y or n sir")
    sys.exit()
decision = input("Are you sure? (y/n): ")
if decision == "y" or decision == "Y":
    print("Good luck sir, you will need it")
else:
    print("Nice decision sir")
    sys.exit()
time.sleep(2)


while money > 0:
    esito = None

    # Betting system
    pulisci_terminale()
    print(blackjack)
    print()
    print()
    while True:
        try:
            bet = int(input(f"How much do you want to bet? currently having: {money}$ "))
            if bet <= 0:
                print("Bet must be greater than 0.")
                continue
            if bet > money:
                print("You don't have enough money for that bet!")
                continue
        except ValueError:
            print("Please enter a valid number.")
            continue

        print(f"Ok sir, you bet: {bet}$")
        bet_or_no = input("Confirm? (y/n): ").strip().lower()
        if bet_or_no == "y":
            break

    money -= bet

    # Game
    pulisci_terminale()
    print(blackjack)
    print()
    print()
    utente = random.randint(1, 21)
    banco = random.randint(1, 21)
    while banco < 17:
        banco = banco + random.randint(1, 11)
    print("Your number is: ", utente)
    hit_stand = input("Do you want to hit or stand? (h/s): ")
    busted = False
    if hit_stand == "s" or hit_stand == "S":
        print("Ok sir, you chose to stand")
        if banco > 21:
            print("You win sir! The bank busted")
            esito = "win"
            time.sleep(3)
            pulisci_terminale()
            print(blackjack)
            print()
            print()
            mega_win = input("Wait sir do you want to take the money you win or you want to triple it (y/n):")
            if mega_win == "y" or mega_win == "Y":
                print("I'll trow a coin")
                if random.randint(1, 2) == 1:
                    money = money*3
                busted = True
            elif mega_win == "n" or mega_win == "N":
                money = money + (bet*2)
                busted = True
        elif utente > 21:
            if random.randint(1, 500) == 1:
                print("Sir, the song of Freddy fazbear saved you")
                print("You unlocked an easter egg, enjoy your money ;)")
                money = money + 9999999999
                esito = "win"
                history = record_result(history, esito, bet, utente, banco)
                save_money(money)
                sys.exit()
            else:
                print("You lose sir, your number is over 21")
                esito = "loss"
                busted = True
        elif utente == banco:
            print("It's a tie! You don't win, but you don't lose either")
            money = money + bet
            esito = "tie"
            busted = True
        elif utente > banco:
            print("You win sir! Your number is higher than the bank's")
            esito = "win"
            time.sleep(3)
            pulisci_terminale()
            print(blackjack)
            print()
            print()
            mega_win = input("Wait sir do you want to take the money you win or you want to triple it (y/n):")
            if mega_win == "y" or mega_win == "Y":
                print("I'll trow a coin")
                if random.randint(1, 2) == 1:
                    money = money*3
                busted = True
            elif mega_win == "n" or mega_win == "N":
                money = money + (bet*2)
                busted = True
        elif utente < banco:
            print("You lose sir, the bank's number is higher")
            esito = "loss"
            busted = True
    else:
        while hit_stand == "h" or hit_stand == "H":
            print("Ok sir, you chose to hit")
            utente = utente + random.randint(1, 11)
            if utente > 21:
                print("Your number is: ", utente)
                if random.randint(1, 500) == 1:
                    print("Sir, the song of Freddy fazbear saved you")
                    print("You unlocked this easter egg final, enjoy your money ;)")
                    money = money + 9999999999
                    esito = "win"
                    history = record_result(history, esito, bet, utente, banco)
                    save_money(money)
                    sys.exit()
                else:
                    print("You lose sir, your number is over 21")
                    esito = "loss"
                    busted = True
                    break
            else:
                print("Your number is: ", utente)
                hit_stand = input("Do you want to hit or stand? (h/s): ")
    if not busted:
        print("Your number is: ", utente)
        print("The bank's number is: ", banco)
        if banco > 21:
            print("You win sir! The bank busted")
            esito = "win"
            time.sleep(3)
            pulisci_terminale()
            print(blackjack)
            print()
            print()
            mega_win = input("Wait sir do you want to take the money you win or you want to triple it (y/n):")
            if mega_win == "y" or mega_win == "Y":
                print("I'll trow a coin")
                if random.randint(1, 2) == 1:
                    money = money*3
                busted = True
            elif mega_win == "n" or mega_win == "N":
                money = money + (bet*2)
                busted = True
        elif utente > banco:
            print("You win sir! your number is higher than the bank's")
            esito = "win"
            time.sleep(3)
            pulisci_terminale()
            print(blackjack)
            print()
            print()
            mega_win = input("Wait sir do you want to take the money you win or you want to triple it (y/n):")
            if mega_win == "y" or mega_win == "Y":
                print("I'll trow a coin")
                if random.randint(1, 2) == 1:
                    print("It came up heads and you tripled th money!")
                    money = money*3
                busted = True
            elif mega_win == "n" or mega_win == "N":
                print("It came up tails and you lost the money")
                busted = True
        elif utente == banco:
            print("It's a tie! You don't win, but you don't lose either")
            money = money + bet
            esito = "tie"
        elif utente < banco:
            print("You lose sir, the bank's number is higher")
            esito = "loss"
            if easter_egg():
                money = money + 9999999999
                esito = "win"

    if esito:
        history = record_result(history, esito, bet, utente, banco)
        save_money(money)
        print(f"Win streak: {history['win_streak']} | Loss streak: {history['loss_streak']}")

    if money > 0:
        time.sleep(2)

print("You ran out of money! Game over sir.")
save_money(money)
sys.exit()