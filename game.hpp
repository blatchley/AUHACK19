#include <string>
#include <iostream>
#include <memory>
#include <vector>
// #include "food.hpp"

class shared_state;

class game : public std::enable_shared_from_this<game>
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
        
    // food foodtoken;
    int foodx, foody;
    int height, width;
    int headx, heady;
    int snakelength;
    std::vector <snakebody> snakeparts;
    enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
    bool gameRunning;
    public:
    game();
    void setDirection(std::string direction);
    void updatefood();
    void reset();
    void move();
    void render(std::shared_ptr<shared_state> const& state);
    void gameloop(std::shared_ptr<shared_state> const& state);
    // void prepGameThread(std::shared_ptr<shared_state> const& state);
};
