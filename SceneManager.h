#pragma once
#include<vector>
#include"GameBaseActor.h"
using namespace std;
class SceneManager {
public:
	void SpawnActor(GameBaseActor* a);
	void RunTick();
private:
	vector<GameBaseActor*> GA;
};