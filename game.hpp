#include <string>
#include <iostream>
#include <memory>

class shared_state;

class game : public std::enable_shared_from_this<game>
{
    int height, width;
    int headx, heady;
    enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
    bool gameRunning;
    public:
    game();
    void setDirection(std::string direction);
    void reset();
    void move();
    void render(std::shared_ptr<shared_state> const& state);
    void gameloop(std::shared_ptr<shared_state> const& state);
};