# Paper Plane

Port of [this game](https://ticalc.org/archives/files/fileinfo/341/34139.html) to raylib.

## Gameplay

![plane flying down](./img/gameplay2.png)

Your goal is to fly a paper plane through obstacles and get to the bottom of the map.

Your score is dictated by how far down the level you get.

![plane flying left](./img/gameplay1.png)

## Building

This game can be built using make.

Install:

```bash
# to install make and gcc
sudo apt install build-essential # debian and it's derivatives
sudo pacman -S base-devel # arch and it's derivatives
```

Obtaining Raylib:

Follow the build instruction on the [raylib github](https://github.com/raysan5/raylib/). 

Once you have a compiled copy of the library, you can set RAYLIB when running make to the path of the library (defaults to /usr/local/lib/).

You also need to set RAYLIBINC to the location of raylib.h, (this defaults to /usr/local/include/).

Build:

```bash
make RAYLIB=/path/to/raylib/binary/ RAYLIBINC=/path/to/raylib/header/ -jN # builds the application, N is the number of jobs to use.
make debug RAYLIB=/path/to/raylib/binary/ RAYLIBINC=/path/to/raylib/header/ -jN # build using debug symbols and debug optimizations
```

Run:

```bash
./paper # run the executable you just built
```

## State of the Game

I'm pretty happy with the current state of the game.

There are a few feature that could still be added, e.i.

- Loading and saving maps from files

- Mouse support for menus

- Changable spritesheets for different paper airplanes

But I think these features don't really add to the game all that much.

That being said if you want to add these things feel free to make a PR, and I will take a look at it.

## Credits

This game is a port of [Paper Plane](https://ticalc.org/archives/files/fileinfo/341/34139.html) from the TI-83+/84+ series of graphing calculators, which itself is a port of a minigame from Wario Ware Inc. on the GBA.

The map is a direct conversions from the calculator version.