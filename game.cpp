#include <ctime>
#include "time.h"
#include "shared_state.hpp"
#include <chrono>
#include <thread>
#include <sstream>
#include <iostream>


    // private:
    // int height, width;
    // int headx, heady;
    // enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
    // eDirection dir;
    // bool gameRunning;
    // public:
game::
game() {
    foodx = 12;
    foody = 12;
    height = 24;
    width = 24;
    headx = 10;
    heady = 10;
    dir = RIGHT;
    gameRunning = true;
    snakelength = 4;
    std::vector<snakebody> snakeparts = {snakebody(10, 10)};
//   gameloop();

}
void game::
move() {
    if (dir == LEFT) {
        if (headx > 1) {
            headx--;
        } else {
            headx = 24;
        }
    }
    if (dir == UP) {
        if (heady > 0) {
            heady--;
        } else {
            heady = 24;
        }
    }
    if (dir == RIGHT) {
        if (headx < 24) {
            headx++;
        } else {
            headx = 0;
        }
    }
    if (dir == DOWN) {
        if (heady < 24) {
            heady++;
        } else {
            heady = 0;
        }
    }
    if (headx == foodx && heady == foody) {
        snakelength++;
        updatefood();
    }
    if (snakeparts.size() < snakelength) {
        snakeparts.insert(snakeparts.begin(), snakebody(headx,heady));
    } else {
        snakeparts.insert(snakeparts.begin(), snakebody(headx,heady));
        snakeparts.pop_back();
    }
}

void game::
updatefood() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    foodx = std::rand() % 24;
    foody = std::rand() % 24;
    
}

void game::
setDirection(std::string direction) {
    if (direction == "left") {
        dir = LEFT;
    }
    if (direction == "up") {
        dir = UP;
    }
    if (direction == "right") {
        dir = RIGHT;
    }
    if (direction == "down") {
        dir = DOWN;
    }
}
void game::
render(std::shared_ptr<shared_state> const& state){
    std::ostringstream ss;
    ss << std::to_string(foodx)+","+std::to_string(foody);
//    for (auto it = snakeparts.cbegin(); it != snakeparts.cend(); it++) {
    for ( const auto part: snakeparts ) {
        ss << "." << part.strrep();
    }

    // std::string str1 = std::to_string(headx);
    // std::string str2 = std::to_string(heady);
    // std::string str3 = str1 + "," + str2;
    state->send(ss.str());
}
void game::
reset() {
    headx = 10;
    heady = 10;
    dir = RIGHT;
}
void game::
gameloop(std::shared_ptr<shared_state> const& state) {
    
    auto start = std::chrono::system_clock::now();
    double ticktime = 134;
    while (gameRunning) {
        auto now = std::chrono::system_clock::now();
        auto seconds_since_start = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
        if (seconds_since_start > ticktime) {
            start = std::chrono::system_clock::now();
            move();
            render(state);
        }
    }
}


    
