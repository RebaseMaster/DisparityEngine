//
// Created by maxim on 18/11/2017.
//

#include "Core/Renderer.hpp"
#include "Core/Exception.hpp"

// The prototype has to be written this way because of the SDL2main
int main(int argc, char *argv[])
{
    try
    {
        Renderer sdl_context;

        sdl_context.loop();
    }
    catch (Exception const& e)
    {
        e.showError();
        return (1);
    }
    return 0;
}