#include "Polynomial.h"

using namespace std;

int main() {
	Polynomial P1, P2;
	cout << "첫번째 다항식을 계수 지수 쌍으로 입력하세요. (지수가 0으로 입력되면 종료)" << endl;
	P1.setTerm();
	cout << "두번째 다항식을 계수 지수 쌍으로 입력하세요. (지수가 0으로 입력되면 종료)" << endl;
	P2.setTerm();
	cout << "두 다항식의 합은 " << P1 + P2 << endl;
	cout << "두 다항식의 곱은 " << P1 * P2 << endl;
}
