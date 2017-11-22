//
// Created by Julian on 14.11.2017.
//

#include "../include/Application.h"


namespace gcf
{
    Application::Application(Config config)
    :conf(config)
    ,grid(config)
    ,runUpdate(false)
    {
        window.create (sf::VideoMode(config.winWidth, config.winHeight), "Game of Life",sf::Style::Titlebar | sf::Style::Close);
        window.setFramerateLimit(15);
    }

    int Application:: run()
    {
        while (window.isOpen())
        {
            handleInput();
            handleEvents();

            if (runUpdate)
                grid.update();

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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            runUpdate = true;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
        {
            runUpdate = false;
        }

        if((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))||(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)))
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