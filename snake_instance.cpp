#include "snake_instance.hpp"
#include <string>

snake_instance::
snake_instance(std::string id, int headx, int heady, eDirection direction) {
    name = id;
    headxx = headx;
    headyy = heady;
    prevdir = direction;
    snakelength = 4;
    dir = direction;
    std::vector<snakebody> snakeparts = {snakebody(headxx, headyy)};

}

void snake_instance::
setDirection(eDirection direction) {
    if (direction == UP && prevdir != DOWN) {
        dir = UP;
    }
     if (direction == DOWN && prevdir != UP) {
        dir = DOWN;
    }
     if (direction == LEFT && prevdir != RIGHT) {
        dir = LEFT;
    }
     if (direction == RIGHT && prevdir != LEFT) {
        dir = RIGHT;
    }
}

void snake_instance::
move() {
    if (dir == LEFT) {
        if (headxx > 1) {
            headxx--;
        } else {
            headxx = 24;
        }
    }
    if (dir == UP) {
        if (headyy > 0) {
            headyy--;
        } else {
            headyy = 24;
        }
    }
    if (dir == RIGHT) {
        if (headxx < 24) {
            headxx++;
        } else {
            headxx = 0;
        }
    }
    if (dir == DOWN) {
        if (headyy < 24) {
            headyy++;
        } else {
            headyy = 0;
        }
    }

    if (snakeparts.size() < static_cast<unsigned int>(snakelength)) {
        snakeparts.insert(snakeparts.begin(), snakebody(headxx,headyy));
    } else {
        snakeparts.insert(snakeparts.begin(), snakebody(headxx,headyy));
        snakeparts.pop_back();
    }

    prevdir = dir;
}

void snake_instance::
grow() {
    snakelength++;
}

void snake_instance::
reset(int x,int y, eDirection dir) {
    headxx = x;
    headyy = y;
    prevdir = dir;
    snakelength = 4;
    dir = dir;
    std::vector<snakebody> snakeparts = {snakebody(headxx, headyy)};
}


std::vector<snake_instance::snakebody> snake_instance:: 
get_body() {
    return snakeparts;
}