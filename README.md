# Strategy-Game
A Programming Technology Project. Uses SFML. The main aim is to implement different programming patterns.

## How to build
This game uses [SFML](https://www.sfml-dev.org/tutorials/2.5/). So you should download it and somehow link the project to a library. Of course, you also should have cmake of the latest version installed.
### Linux:
```bash
sudo apt-get install build-essential
sudo apt-get install git
sudo apt-get install cmake

#get the code and create the makefile 
git clone https://github.com/Shushpancheak/Strategy-Game --recursive
cd Strategy-Game
mkdir build
cd build
cmake ..

#compile
make

#run
cd ..
./Strategy-Game
```

### Windows:
Use VS 2017 to open this CMake project. Make sure to set `SFML_DIR` to the built SFML library, where *.cmake files located at in CMakeLists.txt.