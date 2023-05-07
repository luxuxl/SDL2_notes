#include <SDL2/SDL.h>

#define WIDTH 320
#define HEIGHT 400
int main(int,char**){
    if(SDL_Init(SDL_INIT_EVERYTHING)){
        SDL_Log("Can not init video,%s",SDL_GetError());
        return 1;
    }
    SDL_Window * win = SDL_CreateWindow("Hello world",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    if(win == NULL){
        SDL_Log("Can not Create window,%s",SDL_GetError());
        return 1;
    }

    SDL_Surface * surface = SDL_GetWindowSurface(win);
    // surface 是一张画布，那么也可以单独操作每个像素点

    ((Uint32*)surface->pixels)[WIDTH*HEIGHT/2+WIDTH/2] = 0xff00ff00;
    // 访问像素点

    SDL_UpdateWindowSurface(win);

    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                break;
            }
        }
    }
    SDL_DestroyWindow(win);
    return 0;
}