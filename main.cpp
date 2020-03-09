
// пробный.cpp : Классы

#define _CRT_SECURE_NO_WARNINGS   // добавление для отключения блокировки стандартных функций "СИ"

#include <stdio.h>                // ввод-вывод
#include <iostream>               // ввод-вывод С++
//#include <windows.h>            // ввод на русской кириллице
using namespace std;

//Создание класса queue
class queue
{
    int q[100];
    int sloc, rloc;
    int who; //содержит идентификационных номер очереди
public:
    queue(int id); // праметризованный конструктор
    ~queue(); // деструктор
    void qput(int i);
    int qget();
};

// Определение конструктора
queue::queue(int id)
{
    rloc = sloc = 0;
    who = id;
    cout << "Очередь " << who << " инициализирована.\n";
}

// Определение деструктора
queue::~queue()
{
    cout << "Очередь " << who << " разрушена.\n";
}


//Занесение из очереди целочисленного значения
void queue::qput(int i)
{
    if (sloc == 100)
    {
        cout << "Очередь заполнена.\n";
        return;
    }
    sloc++;
    q[sloc] = i;
}

//Извлечение из очереди целочисленного значения
int queue::qget()
{
    if (rloc == sloc)
    {
        cout << "Очередь пуста.\n";
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

    cout << "Содержимое очереди а: ";
    cout << a.qget() << " ";
    cout << a.qget() << "\n";


    system("pause");
    //getchar();
    //getchar();
    return 0;
}