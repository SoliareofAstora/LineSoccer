#pragma once
class GameRuler
{
	GameRuler(){}
public:
	bool playing = true;
	static GameRuler &instance(){ static GameRuler game; return game; };
	void StopPlaying() { playing = false; }
	void Start();
	void Play();
	~GameRuler();
};

