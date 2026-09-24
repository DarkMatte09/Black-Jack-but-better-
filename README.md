<div align="center">

```
  BLACKJACK — BUT BETTER
 ────────────────────────
 terminal-based • high stakes • pure vibe
```

[![Language](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org)
[![Python](https://img.shields.io/badge/Python-3.8+-3776AB?style=for-the-badge&logo=python&logoColor=white)](python/)
[![Live Demo](https://img.shields.io/badge/Live%20Demo-Play%20Online-4fd6be?style=for-the-badge&logo=google-chrome&logoColor=black)](https://darkmatte09.github.io/Black-Jack-but-better-/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-000000?style=for-the-badge)](https://github.com/DarkMatte09/Black-Jack-but-better-)
[![License](https://img.shields.io/badge/License-MIT-black?style=for-the-badge)](LICENSE)

<br/>

> A ruthless terminal Blackjack experience with real betting stakes, persistence, win-streak tracking, and rare secrets.

[Play the Live Web Terminal](https://darkmatte09.github.io/Black-Jack-but-better-/)

</div>

---

### Features

- C++17 Core Engine: Native high-performance terminal executable with modular architecture.
- Web Terminal Edition: Playable directly in modern browsers via GitHub Pages.
- Coin Flip Gamble: 50/50 probability test at startup.
- Persistent Bankroll: Balance is saved automatically across sessions ($1,000 starting bank).
- Streak Analytics: Tracks win/loss streaks and personal bests in JSON format.
- Classic & Dynamic Rules: Dealer AI draw logic (hits until 17), split-second hit/stand decisions.
- Rare Easter Eggs: 1% clutch save and secret endings.

---

### Quickstart

#### 1. Compile and Run (C++)

**Using g++:**
```bash
g++ -std=c++17 -O2 main.cpp -o blackjack
./blackjack
```

**Using Make:**
```bash
make
./blackjack
```

**Using CMake:**
```bash
cmake -B build
cmake --build build
./build/blackjack
```

#### 2. Run Python Version

```bash
cd python
python main.py
```

#### 3. Play Online (Browser)

Visit [darkmatte09.github.io/Black-Jack-but-better-](https://darkmatte09.github.io/Black-Jack-but-better-/) to play instantly.

---

### Project Structure

```
.
├── main.cpp          # Core C++ game loop and terminal flow
├── ascii.h           # ASCII header banners
├── def_library.h     # Terminal management and easter egg utilities
├── history.h         # Game history and streak persistence
├── money.h           # Bankroll loader and saver
├── Makefile          # GNU Make build script
├── CMakeLists.txt    # CMake configuration
├── index.html        # Web terminal edition for GitHub Pages
├── README.md         # Documentation
└── python/           # Original Python implementation
    ├── main.py
    ├── ascii.py
    ├── def_library.py
    ├── history.py
    └── money.py
```

---

<div align="center">

Built by [DarkMatte09](https://github.com/DarkMatte09)

</div>
