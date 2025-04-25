#include <iostream>
#include<SDL.h>


int main(int  argc, char* argv[])
{
	bool running = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "sdl not initialized" << std::endl;
	}

	
	int prevX = 20; 
	int prevY = 20;
	int x = 440; 
	int y = 440;
	SDL_Window* window = SDL_CreateWindow("window", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	SDL_Surface* image = SDL_LoadBMP("c:/preview.bmp");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

	SDL_Rect rect = { 20,20,202,200 };

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_SetRenderDrawColor(renderer, 233, 244, 244, 222);
	SDL_RenderDrawLine(renderer, prevX, prevY, x, y);
	SDL_RenderPresent(renderer);
	
	if (image == nullptr)
	{
		std::cout << "image is not loaded";
	}
	//SDL_BlitSurface(image, NULL, surface, NULL);

	//SDL_UpdateWindowSurface(window);

	
	//SDL_Surface* surface = SDL_LoadBMP("C:/Users/Saurabh/source/repos/learnsdl2/learnsdl2/assets/sample1.bmp");
//	SDL_Surface* winsurface= SDL_GetWindowSurface(window);
//	SDL_BlitSurface(surface, nullptr, winsurface, nullptr);
//	SDL_UpdateWindowSurface(window);

	//if (surface == nullptr)
	//{
	//	std::cout << "image not loaded";
	//}
	SDL_Event event;
	while (running)
	{

		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
		{
			SDL_Quit();
		}
//		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
//		SDL_RenderClear(renderer);
	//	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		//SDL_RenderDrawLine(renderer, 10, 10, 30, 30);
//		SDL_RenderPresent(renderer);
	}
	std::cout << "h" << std::endl;
	return 0;
}
