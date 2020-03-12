// пробный.cpp : Классы
#define _CRT_SECURE_NO_WARNINGS   // добавление для отключения блокировки стандартных функций "СИ"


#include <iostream> // подключаем cin и cout
#include <ctime> // подключаем clock
#include <cstdlib> 
//#include <string> 


using namespace std;

class timer
{
    int seconds;
public:
    timer(const char*  t) { seconds = atoi(t); };
    timer(int t) { seconds = t; };
    timer(int min, int sec) { seconds = min * 60 + sec; };

    void run();
};

void timer::run()
{
    clock_t t1;
    t1 = clock();
    while ((clock() / CLOCKS_PER_SEC - t1 / CLOCKS_PER_SEC) < seconds)
        ;
    cout << "\a";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    timer a(1);
    a.run();

    cout << "Введите количество секунд: ";
    char str[80];
    cin >> str;
    timer b(str);
    b.run();

    cout << "Введите минуты и секунды: ";
    int min, sec;
    cin >> min >> sec;
    timer c(min, sec);
    c.run();

    return 0; 
}

/*
#include <stdio.h>                
#include <iostream>               
using namespace std;

enum resolution {low, medium, high};

class display
{
    int width; //закрытый член по умолчанию
    int height;
    resolution res;
public:
    void set_dim(int w, int h) { width = w; height = h; };
    void get_dim(int& w, int& h) { w = width; h = height; };
    void set_res(resolution r) { res = r; };
    resolution get_res() { return res; };
};

char names[3][8] = {"низкий", "средний", "высокий"};

int main(void)
{
    setlocale(LC_ALL, "russian");

    display display_mode[3];
    int i, w, h;
    
    display_mode[0].set_res(low);
    display_mode[0].set_dim(640, 480);

    display_mode[1].set_res(medium);
    display_mode[1].set_dim(800, 600);

    display_mode[2].set_res(high);
    display_mode[2].set_dim(1600, 1200);


    cout << "Возможные режимы отображения данных:\n\n";
    
    for (i = 0; i < 3; i++)
    {
        cout << names[display_mode[i].get_res()] << ": ";
        display_mode[i].get_dim(w, h);
        cout << w << " x " << h << "\n";
    }

    return 0;
    system("pause");
}*/