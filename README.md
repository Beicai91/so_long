# so_long
A simple 2D game developed in C using the MiniLibX graphical library.<br>
The goal is to navigate a map, collect all items and reach the exit while avoiding enemies.

## Installation
```
git clone
cd so_long
make all
```

## Usage
```
./so_long maps/map_correct.ber
```

## Controls
**W**: Move up <br>
**A**: Move left<br>
**S**: Move down<br>
**D**: Move right<br>
**ESC**: Quit the game

## Dev Features
- Map parsing and validation
- 2D tile-based rendering using MiniLibx
- Collectibles and exit logic
- Basic enemy logic (random movement)
- User keyboard-input handling
- Animated sprite
- Error handling with descriptive messages

## Technical Notes
- Flood Fill is used to do map validation (closed map, accessible collectibles and exit, correct number of game elements)
- Animated sprite uses a linked list of images and a frame-based update system. Every few frames, the animation advances to the next image of the linked list. When the sprite hits an obstacle, the animation loop resets along with the movement direction.  
- Rendering and input handling rely on MiniLibX event hooks (`mlx_hook`, `mlx_loop_hook`, `mlx_loop`)

## Demo

![so_long](https://github.com/user-attachments/assets/39bdd96f-57da-4cf8-87b1-5c4853d9d586)
