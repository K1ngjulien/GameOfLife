//
// Created by Julian on 14.11.2017.
//

#ifndef GRIDCELLFRAMEWORK_CELL_H
#define GRIDCELLFRAMEWORK_CELL_H

#include <SFML/Graphics.hpp>
#include "Config.h"

namespace gcf
{

    enum State
    {
        Wall,Path
    };

    class Cell {
    private:
        int x;
        int y;
        sf::RectangleShape rect;
        State state;

    public:
        Cell(int x,int y, Config conf,State state);

        void draw(sf::RenderWindow &window);
        void setColor(sf::Color color);
    };


}
#endif //GRIDCELLFRAMEWORK_CELL_H
