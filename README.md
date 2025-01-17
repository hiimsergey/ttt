# ttt
![screenshot](https://github.com/user-attachments/assets/8946e665-ab47-4404-9a61-ef5b2b84b370)

A simple Tic-Tac-Toe game written in C using Raylib.

You can customize the board length in cells and the length of the needed streak to win the game.

My second project in C.

## Compile & Run (on Linux at least)

### If you have raylib installed on the system
```sh
git clone https://github.com/hiimsergey/ttt
cd ttt
make dyn
```

### If you want to compile Raylib yourself
```sh
git clone --recursive https://github.com/hiimsergey/ttt
cd ttt/external/raylib
```

Now, compile Raylib with your desired options. See [here](https://github.com/raysan5/raylib/wiki/CMake-Build-Options). An example would be:

```sh
mkdir build
cd build
cmake .. -DPLATFORM=Desktop -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../install
cmake --build . --target install
```

Now, compile ttt:

```sh
cd ../../..
make
#make semistatic # If the binary should only depend on GLFW
```
