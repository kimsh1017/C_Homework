#include <iostream>
using namespace std;
#include "System.h"

int main() {
	System* system = new System();
	system->running();
	delete system;
}

/* �ؾ� �� ��
* 0. ������ �ð� �ߺ� ����ó�� - ��
* 1. UI ���� , 0�� ������ ���ư��� , ������� include ���� - ����
* 2. �Ĵ� walk in - ��
* 3. console ����� - ����
* 4. ���� ����?
* 5. admin?
*/
