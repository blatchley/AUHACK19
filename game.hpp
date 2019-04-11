#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "snake_instance.hpp"
// #include "food.hpp"

class shared_state;

class game : public std::enable_shared_from_this<game>
{     
    // food foodtoken;
    // snake_instance snake1;
    // snake_instance snake2;
    std::vector <snake_instance> snake_list;
    int foodx, foody;
    int height, width;
    bool gameRunning;
    snake_instance::eDirection dir;
    public:
    game();
    void setDirection(std::string directionfull);
    void updatefood();
    void reset();
    void moveall();
    void render(std::shared_ptr<shared_state> const& state);
    void gameloop(std::shared_ptr<shared_state> const& state);
    // void prepGameThread(std::shared_ptr<shared_state> const& state);
};
