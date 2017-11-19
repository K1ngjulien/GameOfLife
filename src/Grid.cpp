//
// Created by Julian on 14.11.2017.
//

#include "../include/Grid.h"

#include <iostream>
namespace gcf
{

    Grid::Grid(Config conf)
    {
        std::vector<Cell> col;
        for(int i = 0; i<conf.cellcountX;i++)
        {
            for (int j = 0; j < conf.cellcountY; j++)
            {
                col.emplace_back(Cell(i,j,conf,State::Path));
                //std::cout<<"Generating:"<<i<<","<<j<<std::endl;
            }
            grid.push_back(col);
            col.clear();
        }
    }

    Cell *Grid::getCell(int x, int y)
    {
        if((x<grid.size())&&(y<grid[0].size()))
            return &grid[x][y];
        else
            return nullptr;
    }

    void Grid::draw(sf::RenderWindow &window)
    {
        for(auto &coll : grid)
        {
            for(auto &cell : coll)
            {
                cell.draw(window);
            }
        }
    }

    void Grid::clear(sf::Color color)
    {
        for(auto &coll : grid)
        {
            for(auto &cell : coll)
            {
                cell.setColor(color);
            }
        }
    }

}