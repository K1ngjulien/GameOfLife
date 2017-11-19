//
// Created by Julian on 14.11.2017.
//

#ifndef GRIDCELLFRAMEWORK_APPLICATION_H
#define GRIDCELLFRAMEWORK_APPLICATION_H

#include "Config.h"
#include "Grid.h"
#include "Cell.h"
#include <SFML/Graphics.hpp>

namespace gcf
{
    class Application
    {
    private:
        Config conf;
        Grid grid;
        sf::RenderWindow window;
        bool mouseIsPressed;

        void handleEvents();
        void draw();
        void cellClicked(sf::Vector2i mousPos);

    public:

        explicit Application(Config config);
        int run();

    };

}

#endif //GRIDCELLFRAMEWORK_APPLICATION_H
