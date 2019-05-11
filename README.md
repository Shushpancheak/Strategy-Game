# Strategy-Game
A Programming Technology Project. Uses SFML. The main aim is to implement different programming patterns.

## How to build
This game uses [SFML](https://www.sfml-dev.org/tutorials/2.5/). So you should download it and somehow link the project to a library. Of course, you also should have cmake of the latest version installed.
### Linux:
```bash
# Main prerequisite is having apt servers with SFML v. 2.5+, or else it won't build.
sudo apt-get install libsfml-dev:2.5

# Get the code and create the makefile 
git clone https://github.com/Shushpancheak/Strategy-Game --recursive
cd Strategy-Game
mkdir build
cd build
cmake ..

# Compile
make

# Run
cd ..
./Strategy-Game
```

### Windows:
Use VS 2017 to open this CMake project. Make sure to set `SFML_DIR` to the built SFML library, where *.cmake files are located in CMakeLists.txt.

## Building docs

By default, CMake will automatically generate docs upon build, but you can turn it off by providing -DBUILD_DOC=OFF option.

You can generate docs by yourself, using

```bash
doxygen
```

Your docs will be generated in docs/ folder.

## Used resources

Tileset: [Sci-fi RTS (120+ sprites)](https://opengameart.org/content/sci-fi-rts-120-sprites) by Kenney.nl
