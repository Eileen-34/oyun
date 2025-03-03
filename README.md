# Rock Paper Scissors Game

## Overview
This is a Rock Paper Scissors Game developed by Aylin Oymak as a project submission for
"Programming in C++" course taught by D. Hackbarth in Summer Term '25
at Berlin School of Economics and Law.

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
- **macOS**: Tested on macOS (13.x) and later.
- **CLion**: JetBrains IDE for C++ development.
- **CMake**: Build system (version 3.26 or higher).
- **SFML**: Simple and Fast Multimedia Library (version 2.6.2).

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

   --> **Option 1: Using CLion**
   1. Open the project in CLion. 
   2. Reload the CMake project:
   - Go to File > Reload CMake Project. 
   3. Build the project:
   - Go to Build > Build Project.
   4. The executable (i.e. oyun) will be generated in the cmake-build-debug folder.

   --> **Option 2: Using the terminal**

   ```bash
      cmake -S . -B build
      cmake --build build
   ```

The executable (oyun) will be generated in the build folder.

---

## Running the Game
1. **Locate the Executable**:
    - After building, the executable (`oyun`) will be in the `cmake-build-debug` or `cmake-build-release` folder.

2. **Run the Game**:

   --> **Option 1: Run from Finder**
    - Open the oyun project directory in Finder. 
    - Navigate to the cmake-build-debug folder. 
    - Locate the executable file named oyun. 
    - Double-click the oyun file to open the game in a new window.

   --> **Option 2: Run from the Terminal**
   - Navigate to the cmake-build-debug folder:
     ```bash
     cd cmake-build-debug
     ```
   - Run the executable:
     ```bash
     ./oyun
     ```
---

## Game Features
The game features a menu, play, rules, and an about page.

- **Menu:** Start the game, view rules, about page, or exit by clicking on x or using esc on keyboard.
- **Play:** Play Rock Paper Scissors against the computer.
- **Rules:** Learn how to play the game.
- **About:** Information about the game and developer.
- **Game Over Screen:** Shows the final score and allows replay or exit.
  
**Note on assets:**
  All assets (such as fonts and images) are embedded as hex code in the executable, enabling memory-based loading
  instead of file-based methods.
  This avoids potential errors related to file paths or missing resources and ensures successful execution across different macOS devices.
---

## How to Play
1. **Menu**:
    - Use the mouse to click on buttons to navigate through the game.


2. **Play**:
    - Click on the Rock, Paper, or Scissors buttons to make your choice.
    - The computer will randomly select its choice.
    - The winner of each round is determined based on the rules of Rock Paper Scissors.
    - Player can go back to menu page and quit the game while playing.


3. **Game Over**:
    - After 6th round, the game ends, and the final score is displayed.
    - Choose to play again or return to the main menu.

---

## Project Structure
```
oyun/
├── assets/                  # Font and images used in the game
├── cmake-build-debug/       # Build directory (contains the executable)
├── .gitignore               # Specifies files to ignore in Git  
├── About.cpp                # Implementation of the About page
├── About.h                  # Header file for the About page
├── about_background.h       # Background image for the About page (converted to hex code)
├── Button.cpp               # Implementation of the Button class
├── Button.h                 # Header file for the Button class
├── CMakeLists.txt           # CMake build configuration
├── Game.cpp                 # Implementation of the Game class
├── Game.h                   # Header file for the Game class
├── game_background.h        # Background image for the game (converted to hex code)
├── GameOver.cpp             # Implementation of the Game Over screen
├── GameOver.h               # Header file for the Game Over screen
├── GameRules.cpp            # Implementation of the Game Rules page
├── GameRules.h              # Header file for the Game Rules page
├── KenneyHighSquare.h       # Font file (Kenney High Square) converted to hex code
├── main.cpp                 # Entry point of the game
├── Menu.cpp                 # Implementation of the Main Menu
├── Menu.h                   # Header file for the Main Menu
├── paper.h                  # Paper image (converted to hex code)
├── Play.cpp                 # Implementation of the Play screen
├── Play.h                   # Header file for the Play screen
├── README.md 
├── rock.h                   # Rock image (converted to hex code)
├── rules.h                  # Rules image (converted to hex code)
├── scissors.h               # Scissors image (converted to hex code)
               
```
---

## Contact
For questions or feedback, feel free to reach out:
- **GitHub**: [Eileen_Aylin](https://github.com/Eileen-34)
- **E-Mail**: [s_oymak23@stud.hwr-berlin.de](s_oymak23@stud.hwr-berlin.de)

---
