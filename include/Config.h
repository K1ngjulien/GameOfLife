//
// Created by Julian on 17.11.2017.
//

#ifndef GRIDCELLFRAMEWORK_CONFIG_H
#define GRIDCELLFRAMEWORK_CONFIG_H

#include <cmath>

namespace gcf
{
    class Config
    {
    public:
        unsigned int winWidth, winHeight;   //Size of the Window in Pixels
        int cellcountX, cellcountY;     //# of Cells in X and Y direction
        int cellX, cellY;       //Size of the Cells in Pixels

        Config(unsigned int winWidth, unsigned int winHeight, unsigned int cellcountX, unsigned int cellcountY);
    };

}

#endif //GRIDCELLFRAMEWORK_CONFIG_H
