//
// Created by maxim on 20/11/2017.
//

#include "Core/Renderer.hpp"
#include "Core/Exception.hpp"
#include <iostream>

Renderer::Renderer()
{
    SDL_Init(SDL_INIT_VIDEO);

    mp_window = SDL_CreateWindow("DisparityEngine",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                640,
                                480,
                                SDL_WINDOW_OPENGL);
    if (mp_window == NULL)
        throw Exception("Renderer::Renderer", SDL_GetError());
}

Renderer::~Renderer()
{
    SDL_DestroyWindow(mp_window);
    SDL_Quit();
}

void    Renderer::loop(void)
{
    SDL_Event event;

    while (true)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    return;
                case SDL_KEYDOWN:
                    switch( event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            return;
                    }
                default:
                    break;
            }
        }
    }
}