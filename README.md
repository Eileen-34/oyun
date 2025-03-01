# Rock Paper Scissors Game

## Overview
This is a simple Rock Paper Scissors game developed in C++ using the SFML v2.6.2 (Simple and Fast Multimedia Library). 
The game features a menu, play, rules, and an about page.
The game is self-contained, meaning all assets are embedded into the executable. No additional files are required to run the game.
---

## Table of Contents
1. [Requirements](#requirements)
2. [Installation](#installation)
3. [Running the Game](#running-the-game)
4. [Game Features](#game-features)
5. [How to Play](#how-to-play)
6. [Project Structure](#project-structure)
7. [Contact](#contact)

---

## Requirements
To build and run this game on macOS, you need the following:
- **macOS**: Tested on macOS Sequoia (15.2).
- **CLion**: JetBrains IDE for C++ development.
- **CMake**: Build system (version 3.26 or higher).
- **SFML**: Multimedia library (version 2.6.2).

---

## Installation
1. **Install Dependencies**:
    - Install SFML using Homebrew:
      ```bash
      brew install sfml@2.6.2
      ```

2. **Clone the Repository**:
   ```bash
   git clone https://github.com/Eileen-34/oyun.git
   cd oyun
   ```

3. **Build the Game**:
    - Open the project in CLion and build it using the provided `CMakeLists.txt`.
    - Alternatively, build from the terminal:
      ```bash
      cmake -S . -B build
      cmake --build build
      ```

---

## Running the Game
1. **Locate the Executable**:
    - After building, the executable (`oyun`) will be in the `cmake-build-debug` or `cmake-build-release` folder.

2. **Run the Game**:

   --> **Option 1: Run from the Terminal**
    - Navigate to the cmake-build-debug folder:
      ```bash
      cd cmake-build-debug
      ```
    - Run the executable:
      ```bash
      ./oyun
      ```

   --> **Option 2: Run from Finder**
    - Open the oyun project directory in Finder. 
    - Navigate to the cmake-build-debug folder. 
    - Locate the executable file named oyun. 
    - Double-click the oyun file to open the game in a new window.

---

## Game Features
- **Main Menu**: Start the game, view rules, about page, or exit.
- **Gameplay**: Play Rock Paper Scissors against the computer.
- **Rules Page**: Learn how to play the game.
- **About Page**: Information about the game and developer.
- **Game Over Screen**: Shows the final score and allows replay or exit.

---

## How to Play
1. **Main Menu**:
    - Use the mouse to click on buttons to navigate through the game.

2. **Gameplay**:
    - Click on the Rock, Paper, or Scissors buttons to make your choice.
    - The computer will randomly select its choice.
    - The winner of each round is determined based on the rules of Rock Paper Scissors.

3. **Game Over**:
    - After 5 rounds, the game ends, and the final score is displayed.
    - Choose to play again or return to the main menu.

---

## Project Structure
```
oyun/
├── assets/
├── build                   
├── cmake-build-debug/       # Build directory (contains the executable)
├── .gitignore                 
├── About.cpp
├── About.h
├── about_background.h
├── Button.cpp
├── Button.h
├── CMakeLists.txt           # CMake build configuration
├── Game.cpp
├── Game.h
├── game_background.h
├── GameOver.cpp
├── GameOver.h
├── GameRules.cpp
├── GameRules.h
├── Play.h
├── KenneyHighSquare.h
├── main.cpp                  
├── Menu.cpp
├── Menu.h
├── paper.h
├── Play.cpp
├── Play.h
├── README.md 
├── rock.h
├── rules.h
├── scissors.h       
               
```
---

## Contact
For questions or feedback, feel free to reach out:
- **GitHub**: [Eileen_Aylin](https://github.com/Eileen-34)

---
