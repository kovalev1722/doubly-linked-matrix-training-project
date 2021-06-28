#pragma once

#include<fstream>
#include <iostream>
#include "Matrix.h"
#include "Calculate.h"

using namespace std;

class List
{
protected:
	Matrix *m_tail, *m_head;
	int m_amount;
public:
	List();
	List(const List &copy); //
	List(const int &amount);
	List& operator=(const List &from);
	Matrix* getTail() { return m_tail; }
	Matrix* getHead() { return m_head; }
	int getAmount() { return m_amount; }
	Matrix* searchElement(const int &);
	void addToTail();
	void addToTail(Matrix *matr);
	void addToHead();
	void addToHead(Matrix *matr);
	void removeTail();
	void removeHead();
	void removeElement(const int &);
	void removeAll();
	void insert(const int &);
	void printElement(Matrix *element);
	void listForFilterMore(List &filtList,const float &trace);
	void listForFilterLess(List &List,const float &trace);
	void save();
	void load();

	friend List& operator+(List &list, Matrix &matr);
	friend List& operator+(Matrix &matr, List &list);
	List& operator-(const int &index);
	friend List& operator-(const int &index, List &list);
	void operator-();

	Matrix operator[](const int &index);

	friend Matrix operator==(List &list, const int &index);
	friend List operator<(List &list, const float &trace);
	friend List operator>(List &list, const float &trace);

	friend ostream& operator<<(ostream& out, List &list);
	friend istream& operator>>(istream& in, List &list);
	friend ofstream& operator<<(ofstream& fout, List &list);
	friend ifstream& operator>>(ifstream& fin, List &list);

	void saveBinary();
	void loadBinary();

	List& operator--();
	List& operator--(int);

	~List();
};

/*
friend ifstream& operator>>(ifstream& fin, List &list)
	{
		int i, j;
		while (!fin.eof())
		{
			Matrix *temp = new Matrix;

			int demension;
			fin >> demension;

			temp->m_demension = demension;
			temp->memoryAlloc();

			for (i = 0; i < demension; ++i)
				for (j = 0; j < demension; ++j)
					fin >> temp->m_matr[i][j];

			temp->m_determinant = calculateDeterminant(temp->m_matr, demension);
			temp->m_trace = calculateTrace(temp->m_matr, demension);

			temp->m_next = nullptr;
			temp->m_prev = list.m_head;
			if (list.m_amount)
				list.m_head->m_next = temp;
			else
				list.m_head = list.m_tail = temp;

			list.m_head = temp;
			++list.m_amount;
		}
		return fin;
	}
*/