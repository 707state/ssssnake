#pragma once
#include<windows.h>
#include<vector>
#include"GameBaseActor.h"
class snake :public GameBaseActor {
public:
	snake(POINT pos, DWORD color, int InitLength = 3, int Cell = 10, POINT Velocity = { 1,0 }, DWORD LifeTime = 0);
	void Tick();
	void EatFood();
	void Advance();
	void Draw();
	void Dir();
	std::vector<POINT> AllPoint();
private:
	std::vector<POINT> pts;
	int currentLength;
	POINT velocity;
	int score = 0;
};