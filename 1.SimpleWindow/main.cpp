#include <SDL2/SDL.h>
int main(int,char**){
    if(SDL_Init(SDL_INIT_EVERYTHING)){
        SDL_Log("Can not init video,%s",SDL_GetError());
        return 1;
    }

    SDL_Window * win = SDL_CreateWindow("Hello world",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,320,400,SDL_WINDOW_SHOWN);
    if(win == NULL){
        SDL_Log("Can not Create window,%s",SDL_GetError());
        return 1;
    }

    SDL_Delay(3000);
    SDL_DestroyWindow(win);
    return 0;
}