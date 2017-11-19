#include "../include/Application.h"
int main()
{
    gcf::Config conf(1000,1000,100,100);

    gcf::Application app(conf);

    return app.run();
}