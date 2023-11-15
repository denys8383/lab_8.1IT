﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція для підрахунку кількості входжень символів '+' , '-', та '=' у рядку
int Count(char* str)
{
    // Перевірка, чи рядок не має довжини 0
    if (strlen(str) == 0)
        return 0;

    // Ініціалізація лічильника
    int count = 0;

    // Цикл для перебору символів у рядку
    for (int i = 0; str[i] != '\0'; i++)
    {
        // Перевірка на наявність символів '+' , '-', та '='
        if (str[i] == '+' || str[i] == '-' || str[i] == '=')
            count++;
    }

    return count;
}

// Функція для модифікації рядка шляхом подвоєння символів '+' , '-', та '='
char* Change(char* str)
{
    // Визначення довжини вхідного рядка
    size_t len = strlen(str);

    // Перевірка, чи рядок не має довжини 0
    if (len == 0)
        return str;

    // Виділення пам'яті для нового рядка з урахуванням можливого подвоєння символів
    char* tmp = new char[len * 3 + 1];

    // Ініціалізація вказівника для роботи з новим рядком
    char* t = tmp;

    // Перший символ нового рядка - завжди нульовий символ
    tmp[0] = '\0';

    // Цикл для перебору символів у вхідному рядку
    for (size_t i = 0; i < len; i++)
    {
        // Перевірка на наявність символів '+' , '-', та '='
        if (str[i] == '+' || str[i] == '-' || str[i] == '=')
        {
            // Додавання двох символів '*' до нового рядка
            strcat(t, "**");
            // Зміщення вказівника на дві позиції вправо
            t += 2;
        }
        else
        {
            // Копіювання символу в новий рядок
            *t++ = str[i];
            // Завершення рядка символом '\0'
            *t = '\0';
        }
    }

    // Копіювання модифікованого рядка назад у вхідний рядок
    strcpy(str, tmp);

    // Звільнення виділеної пам'яті для нового рядка
    delete[] tmp;

    // Повернення модифікованого вхідного рядка
    return str;
}

int main()
{
    // Оголошення рядка для введення користувача
    char str[101];
    cout << "Enter string: " << endl;

    // Зчитування рядка з консолі
    cin.getline(str, 100);
    cout << "String contains  " << Count(str) << " symbols '+', '-', and '='." << endl;

    // Модифікація рядка
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
