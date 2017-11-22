//
// Created by Julian on 14.11.2017.
//

#ifndef GRIDCELLFRAMEWORK_CELL_H
#define GRIDCELLFRAMEWORK_CELL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.h"

namespace gcf
{
    enum State
    {
        Dead,Alive
    };

    class Cell {
    private:
        int x;
        int y;
        sf::RectangleShape rect;
        State state;

    public:
        Cell(int x,int y, Config conf,State state);
        void update(std::vector<std::vector<gcf::Cell>>&grid,gcf::Config &conf);
        void draw(sf::RenderWindow &window);
        void setColor(sf::Color color);
        void clicked();
        void setState(State state);
        State getState();
    };



}
#endif //GRIDCELLFRAMEWORK_CELL_H
