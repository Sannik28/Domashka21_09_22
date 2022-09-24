// Domashka21_09_22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h> 
#include<Windows.h>
#include <time.h>
#include <stdio.h.>

using namespace std;

//Задание 1 удалить из строки символ с заданным номером
void udal(char *stroka, int n) {
    char* stroka2 = new char[128];
    int sh = 0;
    for (int i = 0, j=0; i < strlen(stroka); i++, j++)
    {
        if (i == n-1) {
            i++;
            sh++;
        }
        *(stroka2 + j) = *(stroka + i);
    }
    for (int i = 0; i < (strlen(stroka)-sh); i++)
    {
        cout << *(stroka2 + i);
    }
}
//Задание 2 удалить все вхождения заданного символа
void udalsimv(char* stroka, char s)
{
    char* stroka2 = new char[128];
    int n = strlen(stroka);

    int k = 0, i=0;
        while (k<n){
            if (*(stroka + i) != s) {
                *(stroka2 + k) = *(stroka + i);
                i++;
                k++;
            }
            else {
                i++;
            }
        }
        for (int i = 0; i < strlen(stroka2); i++)
        {
            cout << *(stroka2 + i);
        }
}

//Задание 3 вставить в строку в заданную позицию заданный символ
void vstav(char* stroka, char s, int n)
{
    char* stroka2 = new char[strlen(stroka) + 1];
    strncpy(stroka2, stroka, n - 1);
}
/*
{
    char* stroka2 = new char[strlen(stroka) + 1];
    strcpy_s(stroka2, n, "");
    strncat_s(stroka2, strlen(stroka) - n, stroka, n+1);
    *(stroka2 + n) = s;
    strcat_s(stroka2, strlen(stroka) + n, stroka + n);
    cout << stroka2;
}
*/

//Задание 4 Программа заменяет "." на "!"



/*
//эта не работает оставляю на подумать
void vstav(char* stroka, char s, int n)
{
    int t = strlen(stroka) + 1;
    char* stroka2 = new char[t];
    for (int i=0, j=0; i<t-1; ++i, ++j)
    {
        if (i == n - 1) {
            *(stroka2 + j) = s; cout << *(stroka2 + j)<<endl; j++;
        }
        else {
            *(stroka2 + j) = *(stroka + i);
            cout << *(stroka2 + j)<<endl;
        }
    }
     for (int i = 0; i < strlen(stroka2); i++)
    {
        cout << *(stroka2 + i);
    }
   
}
*/


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* stroka= new char[128];
    cout << "Введите строку\n";
    gets_s(stroka, strlen(stroka));
    //Задание1
    /*
    int n;
    cout << "Введите номер удаляемного символа в строке\n";
    cin >> n;
    udal(stroka, n);
    */
    //Задание 2
    /*
    char s;
    cout << "Введите удаляемый символ\n";
    cin >> s;
    udalsimv(stroka, s);
    */
    //Задание 3
    char s;
    cout << "Введите вставляемый символ\n";
    cin >> s;
    int n;
    cout << "Введите номер позиции\n";
    cin >> n;
    vstav(stroka, s, n);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
