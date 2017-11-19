//
// Created by Julian on 14.11.2017.
//

#ifndef GRIDCELLFRAMEWORK_GRID_H
#define GRIDCELLFRAMEWORK_GRID_H


#include "Config.h"
#include "Cell.h"
#include <vector>

namespace gcf
{
    class Grid
    {
    private:
        std::vector<std::vector<gcf::Cell>> grid;

    public:
        explicit Grid(Config conf);

        gcf::Cell* getCell(int x, int y);

        void draw(sf::RenderWindow &window);
        void clear(sf::Color color);
        bool cellClicked(unsigned int x, unsigned int y);

    };


}
#endif //GRIDCELLFRAMEWORK_GRID_H
