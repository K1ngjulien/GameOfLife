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
        std::vector<std::vector<gcf::Cell>> grid;   //Stores Cells
        gcf::Config &conf;   //Stores Config
    public:
        explicit Grid(Config &conf);

        gcf::Cell* getCell(int x, int y);

        void draw(sf::RenderWindow &window);    //Draws Cells on window
        void update();  //Updates all Cells
        void clear(State state);    //Sets all of the Cells to a paticular state
        bool cellClicked(unsigned int x, unsigned int y);   //Calls Cellclicked on corresponding cell

    };


}
#endif //GRIDCELLFRAMEWORK_GRID_H
