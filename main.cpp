#include <iostream>
#include <string>
#include "Calculate.h"
#include "Matrix.h"
#include "List.h"
#include "ioConsole.h"

using namespace std;

int main()
{
	//startProgram();

	List list;
	List filtList;
	//while (1)
	//{
	//	readCommand(list, filtList);
	//}

	//1. Конструкторы копирования и операторы присваивания
	{
		//List L;
		//Matrix a;
		//cin >> L >> L >> L;
		//List B(L);
		//cout << B;
		//-B;
		//cin >> B >> B;
		//B = L;
		//cout << B;

		//Matrix a;
		//cin >> a;
		//Matrix b(a);
		//cout << b;

		//Matrix a, b;
		//cin >> a >> b;
		//b = a;
		//cout << b;
	}

	//2. Добавление, удаление эл-ов
	{
		//List L;
		//Matrix a, b;
		//cin >> a >> b;
		//L + a + a;  // +2 в конец.
		//cout << L;
		//b + L;		//+1 в начало.
		//cout << L;
		//L + b + b;	//+2 в конец (всего 5).
		//L - 3;		//Удалит 3-ий элемент в списке (a), осталось 4.
		//cout << L;
		//4 - L;		//Удалит 4-ий элемент в списке (b), осталось 3.
		//cout << L;	// b, a, b.
	}

	//3. Получение элемента по индексу
	{
		//List L;
		//cin >> L >> L >> L >> L;
		//cout << L;
		//Matrix a = L[3];
		//cout << a;
	}

	//4. Фильтр по следу матрицы и поиск по индексу.
	{
		//List L, B;
		//cin >> L >> L >> L;
		//B = L < 3.23;
		//cout << B;
		//B = L > -3.12;
		//cout << B;
		//Matrix a = L == 2;
		//cout << a;
	}

	//5. Ввод вывод для файла.
	{
		//ofstream fout;
		//	fout.open("fileSave.txt");
		//ifstream fin;
		//	fin.open("fileRead.txt");
		//
		//List L;
		//fin >> L;
		//cout << L;
		//fout << L;
		//Matrix a;
		//fin >> a;
		//cout << a;
		//fout << a;
	}

	//7. Сохранить и извлечь объект в бинарном режиме
	{
		//List L;
		//cin >> L >> L >> L;
		//cout << L;
		//L.saveBinary();
		//-L;
		//cout << L;
		//L.loadBinary();	
		//cout << L;
	}

	system("pause");
	return 0;
}