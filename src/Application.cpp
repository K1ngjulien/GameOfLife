//
// Created by Julian on 14.11.2017.
//

#include "../include/Application.h"

#include <iostream>

namespace gc
{
    Application::Application(Config config)
    :conf(config)
    ,grid(config)
    ,mouseIsPressed(false)
    {
        window.create (sf::VideoMode(config.winWidth, config.winHeight), "GCF",sf::Style::Titlebar | sf::Style::Close);
    }

    int Application:: run()
    {
        while (window.isOpen())
        {
            handleEvents();

            if(mouseIsPressed)
            {
                cellClicked(sf::Mouse::getPosition(window));
            }

            //Drawing of all Objects
            window.clear(sf::Color::White);
            draw();
            window.display();
        }
        return EXIT_SUCCESS;
    }

    void Application::handleEvents()
    {
        sf::Event e;

       while(window.pollEvent(e))
       {
           switch (e.type)
           {
               case sf::Event::MouseButtonPressed:
               {
                   mouseIsPressed = true;
                   break;
               }
               case sf::Event::MouseButtonReleased:
               {
                   mouseIsPressed = false;
                   break;
               }
               case sf::Event::KeyPressed:
               {
                   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
                   {
                       grid.clear(sf::Color::White);
                   }
                   break;
               }
               case sf::Event::Closed:
                   window.close();
                   break;
           }


       }
    }

    void Application::draw()
    {
        grid.draw(window);
    }

    void Application::cellClicked(sf::Vector2i mousPos)
    {
        Cell * clickedCell = grid.getCell(floor(mousPos.x/conf.cellX),floor(mousPos.y/conf.cellY));

        if(clickedCell != nullptr)
        {
            clickedCell->setColor(sf::Color::Blue);
        }
        else
        {
            std::cout<<"Null";
        }
    }

}