#include "Polynomial.h"

using namespace std;

int main() {
	Polynomial P1, P2;
	cout << "ù��° ���׽��� ��� ���� ������ �Է��ϼ���. (������ 0���� �ԷµǸ� ����)" << endl;
	P1.setTerm();
	cout << "�ι�° ���׽��� ��� ���� ������ �Է��ϼ���. (������ 0���� �ԷµǸ� ����)" << endl;
	P2.setTerm();
	cout << "�� ���׽��� ���� " << P1 + P2 << endl;
	cout << "�� ���׽��� ���� " << P1 * P2 << endl;
}
