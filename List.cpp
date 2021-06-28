#include <iostream>
#include <fstream>
#include "List.h"
#include "Calculate.h"
#include "Matrix.h"
#include "ioConsole.h"

using namespace std;

List::List()
	: m_tail{ nullptr }, m_head{ nullptr }, m_amount{ 0 }
{

}
List::List(const int &amount)
	: m_tail{ nullptr }, m_head{ nullptr }, m_amount{ 0 }
{
	for (int count = 0; count < amount; ++count)
	{
		Matrix *temp = new Matrix;
		temp->m_next = nullptr;
		temp->m_prev = m_head;
		if (m_amount)
			m_head->m_next = temp;
		else
			m_head = m_tail = temp;

		m_head = temp;
		++m_amount;
	}
}

List::List(const List &copy)
	: List()
{
	Matrix *temp = copy.m_tail;

	for (int count = 1; count <= copy.m_amount; ++count)
	{
		Matrix *matr = new Matrix;
		matr->copyMatrix(temp);

		matr->m_next = nullptr;
		matr->m_prev = m_head;
		if (this->m_amount)
			(this->m_head)->m_next = matr;
		else
			this->m_head = this->m_tail = matr;

		temp = temp->m_next;
		this->m_head = matr;
		++m_amount;
	}
}

List& List::operator=(const List &from)
{
	this->~List();

	Matrix *temp = from.m_tail;

	for (int count = 1; count <= from.m_amount; ++count)
	{
		Matrix *matr = new Matrix;
		matr->copyMatrix(temp);

		matr->m_next = nullptr;
		matr->m_prev = m_head;
		if (this->m_amount)
			(this->m_head)->m_next = matr;
		else
			this->m_head = this->m_tail = matr;

		temp = temp->m_next;
		this->m_head = matr;
		++m_amount;
	}
	return *this;
}

void List::addToTail()
{
	Matrix *temp = new Matrix;
	temp->setMatrix();
	temp->m_prev = nullptr;
	temp->m_next = m_tail;
	if (m_amount)
		m_tail->m_prev = temp;
	else
		m_tail = m_head = temp;

	m_tail = temp;
	++m_amount;
}

void List::addToTail(Matrix *matr)
{
	Matrix *temp = new Matrix;
	temp->copyMatrix(matr);
	temp->m_prev = nullptr;
	temp->m_next = m_tail;
	if (m_amount)
		m_tail->m_prev = temp;
	else
		m_tail = m_head = temp;

	m_tail = temp;
	++m_amount;
}

void List::addToHead()
{
	Matrix *temp = new Matrix;
	temp->setMatrix();
	temp->m_next = nullptr;
	temp->m_prev = m_head;
	if (m_amount)
		m_head->m_next = temp;
	else
		m_head = m_tail = temp;

	m_head = temp;
	++m_amount;
}

void List::addToHead(Matrix *matr)
{
	Matrix *temp = new Matrix;
	temp->copyMatrix(matr);
	temp->m_next = nullptr;
	temp->m_prev = m_head;
	if (m_amount)
		m_head->m_next = temp;
	else
		m_head = m_tail = temp;

	m_head = temp;
	++m_amount;
}

void List::removeTail()
{
	cout << endl;
	Matrix *remove = m_tail;
	m_tail = remove->m_next;
	delete remove;
	--m_amount;
	cout << "The first element was removed.\n" << endl;
}

void List::removeHead()
{
	cout << endl;
	Matrix *remove = m_head;
	m_head = remove->m_prev;
	delete remove;
	--m_amount;
	cout << "The last element was removed.\n" << endl;
}

void List::removeElement(const int &position)
{
	if (position == 1)
	{
		removeTail();
		return;
	}
	if (position == m_amount)
	{
		removeHead();
		return;
	}

	Matrix *del = searchElement(position);
	(del->m_prev)->m_next = del->m_next;
	(del->m_next)->m_prev = del->m_prev;
	delete del;

	--m_amount;
	cout << "Element number [" << position << "] was removed.\n" << endl;
}

void List::removeAll()
{
	int amount = m_amount;
	for (int count = 0; count < amount; ++count)
	{
		removeTail();
	}
}

Matrix* List::searchElement(const int &position)
{
	Matrix *element = m_tail;
	for (int count = 1; count < position; ++count)
		element = element->m_next;
	return element;
}

void List::insert(const int &position)
{
	Matrix *del = searchElement(position);
	Matrix *nextDel = del->m_next;
	Matrix *prevDel = del->m_prev;
	delete del;

	Matrix *newElement = new Matrix;
	newElement->setMatrix();
	newElement->m_next = nextDel;
	newElement->m_prev = prevDel;

	nextDel->m_prev = newElement;
	prevDel->m_next = newElement;
}

void List::printElement(Matrix *element)
{
	element->printMatrix();
}

void List::listForFilterMore(List &filtList, const float &trace)
{
	filtList.removeAll();
	Matrix *goodMatrix;
	Matrix *temp = m_tail;

	for (int count = 0; count < m_amount; ++count)
	{
		if (temp->getTrace() > trace)
		{
			goodMatrix = temp;
			filtList.addToHead(goodMatrix);
		}
		temp = temp->m_next;
	}
}

void List::listForFilterLess(List &filtList, const float &trace)
{
	filtList.removeAll();
	Matrix *goodMatrix;
	Matrix *temp = m_tail;

	for (int count = 0; count < m_amount; ++count)
	{
		if (temp->getTrace() < trace)
		{
			goodMatrix = temp;
			filtList.addToHead(goodMatrix);
		}
		temp = temp->m_next;
	}
}

void List::save()
{
	ofstream fout; // Запись в файл
	fout.open("fileSave.txt");

	if (!fout.is_open())
	{
		cout << "Error." << endl;
		return;
	}

	fout << *this;

	fout.close();
}

void List::load()
{
	ifstream fin;
	fin.open("fileRead.txt");

	if (!fin.is_open())
	{
		cout << "Error." << endl;
		return;
	}

	fin >> *this;
	fin.close();
}

void List::saveBinary()
{
	ofstream fout; // Запись в файл
	fout.open("fileBin.txt", ios::binary);

	if (!fout.is_open())
	{
		cout << "Error." << endl;
		return;
	}

	int i, j, amount = 1;
	Matrix *temp = this->getTail();
	while (amount <= this->getAmount())
	{
		fout.write((char*)&temp->m_demension, sizeof(int));
		fout.write((char*)&temp->m_determinant, sizeof(float));
		fout.write((char*)&temp->m_trace, sizeof(float));
		for (i = 0; i < temp->m_demension; ++i)
			for(j = 0; j < temp->m_demension; ++j)
				fout.write((char*)&(temp->m_matr[i][j]), sizeof(float));

		temp = temp->getNext();
		++amount;
	}

	fout.close();
}

void List::loadBinary()
{
	ifstream fin;
	fin.open("fileBin.txt", ios::binary);

	if (!fin.is_open())
	{
		cout << "Error." << endl;
		return;
	}

	int i, j;
	while (!fin.eof())
	{
		Matrix *temp = new Matrix;
		temp->m_next = nullptr;
		temp->m_prev = m_head;
		if (m_amount)
			m_head->m_next = temp;
		else
			m_head = m_tail = temp;

		fin.read((char*)&temp->m_demension, sizeof(int));
		fin.read((char*)&temp->m_determinant, sizeof(float));
		fin.read((char*)&temp->m_trace, sizeof(float));
		temp->memoryAlloc();
		for (i = 0; i < temp->m_demension; ++i)
			for (j = 0; j < temp->m_demension; ++j)
				fin.read((char*)&(temp->m_matr[i][j]), sizeof(float));

		m_head = temp;
		++m_amount;
	}
	fin.close();
	this->removeHead();
}

List& operator+(List &list, Matrix &matr)
{
	list.addToHead(&matr);
	return list;
}

List& operator+(Matrix &matr, List &list)
{
	list.addToTail(&matr);
	return list;
}

List& List::operator-(const int &index)
{
	this->removeElement(index);
	return *this;
}

List& operator-(const int &index, List &list)
{
	return list - index;
}

void List::operator-()
{
	this->~List();
}

List& List::operator--()
{
	this->removeTail();
	return *this;
}

List& List::operator--(int)
{
	this->removeHead();
	return *this;
}

Matrix List::operator[](const int &index)
{
	return *this->searchElement(index);
}

Matrix operator==(List &list, const int &index)
{
	Matrix *goodMatrix = nullptr;
	Matrix *temp = list.m_tail;

	for (int count = 1; count <= list.m_amount; ++count)
	{
		if (count == index)
			goodMatrix = temp;
		temp = temp->getNext();
	}
	if (goodMatrix)
		return *goodMatrix;

	return *goodMatrix;
}

List operator<(List &list, const float &trace)
{
	List filtList;
	Matrix *goodMatrix;
	Matrix *temp = list.m_tail;

	for (int count = 0; count < list.m_amount; ++count)
	{
		if (temp->getTrace() < trace)
		{
			goodMatrix = temp;
			filtList.addToHead(goodMatrix);
		}
		temp = temp->getNext();
	}
	return filtList;
}

List operator>(List &list, const float &trace)
{
	List filtList;
	Matrix *goodMatrix;
	Matrix *temp = list.m_tail;

	for (int count = 0; count < list.m_amount; ++count)
	{
		if (temp->getTrace() > trace)
		{
			goodMatrix = temp;
			filtList.addToHead(goodMatrix);
		}
		temp = temp->getNext();
	}
	return filtList;
}

ostream& operator<<(ostream& out, List &list)
{
	out << "\n//////////////////////////////////////////\n" << endl;
	out << "\t\t\t Matrix List" << endl;
	out << "\n******************************************" << endl;
	int amount = 1;
	Matrix *temp = list.getTail();
	while (amount <= list.getAmount())
	{
		out << "The number of element is [" << amount << "]" << endl;
		temp->printMatrix();
		temp = temp->getNext();
		++amount;
	}
	out << endl;
	out << "\t\t\t Matrix List" << endl;
	out << "\n//////////////////////////////////////////\n" << endl;

	return out;
}

istream& operator>>(istream& in, List &list)
{
	add(list);
	return in;
}

ofstream& operator<<(ofstream& fout, List &list)
{
	int amount = 1;
	Matrix *temp = list.getTail();
	while (amount <= list.getAmount())
	{
		fout << *temp;
		fout << endl;

		temp = temp->getNext();
		++amount;
	}
	return fout;
}

ifstream& operator>>(ifstream& fin, List &list)
{
	while (!fin.eof())
	{
		Matrix *temp = new Matrix;
		fin >> *temp;
		
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

List::~List()
{
	removeAll();
}