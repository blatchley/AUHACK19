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
    headx2 = 14;
    heady2 = 14;
    dir2 = LEFT;
    snakelength2 = 4;
    std::vector<snakebody> snakeparts2 = {snakebody(14, 14)};
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
move2() {
    if (dir2 == LEFT) {
        if (headx2 > 1) {
            headx2--;
        } else {
            headx2 = 24;
        }
    }
    if (dir2 == UP) {
        if (heady2 > 0) {
            heady2--;
        } else {
            heady2 = 24;
        }
    }
    if (dir2 == RIGHT) {
        if (headx2 < 24) {
            headx2++;
        } else {
            headx2 = 0;
        }
    }
    if (dir2 == DOWN) {
        if (heady2 < 24) {
            heady2++;
        } else {
            heady2 = 0;
        }
    }
    
    if (headx2 == foodx && heady2 == foody) {
        snakelength2++;
        updatefood();
    }
    if (snakeparts2.size() < snakelength2) {
        snakeparts2.insert(snakeparts2.begin(), snakebody(headx2,heady2));
    } else {
        snakeparts2.insert(snakeparts2.begin(), snakebody(headx2,heady2));
        snakeparts2.pop_back();
    }
    
}

void game::
updatefood() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    foodx = std::rand() % 22 + 1;
    foody = std::rand() % 22 + 1;
    
}

void game::
setDirection(std::string directionfull) {
    std::string direction2 = directionfull.substr(1);
    std::string prefix = directionfull.substr(0,1);
    std::string comparator = "1";
    if (prefix == comparator) {
    if (direction2 == "left" && dir != RIGHT) {
        dir = LEFT;
    }
    if (direction2 == "up" && dir != DOWN) {
        dir = UP;
    }
    if (direction2 == "right" && dir != LEFT) {
        dir = RIGHT;
    }
    if (direction2 == "down" && dir != UP) {
        dir = DOWN;
    }
    } else {
        setDirection2(direction2);
    }
}

void game::
setDirection2(std::string direction) {
    if (direction == "left" && dir2 != RIGHT) {
        dir2 = LEFT;
    }
    if (direction == "up" && dir2 != DOWN) {
        dir2 = UP;
    }
    if (direction == "right" && dir2 != LEFT) {
        dir2 = RIGHT;
    }
    if (direction == "down" && dir2 != UP) {
        dir2 = DOWN;
    }
}

void game::
render(std::shared_ptr<shared_state> const& state){
    int death = 0;
    int death2 = 0;
    std::ostringstream ss;
    ss << std::to_string(foodx)+","+std::to_string(foody);
//    for (auto it = snakeparts.cbegin(); it != snakeparts.cend(); it++) {
    for ( const auto part: snakeparts ) {
        ss << "." << part.strrep();
        if (part.x == headx && part.y == heady) {
            death += 1;
        }
        if (part.x == headx2 && part.y == heady2) {
            death += 1;
        }
    }

    ss << "@";
    for ( const auto part: snakeparts2 ) {
        ss << "." << part.strrep();
        if (part.x == headx2 && part.y == heady2) {
            death2 += 1;
        }
        if (part.x == headx && part.y == heady) {
            death2 += 1;
        }
    }

    //detects overlap and kills
    state->send(ss.str());
    if (death > 1) {
        reset();
    }
    if (death2 > 1) {
        reset();
    }
}
void game::
reset() {
    foodx = 12;
    foody = 12;
    height = 24;
    width = 24;
    headx = 10;
    heady = 10;
    dir = RIGHT;
    gameRunning = true;
    snakelength = 4;
    snakeparts = {snakebody(10, 10)};
    headx2 = 14;
    heady2 = 14;
    dir2 = LEFT;
    snakelength2 = 4;
    snakeparts2 = {snakebody(14, 14)};
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
            move2();
            render(state);
        }
    }
}


    
