#include "State.h"

State::State() :
	_state(GameState::initialize)
{}

bool State::isRunning() {
	return _state == GameState::running ? true : false;
}

void State::setInitialize() {
	_state = GameState::initialize;
}

void State::setPause() {
	_state = GameState::paused;
}

void State::setRunning() {
	_state = GameState::running;
}

void State::setQuit() {
	_state = GameState::quit;
}