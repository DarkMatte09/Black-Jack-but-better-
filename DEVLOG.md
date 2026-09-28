# Development Time Log (68h 43m Total)

Project: Black-Jack-but-better-
Participant: DarkMatte09
Event: Hack Club - Out to C
Primary Language: C++ (22h 55m tracked in C++17)
Total Tracked Time: 68h 43m (Hackatime / WakaTime verified)

---

### Hackatime Verified Summary

| Category | Details | Tracked Time |
|---|---|---|
| **C++17 Core Engine** | OOP Architecture, Classes, Persistence & Build Systems | **22h 55m** |
| **Python Prototype** | Game Mechanics, Probability Design, Initial ASCII Art | **35h 50m** |
| **Web & Other** | Web Terminal Port (HTML/JS), Shell & Documentation | **9h 58m** |
| **Total** | | **68h 43m** |

---

### Detailed Activity Log

#### 1. C++17 Core Development (22 Hours 55 Minutes)
- 6.0h: Re-architecting the entire game loop into modern C++17 using Object-Oriented design.
- 5.0h: Developing `BankrollManager` class (`money.h`): RAII stream management, balance validation, and zero-dependency JSON serialization.
- 4.5h: Developing `HistoryTracker` class (`history.h`): vector-based session logs, streak metrics, and persistent file synchronization.
- 3.5h: Cross-platform terminal control and UTF-8 console output setup for Windows (`SetConsoleOutputCP(CP_UTF8)`) and POSIX.
- 2.5h: Build systems integration: GNU `Makefile` and `CMakeLists.txt` for GCC, Clang, and MSVC.
- 1.4h: Edge-case stress testing: non-numeric inputs, negative wagers, balance overflows (`long long`), and abnormal exit safety.

#### 2. Python Prototyping & Game Design (35 Hours 50 Minutes)
- 8.0h: Researching standard Blackjack rules, dealer soft 17 drawing strategies, and probability mechanics.
- 9.0h: Designing custom ASCII banners, character spacing, block alignment, and terminal visual hierarchy.
- 10.5h: Implementing initial CLI game flow in Python, testing random distributions, hit/stand loop, and bust logic.
- 8.3h: Creating initial persistence schemas (`money.json` and `history.json`), streak counters, and easter egg triggers.

#### 3. Web Terminal Port & Project Packaging (9 Hours 58 Minutes)
- 4.0h: Building standalone web terminal emulator in `index.html` replicating terminal experience in the browser.
- 2.5h: Web Audio API integration for authentic retro terminal sounds and winning chimes.
- 2.0h: Fixing ASCII glyph scaling and preventing text-wrapping across mobile viewports.
- 1.4h: GitHub Pages setup, open-source MIT licensing, repository restructuring, and Out to C documentation.
