#include <iostream>

using namespace std;

class MyIntStack {
	int* p;		//스택저장하는 배열
	int size;	//스택의 최대크기
	int tos;	//스택내부 탑 인덱스
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);	//복사 생성자
	~MyIntStack();
	bool push(int n);
	bool pop(int& n);
};
MyIntStack::MyIntStack() {

}
MyIntStack::MyIntStack(int size) {
	this->size = size;
	tos = -1;
	p = new int[size];
}
MyIntStack::MyIntStack(const MyIntStack& s) {
	this->size = s.size;
	this->tos = s.tos;
	this->p = new int[s.size];
	for (int i = 0; i < s.tos; i++) {
		this->p[i] = s.p[i];
	}
}
MyIntStack::~MyIntStack() {
	delete[] p;		//delete 는 동적배열에 대해서만 수행 가능
}

bool MyIntStack::push(int n) {
	if (tos >= size-1) {
		return false;
	}
	++tos;
	p[tos] = n;
	return true;

}
bool MyIntStack::pop(int& n) {
	if (tos < 0) {
		return false;
	}
	n = p[tos];
	tos--;
	return true;

}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;	//복사 생성
	b.push(30);

	int n;
	a.pop(n);	//스택 a 팝
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);	//스택 b 팝
	cout << "스택 b에서 팝한 값 " << n << endl;
}