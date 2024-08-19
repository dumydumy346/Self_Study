#include <iostream>

using namespace std;

class ArrayUtility2 {

public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};
// concat �Լ� ����
int* ArrayUtility2::concat(int s1[], int s2[], int size) {
    int* array1 = new int[size * 2];
    for (int i = 0; i < size; i++) {
        array1[i] = s1[i];
    }
    for (int i = 0; i < size; i++) {
        array1[i + size] = s2[i];
    }
    return array1;
}

// remove �Լ� ����
int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
    int* temp = new int[size];
    retSize = 0;

    for (int i = 0; i < size; i++) {
        int j;
        for (j = 0; j < size; j++) {
            if (s1[i] == s2[j]) {
                break;
            }
        }
        if (j == size) {
            temp[retSize] = s1[i];
            retSize++;
        }
    }


    if (retSize == 0) {
        delete[] temp;
        return nullptr;  // ��ȯ�� �迭�� ������ NULL ��ȯ
    }
    //retSize ũ�⸸ŭ�� �迭 ���� �����ϰ� temp[]�� �����´�
    int* result = new int[retSize]; 
    for (int i = 0; i < retSize; i++) {
        result[i] = temp[i];
    }
    delete[] temp;
    return result;
}
int main() {
    int x[5],y[5];
    int retSize;
    
    cout << "������ 5 �� �Է��϶�. �迭 x�� �����Ѵ�>>";
    for (int i = 0; i < 5; i++)
        cin >> x[i];
    
    cout << "������ 5 �� �Է��϶�. �迭 y�� �����Ѵ�>>";
    for (int i = 0; i < 5; i++)
        cin >> y[i];
    
    cout << "��ģ ���� �迭�� ����Ѵ�." << endl;
    int* concatArray = ArrayUtility2::concat(x,y,5);
    for (int i = 0; i < 10; i++)
        cout << concatArray[i] << " ";
   
    cout << endl;
    delete[] concatArray;
    
    cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ 2" << endl;
    int* removeArray = ArrayUtility2::remove(x, y, 5, retSize);
    for (int i = 0; i < retSize; i++)
        cout << removeArray[i] << " ";

    cout << endl;
    delete[] removeArray;
}