# Asteroids

This game is about a space ship that tries to avoid asteroids by shooting them with bullets. 

## Controls
Movement - `wasd`
Shoot - `space`
Thanks for playing. Enjoy ! 

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
```
