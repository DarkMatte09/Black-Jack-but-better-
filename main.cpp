#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "ascii.h"
#include "def_library.h"
#include "history.h"
#include "money.h"

#ifdef _WIN32
#include <windows.h>
#endif

static long long money = 0;
static History history;

static void handle_exit() {
    save_money(money);
}

static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

static void wait_exit() {
    std::cout << "\nPress Enter to exit...";
    std::string s;
    std::getline(std::cin, s);
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    money = load_money();
    if (money <= 0) {
        money = 1000;
        save_money(money);
    }
    history = load_history();
    std::atexit(handle_exit);

    pulisci_terminale();
    std::cout << blackjack << "\n\n\n";

    std::string luck_start;
    std::cout << "Are you feeling lucky (y/n): ";
    std::getline(std::cin, luck_start);
    std::string ls = trim(luck_start);

    if (ls == "y" || ls == "Y" || ls == "yes" || ls == "Yes") {
        int luck_start_coin = (std::rand() % 2) + 1;
        std::cout << "I'll trow a coin you have 50%\n";
        sleep_sec(1);
        std::cout << "suspence\n";
        if (luck_start_coin == 2) {
            std::cout << "Not your day...\n";
            sleep_sec(1);
            wait_exit();
            std::exit(0);
        } else {
            std::cout << "What a lucky man\n";
            sleep_sec(2);
        }
    }

    pulisci_terminale();
    std::cout << blackjack << "\n\n\n";

    std::string decision;
    while (true) {
        std::cout << "want to play? (y/n): ";
        if (!std::getline(std::cin, decision)) {
            return 0;
        }
        std::string d = trim(decision);
        if (d == "y" || d == "Y" || d == "yes" || d == "Yes") {
            std::cout << "Sure? You can't comeback after this decision\n";
            break;
        } else if (d == "n" || d == "N" || d == "no" || d == "No") {
            std::cout << "Nice decision sir\n";
            wait_exit();
            std::exit(0);
        } else {
            std::cout << "You have to choose between y or n sir\n";
        }
    }

    while (true) {
        std::cout << "Are you sure? (y/n): ";
        if (!std::getline(std::cin, decision)) {
            return 0;
        }
        std::string d = trim(decision);
        if (d == "y" || d == "Y" || d == "yes" || d == "Yes") {
            std::cout << "Good luck sir, you will need it\n";
            break;
        } else if (d == "n" || d == "N" || d == "no" || d == "No") {
            std::cout << "Nice decision sir\n";
            wait_exit();
            std::exit(0);
        } else {
            std::cout << "You have to choose between y or n sir\n";
        }
    }
    sleep_sec(2);

    while (true) {
        if (money <= 0) {
            std::cout << "\nYou ran out of money! Game over sir.\n";
            std::cout << "Want to reload a fresh $1000 bankroll? (y/n): ";
            std::string restart;
            if (std::getline(std::cin, restart)) {
                std::string r = trim(restart);
                if (r == "y" || r == "Y" || r == "yes" || r == "Yes") {
                    money = 1000;
                    save_money(money);
                    continue;
                }
            }
            std::cout << "Game over sir.\n";
            wait_exit();
            break;
        }

        std::string esito = "";

        pulisci_terminale();
        std::cout << blackjack << "\n\n\n";

        long long bet = 0;
        while (true) {
            std::cout << "How much do you want to bet? currently having: " << money << "$ ";
            std::string bet_str;
            if (!std::getline(std::cin, bet_str)) {
                return 0;
            }
            try {
                bet = std::stoll(bet_str);
                if (bet <= 0) {
                    std::cout << "Bet must be greater than 0.\n";
                    continue;
                }
                if (bet > money) {
                    std::cout << "You don't have enough money for that bet!\n";
                    continue;
                }
            } catch (...) {
                std::cout << "Please enter a valid number.\n";
                continue;
            }

            std::cout << "Ok sir, you bet: " << bet << "$\n";
            std::cout << "Confirm? (y/n): ";
            std::string bet_or_no;
            std::getline(std::cin, bet_or_no);
            std::string bon = trim(bet_or_no);
            if (bon == "y" || bon == "Y" || bon == "yes" || bon == "Yes") {
                break;
            }
        }

        money -= bet;
        save_money(money);

        pulisci_terminale();
        std::cout << blackjack << "\n\n\n";

        int utente = (std::rand() % 21) + 1;
        int banco = (std::rand() % 21) + 1;
        while (banco < 17) {
            banco += (std::rand() % 11) + 1;
        }

        std::cout << "Your number is:  " << utente << "\n";
        std::cout << "Do you want to hit or stand? (h/s): ";
        std::string hit_stand;
        std::getline(std::cin, hit_stand);
        std::string hs = trim(hit_stand);
        bool busted = false;

        if (hs == "s" || hs == "S" || hs == "stand" || hs == "Stand") {
            std::cout << "Ok sir, you chose to stand\n";
            if (banco > 21) {
                std::cout << "You win sir! The bank busted\n";
                esito = "win";
                sleep_sec(2);
                pulisci_terminale();
                std::cout << blackjack << "\n\n\n";
                std::cout << "Wait sir do you want to take the money you win or you want to triple it (y/n): ";
                std::string mega_win;
                std::getline(std::cin, mega_win);
                std::string mw = trim(mega_win);
                if (mw == "y" || mw == "Y" || mw == "yes") {
                    std::cout << "I'll trow a coin\n";
                    sleep_sec(1);
                    if ((std::rand() % 2) + 1 == 1) {
                        std::cout << "It came up heads and you tripled the money!\n";
                        money = money + (bet * 3);
                    } else {
                        std::cout << "It came up tails and you lost the gamble.\n";
                    }
                } else {
                    money = money + (bet * 2);
                }
                busted = true;
            } else if (utente > 21) {
                if ((std::rand() % 500) + 1 == 1) {
                    std::cout << "Sir, the song of Freddy fazbear saved you\n";
                    std::cout << "You unlocked an easter egg, enjoy your money ;)\n";
                    money = money + 9999999999LL;
                    esito = "win";
                } else {
                    std::cout << "You lose sir, your number is over 21\n";
                    esito = "loss";
                }
                busted = true;
            } else if (utente == banco) {
                std::cout << "It's a tie! You don't win, but you don't lose either\n";
                money = money + bet;
                esito = "tie";
                busted = true;
            } else if (utente > banco) {
                std::cout << "You win sir! Your number is higher than the bank's\n";
                esito = "win";
                sleep_sec(2);
                pulisci_terminale();
                std::cout << blackjack << "\n\n\n";
                std::cout << "Wait sir do you want to take the money you win or you want to triple it (y/n): ";
                std::string mega_win;
                std::getline(std::cin, mega_win);
                std::string mw = trim(mega_win);
                if (mw == "y" || mw == "Y" || mw == "yes") {
                    std::cout << "I'll trow a coin\n";
                    sleep_sec(1);
                    if ((std::rand() % 2) + 1 == 1) {
                        std::cout << "It came up heads and you tripled the money!\n";
                        money = money + (bet * 3);
                    } else {
                        std::cout << "It came up tails and you lost the gamble.\n";
                    }
                } else {
                    money = money + (bet * 2);
                }
                busted = true;
            } else if (utente < banco) {
                std::cout << "You lose sir, the bank's number is higher\n";
                esito = "loss";
                busted = true;
            }
        } else {
            while (hs == "h" || hs == "H" || hs == "hit" || hs == "Hit") {
                std::cout << "Ok sir, you chose to hit\n";
                utente += (std::rand() % 11) + 1;
                if (utente > 21) {
                    std::cout << "Your number is:  " << utente << "\n";
                    if ((std::rand() % 500) + 1 == 1) {
                        std::cout << "Sir, the song of Freddy fazbear saved you\n";
                        std::cout << "You unlocked this easter egg final, enjoy your money ;)\n";
                        money = money + 9999999999LL;
                        esito = "win";
                    } else {
                        std::cout << "You lose sir, your number is over 21\n";
                        esito = "loss";
                    }
                    busted = true;
                    break;
                } else {
                    std::cout << "Your number is:  " << utente << "\n";
                    std::cout << "Do you want to hit or stand? (h/s): ";
                    std::getline(std::cin, hit_stand);
                    hs = trim(hit_stand);
                }
            }
        }

        if (!busted) {
            std::cout << "Your number is:  " << utente << "\n";
            std::cout << "The bank's number is:  " << banco << "\n";
            if (banco > 21) {
                std::cout << "You win sir! The bank busted\n";
                esito = "win";
                sleep_sec(2);
                pulisci_terminale();
                std::cout << blackjack << "\n\n\n";
                std::cout << "Wait sir do you want to take the money you win or you want to triple it (y/n): ";
                std::string mega_win;
                std::getline(std::cin, mega_win);
                std::string mw = trim(mega_win);
                if (mw == "y" || mw == "Y" || mw == "yes") {
                    std::cout << "I'll trow a coin\n";
                    sleep_sec(1);
                    if ((std::rand() % 2) + 1 == 1) {
                        std::cout << "It came up heads and you tripled the money!\n";
                        money = money + (bet * 3);
                    } else {
                        std::cout << "It came up tails and you lost the gamble.\n";
                    }
                } else {
                    money = money + (bet * 2);
                }
            } else if (utente > banco) {
                std::cout << "You win sir! your number is higher than the bank's\n";
                esito = "win";
                sleep_sec(2);
                pulisci_terminale();
                std::cout << blackjack << "\n\n\n";
                std::cout << "Wait sir do you want to take the money you win or you want to triple it (y/n): ";
                std::string mega_win;
                std::getline(std::cin, mega_win);
                std::string mw = trim(mega_win);
                if (mw == "y" || mw == "Y" || mw == "yes") {
                    std::cout << "I'll trow a coin\n";
                    sleep_sec(1);
                    if ((std::rand() % 2) + 1 == 1) {
                        std::cout << "It came up heads and you tripled the money!\n";
                        money = money + (bet * 3);
                    } else {
                        std::cout << "It came up tails and you lost the gamble.\n";
                    }
                } else {
                    money = money + (bet * 2);
                }
            } else if (utente == banco) {
                std::cout << "It's a tie! You don't win, but you don't lose either\n";
                money = money + bet;
                esito = "tie";
            } else if (utente < banco) {
                std::cout << "You lose sir, the bank's number is higher\n";
                esito = "loss";
                if (easter_egg()) {
                    money = money + 9999999999LL;
                    esito = "win";
                }
            }
        }

        if (!esito.empty()) {
            history = record_result(history, esito, bet, utente, banco);
            save_money(money);
            std::cout << "Win streak: " << history.win_streak << " | Loss streak: " << history.loss_streak << "\n";
        }

        if (money > 0) {
            sleep_sec(2);
        }
    }

    save_money(money);
    return 0;
}
