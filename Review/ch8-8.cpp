#include <iostream>
#include <string>

using namespace std;

// �⺻ ������ Ŭ����
class Printer {
protected:
    string model;          // �𵨸�
    string manufacturer;  // ������
    int printedCount;     // �μ� �ż�
    int availableCount;   // �μ� ���� �ܷ�

public:
    // �⺻ ������
    Printer() : model(""), manufacturer(""), printedCount(0), availableCount(0) {}

    // �Ű������� �޴� ������
    Printer(const string& model, const string& manufacturer, int printedCount, int availableCount)
        : model(model), manufacturer(manufacturer), printedCount(printedCount), availableCount(availableCount) {}

    virtual ~Printer() {}

    virtual void display() const {
        cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��";
    }

    virtual void print(int pages) = 0; // ���� ���� �Լ�
};

// ��ũ�� ������ Ŭ����
class InkJetPrinter : public Printer {
protected:
    int availableInk; // ��ũ �ܷ�

public:
    // �⺻ ������
    InkJetPrinter() : Printer(), availableInk(0) {}

    // �Ű������� �޴� ������
    InkJetPrinter(const string& model, const string& manufacturer, int printedCount, int availableCount, int availableInk)
        : Printer(model, manufacturer, printedCount, availableCount), availableInk(availableInk) {}

    void print(int pages) override {
        if (pages > availableCount) {
            cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
            return;
        }
        if (pages > availableInk) {
            cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
            return;
        }

        availableCount -= pages;
        availableInk -= pages;
        printedCount += pages;
        cout << "����Ʈ�Ͽ����ϴ�." << endl;
    }

    void display() const override {
        Printer::display();
        cout << ", ���� ��ũ " << availableInk << endl;
    }
};

// ������ ������ Ŭ����
class LaserPrinter : public Printer {
protected:
    int availableToner; // ��� �ܷ�

public:
    // �⺻ ������
    LaserPrinter() : Printer(), availableToner(0) {}

    // �Ű������� �޴� ������
    LaserPrinter(const string& model, const string& manufacturer, int printedCount, int availableCount, int availableToner)
        : Printer(model, manufacturer, printedCount, availableCount), availableToner(availableToner) {}

    void print(int pages) override {
        if (pages > availableCount) {
            cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
            return;
        }
        if (pages > availableToner) {
            cout << "��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
            return;
        }

        availableCount -= pages;
        availableToner -= pages;
        printedCount += pages;
        cout << "����Ʈ�Ͽ����ϴ�." << endl;
    }

    void display() const override {
        Printer::display();
        cout << ", ���� ��� " << availableToner << endl;
    }
};

int main() {
    // ��ũ�� �����Ϳ� ������ �����͸� ���� �����մϴ�.
    Printer* inkJetPrinter = new InkJetPrinter("Officejet V40", "HP", 0, 5, 10);
    Printer* laserPrinter = new LaserPrinter("SCX_6x45", "�Ｚ����", 0, 3, 20);

    char choice;
    int printerType, pages;

    do {
        // ���� ������ ���� ���
        cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
        cout << "��ũ�� : ";
        inkJetPrinter->display();
        cout << "������ : ";
        laserPrinter->display();

        // ������ ���� �� �ż� �Է�
        cout << "������(1:��ũ��, 2:������)�� �ż� �Է� >>";
        cin >> printerType >> pages;

        if (printerType == 1) {
            inkJetPrinter->print(pages);
        }
        else if (printerType == 2) {
            laserPrinter->print(pages);
        }
        else {
            cout << "�߸��� �Է��Դϴ�." << endl;
        }

        // ������ ���� �ٽ� ���
        cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
        cout << "��ũ�� : ";
        inkJetPrinter->display();
        cout << "������ : ";
        laserPrinter->display();

        // ��� ���� ���� ����
        cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)>>";
        cin >> choice;


    } while (choice == 'y' || choice == 'Y');

    // ���� �Ҵ�� �޸� ����
    delete inkJetPrinter;
    delete laserPrinter;

    return 0;
}
