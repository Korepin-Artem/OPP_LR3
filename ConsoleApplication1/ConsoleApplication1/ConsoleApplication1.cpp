#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

struct comp//��������� ����� 
{
	string val;//�������� ����������
	comp *next;//������ �� ��������� ���������
};

struct Stac
{
	comp* head;//"������" �����
};

void initstac(Stac&a) {//������������� �����
	a.head = NULL;
}

void Add_Stack(Stac &a, string v) {//���������� ������ ���������� � ����
	comp* c = new comp();
	c->val = v;
	c->next = a.head;
	a.head = c;//����� ��������� ���������� "�������" �����, ������ "������" ��������� �� 2 �����
}

void popStac(Stac &a) {//�������� ������ ����������
	comp* c = a.head;
	a.head = a.head->next;
	delete c;
}

void print(Stac a) {//����� ����������� ����� � �������
	while (a.head != 0) {
		cout << a.head->val << " ";
		a.head = a.head->next;
	}
	cout << endl;
}

void findname(Stac a, string b) {//����� ���������� �� ��������
	int x = 1;
	while (a.head != NULL){
		if (a.head->val == b) {
			cout << b << " ��������� �� " << x << " �������." << endl;
		}
		a.head = a.head->next;
		x++;
	}
}

void findnum(Stac a, int i) {//����� ���������� �� ������ � �����
	int x = 1;
	while (x < i) {
		a.head = a.head->next;
		x++;
	}
	cout << "�� " << i << " ������� ���������:" << a.head->val << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Stac c;
	string name;
	initstac(c);
	srand(time(0));
	int n = 1;
	while (n != 0) {
		cout << "�������� ��������:" << endl
			<< "0 - �����" << endl
			<< "1 - �������� ������ �� �����" << endl
			<< "2 - ����� ������ ������ � �����" << endl
			<< "3 - ����� ������������� �������" << endl
			<< "4 - ����� ������ �� ������" << endl
			<< "5 - ����������� ��� ������� �� �����" << endl
			<< "6 - ������ ��� ������� � �����" << endl;
		cin >> n;
		int a;
		switch (n)
		{
		case (1):
			cout << "�������� �������:";
			cin >> name;
			Add_Stack(c, name);
			break;
		case (2):
			popStac(c);
			cout << "������ �����" << endl;
			break;
		case(3):
			cout << "�������� �������:";
			cin >> name;
			findname(c, name);
			break;
		case(4):
			cout << "�����:";
			cin >> a;
			findnum(c, a);
			break;
		case(5):
			print(c);
			break;
		case(6):
			while (c.head != NULL) {
				popStac(c);
			}
			cout << "������� �������" << endl;
			break;
		}
	}
	system("pause");
    return 0;
}

