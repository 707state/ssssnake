#include<iostream>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include"snake.h"
#include"SceneManager.h"
#include"growfood.h"
int main() {
	initgraph(800, 800);
	SHOWCONSOLE;//���������ʲô��
	setbkcolor(RGB(25, 99, 58));
	cleardevice();
	SceneManager SM;
	snake a({ 55,55 }, RGB(200,200,150));
	SM.SpawnActor(&a);
	DWORD stageTime1 = GetTickCount();
	DWORD stageTime2 = GetTickCount() - 300;
	while (1) {
		if (GetTickCount() - stageTime1 > 100) {
			BeginBatchDraw();
			cleardevice();
			SM.RunTick();
			EndBatchDraw();
			stageTime1 = GetTickCount();//����count��Ŀ
		}
		if (GetTickCount() - stageTime2 > 3000) {
			growfood* f = new growfood(&a, RGB(200, 200, 180));
			SM.SpawnActor(f);//f��a�е�Ԫ����
			stageTime2 = GetTickCount();
		}
	}
	system("pause");
	closegraph();
	return 0;
}