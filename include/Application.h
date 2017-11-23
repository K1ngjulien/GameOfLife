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
        Config &conf;
        Grid grid;
        sf::RenderWindow window;
        bool runUpdate;

        void handleEvents();
        void handleInput();
        void draw();
        void cellClicked();
        bool mouseInWindow();

    public:

        explicit Application(Config config);
        int run();

    };

}

#endif //GRIDCELLFRAMEWORK_APPLICATION_H
