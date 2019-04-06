#include <string>

class game
{
    int height, width;
    int headx, heady;
    enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
    bool gameRunning;

    game();
    void setDirection(std::string direction);
    void reset();
    void move();
    void render();
    void gameloop();
};