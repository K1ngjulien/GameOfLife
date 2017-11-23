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
    enum State  //State of cell
    {
        Dead,Alive
    };

    class Cell
    {
    private:
        int x;  //Stores x pos
        int y;  //Stores y pos
        sf::RectangleShape rect;    //Rectangle to be drawn
        State state;    //State of the cell

    public:
        Cell(int x,int y, Config conf,State state);
        void update(std::vector<std::vector<gcf::Cell>>&grid,gcf::Config &conf);    //Logic
        void draw(sf::RenderWindow &window);    //Draws rect on window
        void clicked(); //Updates Cell State depending on button Clicked
        void setState(State state);     //Sets State and corresponding color
        State getState();   //Returns State of cell
    };



}
#endif //GRIDCELLFRAMEWORK_CELL_H
