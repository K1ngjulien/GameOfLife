//
// Created by Julian on 14.11.2017.
//

#include "../include/Application.h"

#include <iostream>

namespace gcf
{
    Application::Application(Config config)
    :conf(config)
    ,grid(config)
    {
        window.create (sf::VideoMode(config.winWidth, config.winHeight), "GCF",sf::Style::Titlebar | sf::Style::Close);
    }

    int Application:: run()
    {
        while (window.isOpen())
        {
            handleInput();
            handleEvents();

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
               case sf::Event::Closed:
                   window.close();
                   break;
           }


       }
    }

    void Application::handleInput()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
        {
            grid.clear(sf::Color::White);
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if(mouseInWindow())
            {
                cellClicked();
            }
        }
    }


    void Application::draw()
    {
        grid.draw(window);
    }

    bool Application::mouseInWindow()
    {
        return ((sf::Mouse::getPosition(window).x < conf.winWidth) && (sf::Mouse::getPosition(window).y < conf.winHeight));
    }

    void Application::cellClicked()
    {
        grid.cellClicked(sf::Mouse::getPosition(window).x/conf.cellX , sf::Mouse::getPosition(window).y/conf.cellY);
    }

}