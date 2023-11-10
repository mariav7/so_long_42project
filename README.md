<div align="center">

![Demo:](misc/demo.gif)

---
Coded with 💗 by: [mflores-](https://github.com/mariav7)

</div>

## Project

[**Subject PDF**](misc/en.subject.pdf)

The purpose of so_long is to create your own 2D game in [C](https://en.cppreference.com/w/c/language) using the graphic library [miniLibX](https://github.com/42Paris/minilibx-linux).

The player’s goal is to collect all the collectible items present on the map in order to be able to escape.

---

## Supported feautures

The project's requirements:
* Keys to move the main character:
  * `W` to go up or `⬆️` (bonus mode)
  * `A` to go left or `⬅️` (bonus mode)
  * `S` to go down or `⬇️` (bonus mode)
  * `D` to go right or `➡️` (bonus mode)
* To exit the game:
  * press the `ESC` button
  * click the `X` on the window
* Map files must be (`.ber`) type
* Valid maps must be composed of the following characters only:
  * `0` for an empty space
  * `1` for walls
  * `P` for the player's starting position
  * `C` for collectible items
  * `E` for an exit
* Maps must be closed/surrounded by walls
* The player must collect all the collectible items in order to escape
* Display of the current number of movements in the terminal for normal mode and in the game for bonus mode

---

## Installation

**Clone github repository:**
```bash
git clone git@github.com:mariav7/so_long_42project.git
cd so_long_42project
```

**Compile and run the program in BONUS mode:**
```bash
make bonus && ./bonus_so_long maps/map1.ber
```

OR

**Compile and run the program in NORMAL mode:**
```bash
make && ./so_long maps/map1.ber
```

**To execute the script and test various errors with invalid maps:**
```bash
chmod -xr map_testing.sh && ./map_testing.sh
```

---
