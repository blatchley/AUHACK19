

# Multiplayer snake game

This is a multiplayer snake game, building on a project started at AUHACK 2019 (april 5th-7th 2019) in collaboration with https://github.com/FrederikBrasch. 

After the hackathon I decided to continue development as project to continue learning c++, javascript, and general server networking.

The backend consists of a c++ boost::beast web socket server running a basic c++ game engine, running in docker, on a google cloud linux vm. The webpage is served with basic html and javascript. 

Web hosting is set up at www.competitivesnek.dk, and the google cloud VM should have enough free credits to continue running until ~late May/early June.

To play the game, click connect, then control the two snakes with arrow keys and wasd.

## Previous experience

The goal of this project was to gain experience with new tools while developing something fun.

No previous experience with c++, and only very minimal c experience from basic handins for computer architecture course @ Aarhus university.
      
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

-Special thanks to the AUHACK wizards for their assistance with various c++ issues.
