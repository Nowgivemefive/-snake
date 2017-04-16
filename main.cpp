/*
*	*���� Give_Me_Five
*	*ת����ע������
*/

#include<graphics.h>
#include<conio.h>
#include "snake.h"

#define LIMIT 8
#define SLEEP_TIME 200 //�Ƽ�300ms

void endGame();//��Ϸ����
void game();//������Ϸ
void outScore(SNAKE *temp);

void paintLine() {
	setlinecolor(WHITE);
	line(640, 0, 640, 480);
}

void testGame(SNAKE *temp) {
	TCHAR s[100];
	_stprintf_s(s, _T("%hs : %d,%d"),"apple", temp->getAppleX(),temp->getAppleY());
	outtextxy(650, 20, s);
	_stprintf_s(s, _T("%hs : %d,%d"), "head", temp->getX(), temp->getY());// �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
	outtextxy(650, 50, s);
}

void outScore(SNAKE *temp) {
	TCHAR s[12];
	_stprintf_s(s, _T("%hs%d"), "score: ", temp->getScore());
	outtextxy(520, 430, s);
}

void endGame() {
	TCHAR s[30];
	_stprintf_s(s, _T("%hs"), "game over ! pess R to replay");        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
	outtextxy(260, 230, s);
	char temp = _getch();
	if (temp == 'r') {
		game();
	}
	else {
		closegraph();
	}
	
}

void game() {
	initgraph(640, 480);

	int x = 312; //��ʼX����
	int y = 232; //��ʼY����
	SNAKE *pr = new SNAKE(x, y, 8, 8); //��ʼ�ߣ�X,Y ,�뾶,���ȣ�,��Ҫ�޸İ뾶

	//��������
	char c = 'd';
	char temp = 'd';
	//����,����ƻ��
	bool isEat = true;

	while (true)
	{
		outScore(pr);
		//testGame(pr);//ʹ��ʱ�轫����X����Ϊ740
		//paintMap();

		//���������µ�ƻ��
		if (isEat) {
			pr->addApple();
		}

		//��ȡ��ǰͷ����X��Y
		int tmpx = pr->getX();
		int tmpy = pr->getY();

		if (_kbhit()) {
			// ��ȡ����
			c = _getch();
			if (c == ' ') {
				_getch();
				continue;
			}
			//��ֹ����
			if (temp == 'd'&&c == 'a') {
				continue;
			}
			else if (temp == 'a'&&c == 'd') {
				continue;
			}
			else if (temp == 'w'&&c == 's') {
				continue;
			}
			else if (temp == 's'&&c == 'w') {
				continue;
			}

			switch (c)
			{
			case 'a':
				if (tmpx - LIMIT <= 0) { 
					endGame(); break;
				}else if (pr->isInNode(tmpx - 16, tmpy)) {
					endGame(); break;
				}else if ((tmpy == pr->getAppleY()) && (tmpx - 16 == pr->getAppleX())){
					pr->left(); isEat = true; break;
				}else {
					pr->rmEnd(); pr->left(); isEat = false; break;
				}
			case 'd':
				if (tmpx + LIMIT >= 640) {
					endGame(); break;
				}else if (pr->isInNode(tmpx + 16, tmpy)) {
					endGame();break;
				}else if ((tmpy == pr->getAppleY()) && (tmpx + 16 == pr->getAppleX())) { 
					pr->right(); isEat = true; break; 
				}else {
					pr->rmEnd(); pr->right(); isEat = false; break;
				}
			case 'w':
				if (tmpy - LIMIT <= 0) {
					endGame();break;}
				else if (pr->isInNode(tmpx, tmpy - 16)) {
					endGame();break;
				}else if((tmpx == pr->getAppleX()) && (tmpy - 16 == pr->getAppleY())) { 
					pr->up(); isEat = true; break;
				}else{
					pr->rmEnd(); pr->up();  isEat = false; break;
				}
			case 's':
				if (tmpy + LIMIT >= 480) {
					endGame();break;
				}
				else if (pr->isInNode(tmpx, tmpy + 16)) {
					endGame();break;
				}
				else if((tmpx == pr->getAppleX()) && (tmpy + 16 == pr->getAppleY())) {
					pr->down(); isEat = true; break; 
				}else{
					pr->rmEnd(); pr->down();isEat = false; break;
				}
			}
			temp = c;

		}
		else {
			switch (temp) {
			case 'a':
				if (tmpx - LIMIT <= 0) {
					endGame();break;
				}else if (pr->isInNode(tmpx - 16, tmpy)) {
					endGame();break;
				}else if ((tmpy == pr->getAppleY()) && (tmpx - 16 == pr->getAppleX())) {
					pr->left(); isEat = true; continue;
				}else {
					pr->rmEnd(); pr->left();  isEat = false; break;
				}
			case 'd':
				if (tmpx + LIMIT >= 640) {
					endGame();break;
				}else if (pr->isInNode(tmpx + 16, tmpy)) {
					endGame();break;
				}else if ((tmpy == pr->getAppleY()) && (tmpx + 16 == pr->getAppleX())) {
					pr->right(); isEat = true; continue;
				}
				else {
					pr->rmEnd(); pr->right(); isEat = false; break;
				}
			case 'w':
				if (tmpy - LIMIT <= 0) {
					endGame();break;
				}else if (pr->isInNode(tmpx, tmpy - 16)) {
					endGame();break;
				}else if ((tmpx == pr->getAppleX()) && (tmpy - 16 == pr->getAppleY())) {
					pr->up(); isEat = true; continue;
				}else {
					pr->rmEnd(); pr->up(); isEat = false; break;
				}
			case 's':
				if (tmpy + LIMIT >= 480) {
					endGame();break;
				}else if (pr->isInNode(tmpx, tmpy + 16)) {
					endGame();break;
				}else if ((tmpx == pr->getAppleX()) && (tmpy + 16 == pr->getAppleY())) {
					pr->down(); isEat = true; continue;
				}else {
					pr->rmEnd(); pr->down(); isEat = false; break;
				}
			}

		}
		
		// ��ʱ
		Sleep(SLEEP_TIME);
	}
	

	closegraph();
}



int main(){
	game();

	return 0;
}
