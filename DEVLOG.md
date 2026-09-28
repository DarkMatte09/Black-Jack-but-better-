# Development Time Log (68 Hours Total)

Project: Black-Jack-but-better-
Participant: DarkMatte09
Event: Hack Club - Out to C
Language: C++ (C++17 Standard), Python prototype, Web Terminal

---

### Summary Breakdown

| Phase | Description | Hours |
|---|---|---|
| Phase 1 | Rules Research, ASCII Design & Prototype | 14h |
| Phase 2 | Persistence, Bankroll Engine & Streak Analytics | 12h |
| Phase 3 | Web Terminal Port & GitHub Pages Deployment | 10h |
| Phase 4 | Full C++17 Engine Migration & OOP Architecture | 18h |
| Phase 5 | Cross-Platform Build Systems, Edge Cases & Verification | 14h |
| **Total** | | **68h** |

---

### Detailed Activity Log

#### Phase 1: Rules Research, ASCII Design & Prototype (14 Hours)
- 4.0h: Researched Blackjack dealer rules, soft 17 stand/hit mechanics, house advantage, and terminal game UX.
- 3.5h: Designed custom ASCII banners, character spacing, block rendering, and layout aesthetics.
- 4.5h: Developed core game loop in Python: card distribution, hit/stand loop, bust checks, and dealer threshold logic.
- 2.0h: Modularized code into separate modules (`main.py`, `ascii.py`, `def_library.py`).

#### Phase 2: Persistence, Bankroll Engine & Streak Analytics (12 Hours)
- 3.5h: Designed JSON schema for player bankroll (`money.json`) and session analytics (`history.json`).
- 3.5h: Implemented `load_money()`, `save_money()`, and automatic exit handling via `atexit`.
- 3.0h: Engineered streak tracking algorithms: consecutive wins, loss streaks, and session peak records.
- 2.0h: Implemented risk/reward mechanics: startup 50/50 coin toss and post-win triple-or-nothing gamble.

#### Phase 3: Web Terminal Port & GitHub Pages Deployment (10 Hours)
- 4.0h: Developed browser-based terminal emulator in `index.html` replicating CLI interaction without external frameworks.
- 2.5h: Integrated Web Audio API frequency synthesis for retro terminal and casino sound cues.
- 2.0h: Fixed viewport scaling and ASCII glyph wrap corruption across mobile and desktop browsers.
- 1.5h: Configured GitHub Pages deployment and local storage mirroring for persistent game sessions online.

#### Phase 4: Full C++17 Engine Migration & OOP Architecture (18 Hours)
- 5.0h: Re-architected system into modern C++17: Object-Oriented design with encapsulated classes.
- 4.5h: Built `BankrollManager` class (`money.h`): RAII file stream handling, balance validation, and zero-dependency JSON serialization.
- 4.0h: Built `HistoryTracker` class (`history.h`): vector-based game logs, streak progression metrics, and disk synchronization.
- 2.5h: Handled UTF-8 console output for Windows (`SetConsoleOutputCP(CP_UTF8)`) and POSIX terminal standards.
- 2.0h: Restructured repository: migrated original Python prototype into dedicated `python/` directory.

#### Phase 5: Cross-Platform Build Systems, Edge Cases & Verification (14 Hours)
- 3.5h: Configured GNU `Makefile` and `CMakeLists.txt` for seamless compilation across GCC, Clang, and MSVC.
- 4.0h: Robustness testing: non-numeric inputs, negative wagers, balance overflows (`long long`), and abnormal termination handling.
- 3.5h: Game loop validation: verified dealer draw distributions, edge-case tie resolution, and easter egg triggers.
- 3.0h: Final documentation, README alignment for Out to C rubric, licensing (MIT), and repository cleanup.
