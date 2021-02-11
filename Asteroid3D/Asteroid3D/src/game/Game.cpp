#include "Game.h"

/*
* Constructor
*/

Game::Game() :
	_ticks(0),
	_ship(nullptr)
{}


/*
* Init
*/

bool Game::init() {

	// SDL Video
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0) {
		SDL_Log("Unable to init Video: %s", SDL_GetError());
		return false;
	}

	// SDL Audio
	int sdlAudioResult = SDL_Init(SDL_INIT_AUDIO);
	if (sdlAudioResult != 0) {
		SDL_Log("Unable to init Audio: %s", SDL_GetError());
		return false;
	}

	// SDL Window 
	if (!_info.createWindow()) {
		SDL_Log("Unable to create window: %s", SDL_GetError());
		return false;
	}

	// SDL Image Files
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
		return false;
	}

	// Renderer
	if (!_info.createRenderer()) {
		SDL_Log("Unable to create renderer: %s", SDL_GetError());
		return false;
	}


	// load assets
	load_data();

	_ticks = SDL_GetTicks();

	return true;
}

/*
* Load Texture
*/

SDL_Texture* Game::load_texture(const std::string& filename) {

	SDL_Texture* tex = nullptr;
	auto it = _textures.find(filename);
	if (it != _textures.end()) return it->second;

	// not loaded yet
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (!surface) {
		SDL_Log("Unable to load Texture: %s", SDL_GetError());
		return nullptr;
	}

	tex = SDL_CreateTextureFromSurface(_info.renderer, surface);
	SDL_FreeSurface(surface);
	if (!tex) {
		SDL_Log("Unable to convert Texture: %s", SDL_GetError());
		return nullptr;
	}
	_textures.emplace(filename.c_str(), tex);
	return tex;
}


/*
* Load Data
*/

void Game::load_data() {



}

void Game::unload_data() {

	while (!_actors.empty()) delete _actors.back();
	for (auto i : _textures) SDL_DestroyTexture(i.second);
	_textures.clear();

}



/*
* Actors
*/

void Game::add_actor(Actor* actor) {
	if (status.update_actors)
		_pending_actors.emplace_back(actor);
	else
		_actors.emplace_back(actor);
}

void Game::remove_actor(Actor* actor) {

	auto it = std::find(_pending_actors.begin(), _pending_actors.end(), actor);
	if (it != _pending_actors.end()) {
		std::iter_swap(it, _pending_actors.end() - 1);
		_pending_actors.pop_back();
	}

	it = std::find(_actors.begin(), _actors.end(), actor);
	if (it != _actors.end()) {
		std::iter_swap(it, _actors.end() - 1);
		_actors.pop_back();
	}
}



/*
* Exit
*/
void Game::Shutdown() {

	unload_data();
	IMG_Quit();
	SDL_DestroyRenderer(info.game_renderer);
	SDL_DestroyWindow(info.game_window);
	SDL_Quit();
}

/*
* Gameloop
*/
void Game::GameLoop() {

	while (status.running) {
		get_input();
		update_world();
		manage_output();
	}
}

/*
* Input
*/
void Game::get_input() {


	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			_state.setQuit();
			break;
		}
	}

	// Keyboard State
	const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);

	if (keyboard_state[SDL_SCANCODE_ESCAPE]) _state.setQuit();

	//_ship->process_keyboard(keyboard_state);
}


/*
* Update
*/
void Game::update_world() {

	// capped at 60 FPS
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), _ticks + 16));

	float deltaTime = (SDL_GetTicks() - _ticks) / 1000.0f;
	_ticks = SDL_GetTicks();

	if (deltaTime > 0.05f) deltaTime = 0.05f;


	// update actors

	_state.update = true;
	
	/*
	for (auto actor : _actors)
		actor->update(deltaTime);
	*/

	_state.update = false;

	/*
	// add pending actors
	for (auto pending : _pending_actors)
		_actors.emplace_back(pending);

	_pending_actors.clear();


	// remove dead actors
	std::vector<Actor*> dead_actors;

	for (auto actor : _actors)
		if (actor->get_state() == Actor::State::dead) {
			dead_actors.emplace_back(actor);
		}

	for (auto actor : dead_actors)
		delete actor;
	*/

}


/*
* Output
*/
void Game::manage_output() {

	// render background
	SDL_SetRenderDrawColor(
		_info.renderer,
		0,
		0,
		0,
		255
	);
	// clear back buffer
	SDL_RenderClear(_info.renderer);

	//for (auto sprite : _sprites) sprite->draw(info.game_renderer);

	SDL_RenderPresent(_info.renderer);

}
