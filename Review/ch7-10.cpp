#include <iostream>
#include <vector>

using namespace std;

class Statistics {
    vector<int> data;  // 데이터를 저장할 동적 배열을 대신할 vector
    vector<int>::iterator it;

public:
    // 데이터가 있는지 확인하는 연산자 ! 정의
    bool operator!() {
        return data.empty();
    }

    // 데이터를 추가하는 연산자 << 정의
    Statistics& operator<<(int value) {
        data.push_back(value);
        return *this;
    }

    // 통계 데이터를 출력하는 연산자 ~ 정의
    void operator~() {
        for (it = data.begin(); it != data.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    // 평균을 계산하여 반환하는 연산자 >> 정의
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
        cout << "현재 통계 데이터가 없습니다." << endl;

    int x[5];
    cout << "5 개의 정수를 입력하라>>";
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