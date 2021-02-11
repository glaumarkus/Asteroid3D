#pragma once


#include <unordered_map>
#include <string>

#include "../../Dependencies/SDL/include/SDL.h"
#include "../../Dependencies/SDL/include/SDL_image.h"


#include "state/State.h"
#include "info/info.h"

class Game {
public:

	Game();

	bool init();
	void GameLoop();
	void Shutdown();

	void add_actor(class Actor* actor);
	void remove_actor(class Actor* actor);

	/*
	void add_sprite(class SpriteComponent* sprite);
	void remove_sprite(class SpriteComponent* sprite);
	*/

	SDL_Texture* load_texture(const std::string& filename);

	/*
	Ship* get_ship() { return _ship; }
	*/

	Uint32 get_ticks() const { return _ticks; }


private:

	State _state;
	Info _info;

	Uint32 _ticks;

	std::unordered_map<std::string, SDL_Texture*> _textures;
	std::vector<Actor*> _actors;
	std::vector<Actor*> _pending_actors;

	/*
	class Ship* _ship;
	*/

	void get_input();
	void update_world();
	void manage_output();

	void load_data();
	void unload_data();

};
