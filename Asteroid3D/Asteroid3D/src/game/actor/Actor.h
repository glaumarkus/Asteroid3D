#pragma once

#include <vector>

#include "../math/math.h"
#include "../math/Vec2.h"
#include "../math/Vec4.h"
#include "../math/Matrix.h"


class Actor {
public:

	enum class State {
		active,
		paused,
		dead
	};

	Actor(class Game* game);
	virtual ~Actor();

	virtual void update(const float& deltaTime);
	void update_components(const float& deltaTime);
	virtual void update_actor(const float& deltaTime);

	void add_component(class Component* component);
	void remove_component(class Component* component);

	Vec2 get_position() { return _position; }
	void set_position(const Vec2& position) { _position = position; }

	State get_state() { return _state; }
	void set_state(State state) { _state = state; }

	float get_scale() { return _scale; }
	void set_scale(const float& scale) { _scale = scale; }

	float get_rotation() { return _rotation; }
	void set_rotation(const float& rotation) { _rotation = rotation; }

	Game* get_game() { return _game; }

private:

	State _state;
	Vec2 _position;
	float _scale;
	float _rotation;
	std::vector<class Component*> _components;
	class Game* _game;

};