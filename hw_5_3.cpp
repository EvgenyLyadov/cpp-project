//Лядов Евгений КМБ2 Вариант 9
//Написать программу, которая считывает текст из файла и выводит на экран только предложения, состоящие из заданного количества слов.
#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
#include <windows.h>
#include <string>
using namespace std;
int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	string str,str_len_slov;
	int i = 0,j, slov = 0, predl = 0, len, pos_dot;
	ifstream f; // открытие файла для чтения
	f.open("Text.txt");
	getline(f, str); //считывание строки из файла
	f.close();
	cout << "Исходный текст\n" << str << endl;
	cout << "Введите длину предложения" << endl;
	cin >> len;
	while (str != "\0")
	{
		if (str[0] != ' ') //проверка первого символа на пробел
			slov = 1;      // если 1 символ не пробел, то количство слов+1
		else
			slov = 0;	   // если 1 символ пробел, то количство слов = 0
		for (i = 0;str[i] != '.';i++) // цикл для прохождения по всем символам до точки
			if (str[i] == ' ' && str[i + 1] != ' ') // условие для проверка явлется ли символ пробелом, и не является ли следующий за ним пробелом
				slov += 1;
		if (slov == len) // если количество слов в предложении равно нужному, то  
		{
			str_len_slov.assign(str, 0, i + 1); //дополниельной строке присваиваем это предложение
			cout << str_len_slov << endl;       //выводим его
		}
		str_len_slov = "\0"; //обнуление дополнительной строки
		slov = 0; //обнуление счетчика слов
		pos_dot = str.find('.'); //нахождение позиции точки
		str.erase(0, pos_dot+1); //удаление из всей строки начиная с нулевого символа до первойй точки(включая точку)
	}
}
/*тест 1
Исходный текст
a bb ccc dddd. a bb ccc. a bb ccc dddd eeeee ffffff. a bb. a. a bb ccc. a b. a bb ccc. a bb ccc dddd. while i zero. ich will schlafen. СЏ РЅРµ С…РѕС‡Сѓ СЃРїР°С‚СЊ.
Введите длину предложения
3
 a bb ccc.
 a bb ccc.
 a bb ccc.
 while i zero.
 ich will schlafen.

C:\Users\Женя\source\repos\hw_5_3\Debug\hw_5_3.exe (процесс 11144) завершает работу с кодом 0.
Чтобы закрыть это окно, нажмите любую клавишу…
*/

