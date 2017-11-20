//
// Created by maxim on 20/11/2017.
//

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "SDL2/include/SDL.h"

class Renderer
{
public:
    //CTOR
    Renderer();

    //DTOR
    ~Renderer();

    //MEMBER FUNC
    void loop(void);
private:
    SDL_Window  *mp_window;

};

#endif //!RENDERER_HPP_
