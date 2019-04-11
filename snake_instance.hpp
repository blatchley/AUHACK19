#include <string>
#include <iostream>
#include <memory>
#include <vector>
// #include "food.hpp"


class game 
{
    class snakebody 
    {
        public:
        int x, y;
        snakebody(int x_, int y_) {
            x = x_;
            y = y_;
        }
        std::string strrep() const {
            return std::to_string(x)+","+std::to_string(y);
        }
    };

    int headx, heady;
    std::string id;
    std::vector <snakebody> snakeparts;
    enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
    eDirection prevdir;
    eDirection dir;
    void setDirection(std::string direction)
    void move();
}