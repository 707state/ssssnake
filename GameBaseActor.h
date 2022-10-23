#pragma once
#include<windows.h>
class GameBaseActor {
public:
	GameBaseActor();
	virtual void Tick();
	virtual void Death();
	bool GetState();
protected:
	DWORD startTime;
	DWORD lifeTime;
	DWORD color;
	DWORD pos;
	int cell;
	bool die = false;
};