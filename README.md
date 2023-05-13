# Fall22_OOP_FlappyFairy
Inspired by the Flappy Bird Game this is our Final Project for Object Oriented Programming course offered by Habib University in Fall of 22. It makes use of SDL libraries for the GUI and tests basic OOP concepts like abstraction, overloading etc.

Group Members: Simal Anjum, Muhammad Talha Salani

How to Compile:
**THE FILES ABOVE ARE MODIFIED TO RUN ON MAC. YOU MAY NEED TO MAKE THE FOLLOWING CHANGES**

Windows:
Open this folder in VSCode, make the following changes in the files and then in the terminal copy the command for compiling and running the game.

Change #include<SDL2.h> to #include<SDL.h>
Change  #include<SDL2/SDL_image.h> to #include<SDL_image.h>
Change  #include<SDL2/SDL_mixer.h> to #include<SDL_mixer.h>

Compiling:
g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

Running the game:
.\a.exe

Mac:
Open this folder in VSCode and then in the terminal copy the commands for compiling and running the game.

Compiling:
g++ *.cpp -std=c++11 -lSDL2 -lSDL2_image -lSDL2_mixer

Running the game:
./a.out

