

# AUHACK multiplayer snake game

This is a multiplayer snake game made for AUHACK 2019.

Made by Frederik Brasch and Adam Blatchley Hansen (https://github.com/killerdogice)

Game consists of a c++ boost::beast web socket server running a basic c++ game engine, running in docker, on a google cloud linux vm. The webpage is served with basic html and javascript. 

Web hosting is set up at www.competitivesnek.dk, however the hosting has not yet gone through full dns registration, and may not be responsive before the deadline. 

If the website is not active, the google server can be accessed at http://35.243.131.250/, and should remain stable for at least a month or so.

To play the game, click connect, then control the two snakes with arrow keys and wasd.

## Previous experience

The goal of this project was to gain experience with new tools while developing something fun.

Adam: No previous experience with c++, and only very minimal c experience from basic handins for computer architecture course @ Aarhus university.
      No previous javascript experience.
      No previous docker experience.
      No previous server setup experience.

## Docker Container
To run this server in a Docker container, simply pull the repo, and enter the following commands:
```
docker build -t cppcon2018-example .
docker run -d -p 80:80 cppcon2018-example
```
After that, you may observe the example at `localhost:80`.
