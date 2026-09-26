<div align="center">

```
  BLACKJACK — BUT BETTER
 ────────────────────────
 Hack Club: Out to C Submission
 terminal-based • high stakes • pure C++17
```

[![Language](https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org)
[![Event](https://img.shields.io/badge/Hack%20Club-Out%20to%20C-ec3750?style=for-the-badge)](https://github.com/hackclub/out-to-c)
[![Live Demo](https://img.shields.io/badge/Live%20Demo-Play%20Online-4fd6be?style=for-the-badge&logo=google-chrome&logoColor=black)](https://darkmatte09.github.io/Black-Jack-but-better-/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-000000?style=for-the-badge)](https://github.com/DarkMatte09/Black-Jack-but-better-)
[![License](https://img.shields.io/badge/License-MIT-black?style=for-the-badge)](LICENSE)

<br/>

> A ruthless terminal Blackjack experience engineered in C++17 with real betting stakes, persistence, win-streak analytics, and rare secrets.

[Play the Live Web Terminal](https://darkmatte09.github.io/Black-Jack-but-better-/)

</div>

---

### Hack Club: Out to C Project Details

This project is built for Hack Club's **Out to C** event.

- Primary Language: C++ (C++17 Standard)
- Core Paradigms: Object-Oriented Programming (OOP), RAII, STL container algorithms, cross-platform terminal management.
- Why C++ was chosen: C++ allows direct systems control and high performance while providing modern abstractions through classes, templates, and strict type safety. It enables clean encapsulation of game states, custom serialization for game persistence without bulky external dependencies, and low-latency terminal execution.

---

### Beyond The Tutorial: Genuine Effort & Custom Systems

Unlike standard tutorial blackjack scripts, this project features:

1. Object-Oriented State Encapsulation:
   - BankrollManager (`money.h`): Handles bankroll management, bet validation, and JSON disk serialization using RAII file streams.
   - HistoryTracker (`history.h`): Tracks individual game entries, consecutive win/loss streaks, and all-time records in structured JSON format.

2. Custom Visuals & Cross-Platform Display:
   - UTF-8 console output switching for Windows consoles (`CP_UTF8`) and POSIX terminal support for high-resolution ASCII banner art.
   - Screen clearing and sleep helpers without platform-specific hardcoding.

3. High-Stakes Risk/Reward Game Mechanics:
   - Initial 50/50 coin-toss gamble at boot.
   - Automated dealer draw AI respecting the soft 17 threshold rule.
   - Double-or-triple coin-toss multiplier on winning hands.
   - Low-probability (1%) clutch save easter eggs.

4. Multi-Platform Build Systems:
   - Standard GNU Make configuration (`Makefile`).
   - Cross-platform CMake configuration (`CMakeLists.txt`).
   - Direct compiler command support for `g++` and `clang++`.

5. Web Terminal Edition:
   - Embedded browser terminal published on GitHub Pages for zero-setup evaluator testing.

---

### Quickstart & Compilation

#### Option A: Direct g++ / Clang++ (Recommended)

```bash
g++ -std=c++17 -O2 main.cpp -o blackjack
./blackjack
```

#### Option B: GNU Make

```bash
make
./blackjack
```

#### Option C: CMake

```bash
cmake -B build
cmake --build build
./build/blackjack
```

#### Option D: Play Online (Browser)

No compilation needed:
[https://darkmatte09.github.io/Black-Jack-but-better-/](https://darkmatte09.github.io/Black-Jack-but-better-/)

---

### Project Architecture

```
.
├── main.cpp          # Game loop, input handling, and decision flow
├── ascii.h           # Raw string literal ASCII banners
├── def_library.h     # Cross-platform terminal control and easter eggs
├── history.h         # HistoryTracker class and streak analytics
├── money.h           # BankrollManager class and balance persistence
├── Makefile          # GNU Make build targets
├── CMakeLists.txt    # CMake configuration
├── index.html        # Web terminal edition for GitHub Pages
├── README.md         # Out to C submission documentation
└── python/           # Original Python prototype
    ├── main.py
    ├── ascii.py
    ├── def_library.py
    ├── history.py
    └── money.py
```

---

<div align="center">

Built for Hack Club Out to C by [DarkMatte09](https://github.com/DarkMatte09)

</div>
