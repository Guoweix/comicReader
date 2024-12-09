#include <SDL.h>
#include <iostream>

using  namespace std; 

unsigned int width=800;
unsigned int height=600;


int main(int argc, char* argv[]) {
    // 初始化 SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout<<"SDL could not initialize! SDL_Error: "<<SDL_GetError()<<endl;
        // printf("SDL could not initialize! SDL_Error: %s\n", ());
        return 1;
    }

    // 创建窗口
    SDL_Window* window = SDL_CreateWindow("SDL Example",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

    if (window == NULL) {
        // printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        cout<<"Window could not be created! SDL_Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return 1;
    }

    // 创建渲染器
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        // printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        cout<<"Renderer could not be created! SDL_Error:  "<<SDL_GetError()<<endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // 主循环
    int running = 1;
    SDL_Event event;
    while (running) {
        // 事件处理
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // 清屏
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // 白色
        SDL_RenderClear(renderer);

        // 绘制矩形
        SDL_Rect rect = { 100, 100, 200, 150 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 红色
        SDL_RenderFillRect(renderer, &rect);

        // 显示渲染内容
        SDL_RenderPresent(renderer);
    }

    // 清理
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
