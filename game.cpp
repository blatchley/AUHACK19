#include <ctime>
#include "time.h"
#include "shared_state.hpp"
#include <chrono>
#include <thread>


    // private:
    // int height, width;
    // int headx, heady;
    // enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
    // eDirection dir;
    // bool gameRunning;
    // public:
game::
game() {
    height = 24;
    width = 24;
    headx = 10;
    heady = 10;
    dir = RIGHT;
    gameRunning = true;
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
    std::string str1 = std::to_string(headx);
    std::string str2 = std::to_string(heady);
    std::string str3 = str1 + "," + str2;
    state->send(str3);
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
    double ticktime = 67;
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

// void game::
// prepGameThread(std::shared_ptr<shared_state> const& state) {
//     std::thread gamethread ([this](std::shared_ptr<shared_state> const& state){this->gameloop(state);}, state);
// }

    
