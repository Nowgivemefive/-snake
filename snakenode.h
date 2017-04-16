/*
*	˫����������������
*/
#pragma once
#ifndef NODE_H
#define NODE_H


struct Node {
	int x;
	int y;
	struct Node *next;
	struct Node *prev;
};


class SnakeNode {
public:
	SnakeNode();
	void addNode(int x, int y); //β�����ӽ��
	void addHeadNode(int x, int y); //��ͷ�������ӽ��
	void rmNode(); //ɾ��β�����
	Node* getEnd(); //��ȡβ�����
	void showAll(); //������
	Node* getHead(); //��ȡͷ�����
	bool inNode(int x, int y); //ƻ�������Ƿ������� 
	bool headInNode(int x, int y); //ͷ��ײ������
private:
	Node *head, *end;
};



#endif // !NODE_H
