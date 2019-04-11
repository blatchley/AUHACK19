#include <string>
#include <iostream>
#include <memory>
#include <vector>

class snake_instance 
{

    public:
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
    std::vector <snakebody> snakeparts;
    int headxx, headyy;
    std::string name;
    int snakelength;
    enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
    eDirection prevdir;
    eDirection dir;

    snake_instance(int headx, int heady, eDirection direction);
    void setDirection(eDirection direction);
    void move();
    void grow();
    const std::vector<snakebody> get_body();
    void reset(int x, int y, eDirection dir);
};