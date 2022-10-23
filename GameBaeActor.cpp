#include "GameBaseActor.h"
GameBaseActor::GameBaseActor() {
	startTime = GetTickCount();
}
void GameBaseActor::Tick() {//声明Tick的作用域在GameBaseActor中
	if (GetTickCount() - startTime > lifeTime && lifeTime > 0)
		Death();
}
void GameBaseActor::Death() {
	die = true;
}
bool GameBaseActor::GetState() {
	return die;
}