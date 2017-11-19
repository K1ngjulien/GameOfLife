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
    }

    void Cell::draw(sf::RenderWindow &window)
    {
        window.draw(rect);
    }

    void Cell::setColor(sf::Color color)
    {
        rect.setFillColor(color);
    }

    void Cell::clicked()
    {
        rect.setFillColor(sf::Color::Red);
    }

    void Cell::setState(State state)
    {
        this->state = state;

        if(state == State::Path)
            rect.setFillColor(sf::Color::White);

        if(state == State::Wall)
            rect.setFillColor(sf::Color::Black);
    }


}