# SFMLSnake

Snake built in C++ using SFML.

![Imgur Image](https://imgur.com/pmUXumI.jpg)

# Required Dependencies

SFML is required.

Debian/ Ubuntu:

```
sudo apt install libsfml-dev
```
Downloads for other operating systems here.

https://www.sfml-dev.org/download.php

# Compiling with CMAKE.

clone the repo
```
cd sfmlsnake
```
```
cmake .
```
```
make 
```

```
./SFMLSnake
```

# Compiling with g++.
clone the repo
```
cd sfmlsnake
```
```
g++ main.cpp src/*.cpp -o SFMLSnake -lsfml-graphics -lsfml-window -lsfml-system
```

```
./SFMLSnake
```
# Controls

Move up - W or UP

Move down - S or DOWN

Move left - A or LEFT

Move right - D or RIGHT

Exit - ESC

# Command line options

The width, height, cellsize and frame rate are customizable.

Run

```
./SFMLSnake -h
```
For help and further details.




