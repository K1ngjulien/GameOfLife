//
// Created by Julian on 17.11.2017.
//

#include "../include/Config.h"

namespace gcf
{
    Config::Config(unsigned int winWidth, unsigned int winHeight, unsigned int cellcountX, unsigned int cellcountY)
            : winWidth(winWidth),winHeight(winHeight), cellcountX(cellcountX),cellcountY(cellcountY)
    {
        cellX = floor(winWidth/cellcountX);
        cellY = floor(winHeight/cellcountY);
    }

}