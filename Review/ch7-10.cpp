#include <iostream>
#include <vector>

using namespace std;

class Statistics {
    vector<int> data;  // �����͸� ������ ���� �迭�� ����� vector
    vector<int>::iterator it;

public:
    // �����Ͱ� �ִ��� Ȯ���ϴ� ������ ! ����
    bool operator!() {
        return data.empty();
    }

    // �����͸� �߰��ϴ� ������ << ����
    Statistics& operator<<(int value) {
        data.push_back(value);
        return *this;
    }

    // ��� �����͸� ����ϴ� ������ ~ ����
    void operator~() {
        for (it = data.begin(); it != data.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    // ����� ����Ͽ� ��ȯ�ϴ� ������ >> ����
    void operator>>(int& avg) {
        if (data.empty()) {
            avg = 0;
            return;
        }

        int sum = 0;
        for (it = data.begin(); it != data.end(); ++it) {
             sum += *it;
        }

        avg = sum / data.size();
    }
};

int main() {
    Statistics stat;

    if (!stat)
        cout << "���� ��� �����Ͱ� �����ϴ�." << endl;

    int x[5];
    cout << "5 ���� ������ �Է��϶�>>";
    for (int i = 0; i < 5; i++)
        cin >> x[i];

    for (int i = 0; i < 5; i++)
        stat << x[i];

    stat << 100 << 200;

    ~stat;

    int avg;
    stat >> avg;

    cout << "avg=" << avg << endl;

    return 0;
}