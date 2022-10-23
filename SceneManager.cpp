#include"SceneManager.h"
void SceneManager::RunTick() {
	for (std::vector<GameBaseActor*>::iterator it = GA.begin(); it != GA.end(); it++)//"GameBaseActor为什么是指针？
	{
		if ((*it)->GetState()) {

		}
		else {
			(*it)->Tick();//*it的作用域仅限于GameBaseActor函数中
		}
	}
}
void SceneManager::SpawnActor(GameBaseActor* a) {
	GA.push_back(a);
}