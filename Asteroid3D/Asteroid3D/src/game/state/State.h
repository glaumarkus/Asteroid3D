#pragma once

class State {
public:

	enum GameState {
		initialize,
		running,
		paused,
		quit
	};

	State();
	~State(){}
	
	bool isRunning();

	void setInitialize();
	void setPause();
	void setRunning();
	void setQuit();

	bool updateActors() { !isRunning(); }

	bool update;

private:



	GameState _state;

};