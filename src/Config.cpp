//
// Created by Julian on 17.11.2017.
//

#include "../include/Config.h"

namespace gc
{
    Config::Config(int winWidth, int winHeight, int cellcountX, int cellcountY)
            : winWidth(winWidth),winHeight(winHeight), cellcountX(cellcountX),cellcountY(cellcountY)
    {
        cellX = floor(winWidth/cellcountX);
        cellY = floor(winHeight/cellcountY);
    }

}