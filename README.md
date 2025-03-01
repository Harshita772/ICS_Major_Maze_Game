
# Enigma Escape - Maze Game

Enigma Escape is an interactive maze game developed in the C programming language. This game generates dynamic mazes with varying difficulty levels, challenges players to navigate through the maze, collect food items, and reach the exit within a specified time limit. The game features colorful ASCII-based graphics and user-friendly keyboard controls.

## Objectives

The primary objectives of Enigma Escape are:

Develop a dynamic maze game using C programming.

Implement player movement, scoring mechanisms, and time management.

Provide a visually appealing interface using ASCII graphics.

## Features

Dynamic Maze Generation with Recursive Backtracking algorithm.

Three Difficulty Levels: Easy, Medium, and Hard.

Keyboard-based Player Controls.

Time Limit for Each Level.

Food Collection Mechanism to Increase Score.

Maze Solution Display using Depth First Search (DFS).

Colorful ASCII Graphics.

## How to Play

Choose the difficulty level:

1: Easy (60 seconds)

2: Medium (120 seconds)

3: Hard (180 seconds)

Use the following keys for navigation:

W: Move Up

S: Move Down

A: Move Left

D: Move Right

E: Grab Food to increase score

Q: Quit the game and show the solution

Complete the maze by reaching the exit E within the time limit.

Collect food items F to increase your score.

If the time limit expires, the game ends.

## Installation

1. Clone the repository or download the source code.
#### git clone: https://github.com/Harshita772/ICS_Major_Maze_Game.git
2. cd ICS_Major_Maze_Game
3. Compile the code using any C compiler (GCC recommended): 
#### gcc enigma_escape.c -o enigma_escape
4. Run the game:
#### ./enigma_escape

## Code Structure

Maze Generation: Recursive Backtracking Algorithm.

Player Movement: Keyboard-based navigation.

Food Mechanism: Random food item placement.

Scoring System: Points awarded for each collected food item.

Time Management: Timer for each difficulty level.

Solution Display: DFS Algorithm for maze solution.

## Future Improvements

Advanced graphical user interface.

Multiplayer Mode.

Power-ups and Obstacles.

More Maze Design Variations.

Sound Effects and Animations.
