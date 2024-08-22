#include <iostream>
#include <string>

using namespace std;

// 기본 프린터 클래스
class Printer {
protected:
    string model;          // 모델명
    string manufacturer;  // 제조사
    int printedCount;     // 인쇄 매수
    int availableCount;   // 인쇄 종이 잔량

public:
    // 기본 생성자
    Printer() : model(""), manufacturer(""), printedCount(0), availableCount(0) {}

    // 매개변수를 받는 생성자
    Printer(const string& model, const string& manufacturer, int printedCount, int availableCount)
        : model(model), manufacturer(manufacturer), printedCount(printedCount), availableCount(availableCount) {}

    virtual ~Printer() {}

    virtual void display() const {
        cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장";
    }

    virtual void print(int pages) = 0; // 순수 가상 함수
};

// 잉크젯 프린터 클래스
class InkJetPrinter : public Printer {
protected:
    int availableInk; // 잉크 잔량

public:
    // 기본 생성자
    InkJetPrinter() : Printer(), availableInk(0) {}

    // 매개변수를 받는 생성자
    InkJetPrinter(const string& model, const string& manufacturer, int printedCount, int availableCount, int availableInk)
        : Printer(model, manufacturer, printedCount, availableCount), availableInk(availableInk) {}

    void print(int pages) override {
        if (pages > availableCount) {
            cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
            return;
        }
        if (pages > availableInk) {
            cout << "잉크가 부족하여 프린트 할 수 없습니다." << endl;
            return;
        }

        availableCount -= pages;
        availableInk -= pages;
        printedCount += pages;
        cout << "프린트하였습니다." << endl;
    }

    void display() const override {
        Printer::display();
        cout << ", 남은 잉크 " << availableInk << endl;
    }
};

// 레이저 프린터 클래스
class LaserPrinter : public Printer {
protected:
    int availableToner; // 토너 잔량

public:
    // 기본 생성자
    LaserPrinter() : Printer(), availableToner(0) {}

    // 매개변수를 받는 생성자
    LaserPrinter(const string& model, const string& manufacturer, int printedCount, int availableCount, int availableToner)
        : Printer(model, manufacturer, printedCount, availableCount), availableToner(availableToner) {}

    void print(int pages) override {
        if (pages > availableCount) {
            cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
            return;
        }
        if (pages > availableToner) {
            cout << "토너가 부족하여 프린트 할 수 없습니다." << endl;
            return;
        }

        availableCount -= pages;
        availableToner -= pages;
        printedCount += pages;
        cout << "프린트하였습니다." << endl;
    }

    void display() const override {
        Printer::display();
        cout << ", 남은 토너 " << availableToner << endl;
    }
};

int main() {
    // 잉크젯 프린터와 레이저 프린터를 동적 생성합니다.
    Printer* inkJetPrinter = new InkJetPrinter("Officejet V40", "HP", 0, 5, 10);
    Printer* laserPrinter = new LaserPrinter("SCX_6x45", "삼성전자", 0, 3, 20);

    char choice;
    int printerType, pages;

    do {
        // 현재 프린터 상태 출력
        cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
        cout << "잉크젯 : ";
        inkJetPrinter->display();
        cout << "레이저 : ";
        laserPrinter->display();

        // 프린터 선택 및 매수 입력
        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >>";
        cin >> printerType >> pages;

        if (printerType == 1) {
            inkJetPrinter->print(pages);
        }
        else if (printerType == 2) {
            laserPrinter->print(pages);
        }
        else {
            cout << "잘못된 입력입니다." << endl;
        }

        // 프린터 상태 다시 출력
        cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
        cout << "잉크젯 : ";
        inkJetPrinter->display();
        cout << "레이저 : ";
        laserPrinter->display();

        // 계속 진행 여부 묻기
        cout << "계속 프린트 하시겠습니까?(y/n)>>";
        cin >> choice;


    } while (choice == 'y' || choice == 'Y');

    // 동적 할당된 메모리 해제
    delete inkJetPrinter;
    delete laserPrinter;

    return 0;
}
