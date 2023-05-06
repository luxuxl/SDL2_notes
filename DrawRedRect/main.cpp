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

    SDL_Rect r1 = {0,0,100,100};
    SDL_FillRects(surface,&r1,1,0xffff0000); // ARGB

    SDL_UpdateWindowSurface(win);

    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event)) {
            printf("%x\n",event.type);
            if(event.type == SDL_QUIT){
                break;
            }
        }
    }
    SDL_DestroyWindow(win);
    return 0;
}