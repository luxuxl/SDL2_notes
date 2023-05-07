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
    // surface 即是一张画布，可以用
    // printf("%d %d",surface->w,surface->h);
    // 来显示画布大小，画布 surface 是根据 window 的尺寸生成的，所以要用 GetWindowSurface() 来创建

    SDL_Rect r1 = {100,0,100,100};
    // rect 可以理解为一种绘图元素，各种绘图元素需要用 Fill 绘制在 surface 上
    SDL_FillRects(surface,&r1,1,0xffff0000); // ARGB

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