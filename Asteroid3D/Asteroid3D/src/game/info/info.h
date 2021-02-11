#pragma once

#include "../SpaceGame/Dependencies/SDL/include/SDL.h"

#include <array>




class Info {
public:

	SDL_Window* window;
	SDL_Renderer* renderer;

	const std::array<int, 2> resolution = { 1024,768 };
	const std::array<int, 2> position = { 100,20 };

	Info() :
		window(nullptr),
		renderer(nullptr)
	{}

	bool createWindow() {
		window = SDL_CreateWindow(
			"...",
			position[0], position[1],
			resolution[0], resolution[1],
			0
		);

		return true;
	}

	bool createRenderer() {
		renderer = SDL_CreateRenderer(
			window,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		);
		return true;
	}

};