# Asteroids

This game is about a space ship that tries to avoid asteroids by shooting them with bullets. 

## How to install

On ubuntu/debian,

First update you package manager
```
sudo apt-get update
```

Then you need to install make:
```
sudo apt-get install make
```

Now you need to install then SDL Libraries that we used:
```
sudo apt-get install libsdl2-dev
```
and 
```
sudo apt-get install libsdl2-image-dev
```
Now navigate to to the source/ file inside of asteroids/ that you just cloned
Then type:
```
make
```
or
```
make -f Makefile
```
After the process is complete, source/ will have a game exec file. To play it type:
```
./game
``` ## How to play
The game is simple, avoid asteroids by moving around usinfg ASDE keyboard keys. In case you want shoot the asteroids use the space button on the keyboard. You can hold on to the space button while moving around and that will help you shoot a lot of bullets while moving around at the same time. Furthermore, if you want to change the direction of the bullets just use your mouse cursor while shooting the bullets.
Thanks for playing. Enjoy ! 
