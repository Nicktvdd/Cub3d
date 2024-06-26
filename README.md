# Cub3D

Cub3D is a 3D graphics project that utilizes the raycasting technique to create a simple yet immersive first-person perspective game. This project is part of the curriculum at 42 School.

![cub3d](https://github.com/Nicktvdd/Cub3d/assets/5775657/8e83589c-4af2-4ef9-b54f-432d0cb2708b)


## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Map Format](#map-format)
- [Acknowledgments](#acknowledgments)

## Introduction

Cub3D is inspired by the classic game Wolfenstein 3D and serves as an introduction to the world of computer graphics. It involves the creation of a game engine that renders a 3D maze using the raycasting technique.

## Features

- First-person perspective rendering
- Textured walls and sprites
- Floor and ceiling colors
- Player movement and rotation

## Getting Started

### Prerequisites

- macOS (only tested on macOS)
- Make sure you have `gcc` and `make` installed

### Installation

1. Clone the repository
   ```bash
   git clone https://github.com/your-username/Cub3D.git
   cd Cub3D
### Build the Project
1. Clone the repository
   ```bash
   git clone https://github.com/your-username/Cub3D.git
   cd Cub3D
   make

### Usage
Run the executable with a provided map file:
  ```bash
  ./Cub3D maps/map.cub
```

### Controls
- **W:** Move forward
- **A:** Strafe left
- **S:** Move backward
- **D:** Strafe right
- **→:** Rotate right
- **←:** Rotate left
- **ESC:** Exit the game

### Map Format
The map file specifies the layout of the 3D maze and includes information about textures, colors, and the starting position of the player.

### Acknowledgments
This project was completed as part of the curriculum at 42 School.
Thanks to the creators of Wolfenstein 3D for the inspiration.
A massive thank you to [juan](https://github.com/jestebanpelaez18) for being a great teammate and hard worker.
