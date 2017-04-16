#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#define LINE_COLOR BLACK
#define FULL_COLOR GREEN

#include<graphics.h>
#include "snakenode.h"

class SNAKE {
public:
	SNAKE(int x, int y, int r, int length); //��ʼ��

	void right(); //��������
	void left();
	void up();
	void down();
	void rmEnd(); //�Ƴ�β��

	int getR(); //��ȡ�뾶
	int getX(); //��ȡͷ��������
	int getY(); //��ȡͷ��������
	int getScore(); //��ȡ����

	void addApple(); //����ƻ��
	int getAppleX(); //ƻ��X
	int getAppleY(); //ƻ��Y

	bool isInNode(int x, int y);//�ж�ײ������
	

private:
	SnakeNode *sk;

	int r; //�뾶
	int Apple_x;//apple x
	int Apple_y;// apple y
	int temp_x; //�ϴ���ʧ��β��X��Y
	int temp_y; 

	int score = 0; //����
};

#endif //SNAKE_H
