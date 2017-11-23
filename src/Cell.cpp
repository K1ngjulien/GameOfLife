//
// Created by Julian on 14.11.2017.
//

#include "../include/Cell.h"

namespace gcf
{

    Cell::Cell(int x,int y, Config conf,State state)
            :x(x),y(y)
    {
        setState(state);
        rect.setSize(sf::Vector2f(conf.cellX,conf.cellY));
        rect.setPosition(x*conf.cellX,y*conf.cellY);
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(1);
    }

    void Cell::draw(sf::RenderWindow &window)
    {
        window.draw(rect);
    }

    void Cell::clicked()
    {
        if((state == State::Alive )&&(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)))
            setState(State::Dead);

        else if((state == State::Dead)&&(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
            setState(State::Alive);
    }

    void Cell::setState(State state)
    {
        this->state = state;

        if(state == State::Alive)
            rect.setFillColor(sf::Color::White);

        if(state == State::Dead)
            rect.setFillColor(sf::Color::Black);
    }

    State Cell::getState()
    {
        return state;
    }


    void Cell::update(std::vector<std::vector<gcf::Cell>>&grid,gcf::Config &conf)
    {
        int aliveNeighbors = 0;

        //Gets states of neighbors and increases the counter if it is alive

        /* CE = Cell
        UL|MU|UR
        ML|CE|MR
        LL|ML|MR
        */

        if(x>0)
        {
            if(grid[x-1][y].getState() == State::Alive) //ML
                aliveNeighbors++;
            if(y>0)
            {
                if(grid[x-1][y-1].getState() == State::Alive) //LU
                    aliveNeighbors++;
            }
            if(y<conf.cellcountY-1)
            {

                if(grid[x-1][y+1].getState() == State::Alive) //LL
                    aliveNeighbors++;
            }
        }
        if(x<conf.cellcountX-1)
        {
            if(grid[x+1][y].getState() == State::Alive)
                aliveNeighbors++;
            //MR

            if(y<conf.cellcountY-1)
            {
                     //LR
                if(grid[x+1][y+1].getState() == State::Alive)
                    aliveNeighbors++;
            }
            if(y>0)
            {

                    //UR
                if(grid[x+1][y-1].getState() == State::Alive)
                    aliveNeighbors++;
            }
        }
        if(y>0)
        {
             //MU
            if(grid[x][y-1].getState() == State::Alive)
                aliveNeighbors++;
        }
        if(y<conf.cellcountY-1)
        {
            if(grid[x][y+1].getState() == State::Alive)
                aliveNeighbors++;
            //ML
        }


        if(aliveNeighbors < 2)
            setState(State::Dead);

        if(aliveNeighbors > 3)
            setState(State::Dead);

        if(aliveNeighbors == 3)
            setState(State::Alive);
    }


}