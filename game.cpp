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
game()
//  :
//     snake1(10, 10, snake_instance::eDirection::RIGHT),
//     snake2(14, 14, snake_instance::eDirection::LEFT) 
    {
    std::cout << "game constructor called";
    snake_list.push_back(snake_instance(10, 10, snake_instance::eDirection::RIGHT));
    snake_list.push_back(snake_instance(14, 14, snake_instance::eDirection::LEFT));
    foodx = 12;
    foody = 12;
    height = 24;
    width = 24;
    dir = snake_instance::eDirection::RIGHT;
    gameRunning = true;
//     headx = 10;
//     heady = 10;
//     prevdir = RIGHT;
//     dir = RIGHT;
//     snakelength = 4;
//     std::vector<snakebody> snakeparts = {snakebody(10, 10)};
//     headx2 = 14;
//     heady2 = 14;
//     dir2 = LEFT;
//     prevdir2 = LEFT;
//     snakelength2 = 4;
//     std::vector<snakebody> snakeparts2 = {snakebody(14, 14)};
// //   gameloop();

}

void game::
moveall() {

    for ( auto &part: snake_list) {
        part.move();
        if (part.headxx == foodx && part.headyy == foody) {
        part.grow();
        updatefood();
    }
    }
    // snake1.move();
    // snake2.move();
    // if (snake1.headxx == foodx && snake1.headyy == foody) {
    //     snake1.grow();
    //     updatefood();
    // }
    // if (snake2.headxx == foodx && snake2.headyy == foody) {
    //     snake2.grow();
    //     updatefood();
    // }
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
    if (direction2 == "left") {dir = snake_instance::eDirection::LEFT;}
    if (direction2 == "right") {dir = snake_instance::eDirection::RIGHT;}
    if (direction2 == "up") {dir = snake_instance::eDirection::UP;}
    if (direction2 == "down") {dir = snake_instance::eDirection::DOWN;}
    
    if (prefix == comparator) {
        snake_list[0].setDirection(dir);
    } else {
        snake_list[1].setDirection(dir);
    }
}

void game::
render(std::shared_ptr<shared_state> const& state){
    int death = 0;
    // int death2 = 0;
    std::ostringstream ss;
    ss << std::to_string(foodx)+","+std::to_string(foody);
//    for (auto it = snakeparts.cbegin(); it != snakeparts.cend(); it++) {
    for ( snake_instance snake: snake_list) {
        std::cout << "iterating through list of snakes\n";
        std::cout << snake_list.size() << "\n";
        std::cout << snake.get_body().size() << "\n";
       

    for ( const snake_instance::snakebody part: snake.get_body()) {
        std::cout << "iterating through snake body parts\n";
        ss << "." << part.strrep();
        // if (part.x == snake.headxx && part.y == snake.headyy) {
            // death += 1;
        // }
    }

    ss << "@";
    }
    //detects overlap and kills
    std::string message = ss.str();
    message.pop_back();
    state->send(message);
    if (death > 2) {
        reset();
    }
    // if (death2 > 1) {
    //     reset();
    // }
}
void game::
reset() {
    std::cout << "game reset";
    std::this_thread::sleep_for(std::chrono::milliseconds(330));
    foodx = 12;
    foody = 12;
    height = 24;
    width = 24;
    snake_list[0].reset(10,10,snake_instance::eDirection::RIGHT);
    snake_list[1].reset(14,14,snake_instance::eDirection::LEFT);
    gameRunning = true;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
             
}
void game::
gameloop(std::shared_ptr<shared_state> const& state) {
    
    auto start = std::chrono::high_resolution_clock::now();
    double ticktime = 134;
    while (gameRunning) {
        auto now = std::chrono::high_resolution_clock::now();
        auto seconds_since_start = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
        if (seconds_since_start < ticktime) {
             if ((ticktime - seconds_since_start) > 40) {
             std::this_thread::sleep_for(std::chrono::milliseconds(30));
             }
        } else {
            start = std::chrono::high_resolution_clock::now();
            moveall();
            render(state);
         }
    }
}


    
