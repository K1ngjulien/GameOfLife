//
// Created by Julian on 14.11.2017.
//

#include "../include/Grid.h"

#include <iostream>
namespace gcf
{

    Grid::Grid(Config &conf)
    :conf(conf)
    {
        std::vector<Cell> col;
        for(int i = 0; i<conf.cellcountX;i++)
        {
            for (int j = 0; j < conf.cellcountY; j++)
            {
                col.emplace_back(Cell(i,j,conf,State::Dead));   //Generating Cells
            }
            grid.push_back(col);
            col.clear();
        }
    }

    Cell *Grid::getCell(int x, int y)   //Returns Pointer to cell object
    {
        if((x<grid.size())&&(y<grid[0].size()))
            return &grid[x][y];
        else
            return nullptr;
    }


    void Grid::draw(sf::RenderWindow &window)   //Draws each cell on the Screen
    {
        for(auto &coll : grid)
        {
            for(auto &cell : coll)
            {
                cell.draw(window);
            }
        }
    }

    void Grid::clear(State state)   //Clears All Cells
    {
        for(auto &coll : grid)
        {
            for(auto &cell : coll)
            {
                cell.setState(state);
            }
        }
    }

    bool Grid::cellClicked(unsigned int x, unsigned int y)  //Calls Clicked method with for specific cell
    {                                                       //and returns "true" if successful
        if((x < grid.size()) && (y<grid[0].size()))
        {
            grid[x][y].clicked();
            return true;
        }
        else
            return false;
    }

    void Grid::update()
    {
        std::vector<std::vector<gcf::Cell>>cpGrid = grid;   //Copy of grid so you can change the states without
                                                            //modyfiying the data they are determined from
        for(auto &coll : grid)
        {
            for(auto &cell : coll)
            {
                cell.update(cpGrid,conf);
            }
        }
    }



}