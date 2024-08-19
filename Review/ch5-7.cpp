#include <iostream>

using namespace std;

class MyIntStack {
	int p[10];	//스택저장하는 배열
	int tos;	//스택 꼭대기
public:
	MyIntStack();
	bool push(int n);
	bool pop(int& n);
};
MyIntStack::MyIntStack() {
	tos = -1;

}
bool MyIntStack::push(int n) {
	if (tos >= 9) {
		return false;
	}
	++tos;
	p[tos] = n;
	return true;

}
bool MyIntStack::pop(int& n) {
	if (tos<0) {
		return false;
	}
	n = p[tos];
	tos--;
	return true;

}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i))
			cout << i << ' ';
		else
			cout << endl << i + 1 << " 번째 stack full" << endl;

	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n))
			cout << n << ' ';
		else
			cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}