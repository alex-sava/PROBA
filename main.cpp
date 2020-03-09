
// �������.cpp : ������

#define _CRT_SECURE_NO_WARNINGS   // ���������� ��� ���������� ���������� ����������� ������� "��"

#include <stdio.h>                // ����-�����
#include <iostream>               // ����-����� �++
//#include <windows.h>            // ���� �� ������� ���������
using namespace std;

//�������� ������ queue
class queue
{
    int q[100];
    int sloc, rloc;
    int who; //�������� ����������������� ����� �������
public:
    queue(int id); // ���������������� �����������
    ~queue(); // ����������
    void qput(int i);
    int qget();
};

// ����������� ������������
queue::queue(int id)
{
    rloc = sloc = 0;
    who = id;
    cout << "������� " << who << " ����������������.\n";
}

// ����������� �����������
queue::~queue()
{
    cout << "������� " << who << " ���������.\n";
}


//��������� �� ������� �������������� ��������
void queue::qput(int i)
{
    if (sloc == 100)
    {
        cout << "������� ���������.\n";
        return;
    }
    sloc++;
    q[sloc] = i;
}

//���������� �� ������� �������������� ��������
int queue::qget()
{
    if (rloc == sloc)
    {
        cout << "������� �����.\n";
        return 0;
    }
    rloc++;
    return q[rloc];
}

int main(void)
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    queue a(4);
    a.qput(10);
    a.qput(19);

    cout << "���������� ������� �: ";
    cout << a.qget() << " ";
    cout << a.qget() << "\n";


    system("pause");
    //getchar();
    //getchar();
    return 0;
}