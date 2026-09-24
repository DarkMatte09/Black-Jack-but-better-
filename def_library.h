#ifndef DEF_LIBRARY_H
#define DEF_LIBRARY_H

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "ascii.h"

inline void sleep_sec(double seconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(seconds * 1000)));
}

inline void pulisci_terminale() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

inline bool easter_egg() {
    double r = static_cast<double>(std::rand()) / RAND_MAX;
    if (r < 0.01) {
        std::cout << "Sir, the song of Freddy fazbear saved you\n";
        std::cout << "You unlocked this easter egg final, enjoy your money ;)\n";
        return true;
    } else {
        std::cout << "You lose sir, your number is lower than the bank's\n";
        return false;
    }
}

inline void start_welcome() {
    pulisci_terminale();
    std::cout << blackjack << "\n";
    sleep_sec(1);
    std::cout << "Welcome to the BlackJack game! Get ready for EVERYTHING (literaly)\n";
    sleep_sec(2);
}

#endif
