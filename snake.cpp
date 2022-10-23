#include"snake.h"
#include<iostream>
#include<graphics.h>
#include<conio.h>
snake::snake(POINT pos, DWORD COLOR, INT InitLength, int Cell, POINT Velocity, DWORD LifeTime) :GameBaseActor()
{
	this->cell = cell;
	POINT start = pos;
	this->pos = pos;
	this->color = color;
	for (int i = 0; i < InitLength; ++i) {
		this->pts.push_back(start);
		start.x += -cell;
	}
	this->currentLength = InitLength;
	this->velocity = Velocity;
	LifeTime = LifeTime;
}
void snake::Tick() {
	GameBaseActor::Tick();
	Dir();
	Advance();
	Draw();
}
void snake::EatFood() {
	POINT pt = { this->pts[currentLength - 1].x * 2 - this->pts[currentLength - 2].x,
	this->pts[currentLength - 1].y * 2 - this->pts[currentLength - 2].y };
	this->pts.push_back(pt);
	currentLength++;
}
void snake::Advance() {
	for (std::vector<POINT>::iterator it = this->pts.end() - 1; it != this->pts.begin(); it++)
	{
		*it = *(it - 1);
	}
	pts[0] = { pts[0].x + velocity.x * cell,pts[0].y + velocity.y * cell };
}
void snake::Draw() {
	setfillcolor(color);
	for (std::vector<POINT>::iterator it = this->pts.begin(); it != pts.end(); it++)
	{
		solidroundrect(it->x - cell / 2, it->y - cell / 2, it->x + cell / 2, it->y + cell / 2, cell / 2, cell / 2);
	}
}
void snake::Dir() {
	if (_kbhit()) {
		switch (_getch()) {
		case 119:
		case 87:
			if (velocity.y != 1)
				velocity = { 0,-1 };
			break;
		case 100:
		case 68:
			if (velocity.x != -1)
				velocity = { 1,0 };
			break;
		case 97:
		case 65:
			if (velocity.x != 1)
				velocity = { 0,-1 };
			break;
		case 115:
		case 83:
			if (velocity.y != 1)
				velocity = { 0,1 };
			break;
		default:break;
		}
	}
}
std::vector<POINT> snake::AllPoint() {
	return pts;
}