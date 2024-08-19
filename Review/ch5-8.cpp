#include <iostream>

using namespace std;

class MyIntStack {
	int* p;		//���������ϴ� �迭
	int size;	//������ �ִ�ũ��
	int tos;	//���ó��� ž �ε���
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);	//���� ������
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
	delete[] p;		//delete �� �����迭�� ���ؼ��� ���� ����
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
	MyIntStack b = a;	//���� ����
	b.push(30);

	int n;
	a.pop(n);	//���� a ��
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n);	//���� b ��
	cout << "���� b���� ���� �� " << n << endl;
}