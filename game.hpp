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
    int headx, heady, headx2, heady2;
    int snakelength, snakelength2;
    std::vector <snakebody> snakeparts;
    std::vector <snakebody> snakeparts2;
    enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
    eDirection prevdir;
    eDirection dir;
    eDirection prevdir2;
    eDirection dir2;
    bool gameRunning;
    public:
    game();
    void setDirection(std::string directionfull);
    void setDirection2(std::string direction);
    void updatefood();
    void reset();
    void move();
    void move2();
    void render(std::shared_ptr<shared_state> const& state);
    void gameloop(std::shared_ptr<shared_state> const& state);
    // void prepGameThread(std::shared_ptr<shared_state> const& state);
};
