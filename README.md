# Asteroids

This is the Asteroids game but with modifications that make it more entertaining. This was built with the SDL Library.

## Controls
Movement - `wasd`

Shoot - `space`

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
