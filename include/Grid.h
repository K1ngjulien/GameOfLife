//
// Created by Julian on 14.11.2017.
//

#ifndef GRIDCELLFRAMEWORK_GRID_H
#define GRIDCELLFRAMEWORK_GRID_H


#include "Config.h"
#include "Cell.h"
#include <vector>

namespace gc
{

    class Grid
    {
    private:
        std::vector<std::vector<gc::Cell>> grid;

    public:
        Grid(Config conf);

        gc::Cell* getCell(int x, int y);

        void draw(sf::RenderWindow &window);
        void clear(sf::Color color);

    };


}
#endif //GRIDCELLFRAMEWORK_GRID_H
