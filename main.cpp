#include <iostream>
using namespace std;
#include "System.h"
#include <Windows.h>

int main() {
	//�ܼ� ȭ�� ũ�� ��ȯ
	system("mode con cols=130 lines=40 | title ���� ���α׷�");

	System* system = new System();
	system->running();
	delete system;
}


/*
airport ���� ����
�Ĵ� ��������

�Ĵ� ui ��ġ�� (������ �ð� ���̱� / walk-in ui ����)
������ ���� �ʿ�
���� ���� ����

����ó�� ����
�ڵ� ����ϰ�?
*/