#include "../include/Application.h"
int main()
{
    gc::Config conf(1000,1000,100,100);

    gc::Application app(conf);

    return app.run();
}