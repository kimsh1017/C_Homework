#include <iostream>
using namespace std;
#include "System.h"

int main() {
	System* system = new System();
	system->running();
	delete system;
}

/* �ؾ� �� ��
* 1. ����� �¼��� ���� �����, �¼� 8���� �ٲٱ� - �Ϸ�
* 1-1 0�� ������ ���ư��� ����
* 2. �Ĵ� walk-in ���̺� �����
* 3. ������ �����
* 
* (4) ����� �պ� ����� �ϳ� ����ϸ� �������� ���?
* (5) ����� �պ� ����� ��� ���� �ð� ���� ����ó��
* 
* 4. console �����? include "windows.h" system("cls") -> system ��ü ����
*/
