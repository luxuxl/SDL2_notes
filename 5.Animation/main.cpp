#include <SDL2/SDL.h>

#define WIDTH 320
#define HEIGHT 400

void draw(SDL_Surface * surface,int x,int y,Uint32 color){
    SDL_Rect bg = {0,0,WIDTH,HEIGHT};
    SDL_Rect r = {x,y,100,100};
    SDL_FillRect(surface,&bg,0xffffffff);
    SDL_FillRect(surface,&r,color);

}

int main(int,char**){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window * win = SDL_CreateWindow("Hello world",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);


    SDL_Surface * surface = SDL_GetWindowSurface(win);
    // surface 是一张画布，那么也可以单独操作每个像素点



    SDL_Event event;
    int i = 0;

    while (true) {

        draw(surface,i,0,0x0000ff00);
        SDL_UpdateWindowSurface(win);
        i++;

        if (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                break;
            }
        }
    }
    SDL_DestroyWindow(win);
    return 0;
}