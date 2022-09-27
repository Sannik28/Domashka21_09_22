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
// вариант разобранный на уроке
char* udal2(char* stroka, int n) {
    char* new_arr = new char[strlen(stroka) - 1];
    strncpy_s(new_arr, strlen(stroka), stroka, n - 1);
    strcat_s(new_arr, strlen(stroka), stroka + n);
    delete[]stroka;
    return new_arr;
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

//вариант разобранный на уроке, очень интересный
char* udalsimv2(char* stroka, char s) {
    char* new_stroka = new char[256]{ "" };
    char* temp_stroka;
    while (temp_stroka = strchr(stroka, s)) {
        strncat_s(new_stroka, 256, stroka,
        strlen(stroka) - strlen(temp_stroka));
        stroka = ++temp_stroka;
    }
    strcat_s(new_stroka, 256, stroka);

    return new_stroka;
}

//Задание 3 вставить в строку в заданную позицию заданный символ

char* vstav(char* stroka, char s, int n) {
    char* new_str = new char[strlen(stroka) + 1];
    strncpy_s(new_str, n + 2, stroka, n + 1);
    *(new_str + n) = s;
    strcat_s(new_str, strlen(stroka) + 2, stroka + n);
    return new_str;
}

//Задание 4 Программа заменяет "." на "!"
char* f4(char* stroka) {
    char* temp;
    while (temp = strchr(stroka, '.')) {
        *temp = '!';
        strcpy_s(stroka + (strlen(stroka) - strlen(temp)),strlen(stroka),temp);
    }
    return stroka;
}

//Задание 5: посчитать сколько раз он встречается строке исходный символ.
int f5(char* stroka, int s) {
    char* temp;
    int count = 0;
    while (temp = strchr(stroka, s)) {
        count++;
        stroka = ++temp;
    }
    return count;
}
//Задание 6: Определить количество букв, цифр и остальных символов
//оно же задание 8
    void f6(char* stroka) {
    int n = 0, c = 0, o = 0;
    for (int i = 0; i < strlen(stroka); i++) {
        //первый вариант
        if (stroka[i] >= 48 && stroka[i] <= 57)
            n++;
        else if (stroka[i] >= 65 && stroka[i] <= 90 ||
            stroka[i] >= 97 && stroka[i] <= 122)
            c++;
        else
            o++;
        //второй вариант
        if (isdigit(stroka[i]))
            n++;
        else if (isalpha(stroka[i]))
            c++;
        else
            o++;
    }
    cout << n << " " << c << " " << o;
}

  //  Задание 7: Заменить все пробелы на табуляции.
        char* f7(char* stroka) {
        char* temp;
        while (temp = strchr(stroka, ' ')) {
            *temp = '\t';
            //можно я оставлю в своей домашке ваши комментарии? Чтобы пользоваться в будущем если потребуется вспомнить.
            strcpy_s(
                stroka + (strlen(stroka) - strlen(temp)), // куда копируем (со сдвигом по указетлю)
                strlen(stroka), // буферная память для копирования
                temp); // что копируем
        }
        return stroka;
    }
       // Задание 9:Подсчитать количество слов во введенном предложении.
          
            int f9(char* stroka) {
            char* temp;
            int count = 1;
            while (temp = strchr(stroka, ' ')) {
                count++;
                stroka = ++temp;
            }
            return count;
        }
//Задание 10: Проверка полиндрома (задание по типу выполняемого на уроке от 18.09
            char* f10(char* stroka) {
            char* str = new char[256];
            for (int i = 0, j = 0; i < strlen(stroka) + 1; i++) {
                if (stroka[i] != ' ') {
                    str[j] = stroka[i];
                    j++;
                }
            }
            delete[]stroka;
            if (_stricmp(str, _strrev(str)) == 0) cout << "палиндром";
            else cout << "Нет"; 
}


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
    /*
    char s;
    cout << "Введите вставляемый символ\n";
    cin >> s;
    int n;
    cout << "Введите номер позиции\n";
    cin >> n;
    vstav(stroka, s, n);
    */
    //Задание 4
    /*
    f4(stroka);
    */
    //Задание 5
    /*
    char s;
    cout << "Введите искомый символ\n";
    cin >> s;
    f5(stroka, s);
    */
    //Задание 6
    /*
    f6(stroka);
    */
    //Задание 7
    /*
    f7(stroka);
    */
    //Задание 8
    /*
    f6(stroka);
    */
    //Задание 9
    /*
    f9(stroka);
    */
    //Задание 10
    f10(stroka);





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
