#pragma once
#include<fstream>
#include <iostream>

using namespace std;

class Matrix
{
private:
	int m_demension;
	float **m_matr;
	float m_determinant;
	float m_trace;
	Matrix *m_prev, *m_next;

	void memoryAlloc();
public:
	Matrix();
	Matrix(const Matrix &copy);
	Matrix& operator=(const Matrix &from);
	Matrix* getPrev() { return m_prev; }
	Matrix* getNext() { return m_next; }
	int getDemension() { return m_demension; }
	float** getMatr() { return m_matr; }
	float getDeterminant() { return m_determinant; }
	float getTrace() { return m_trace; }
	int& getDemensionPtr() { return m_demension; }
	float& getDeterminantPtr() { return m_determinant; }
	float& getTracePtr() { return m_trace; }
	void setDemension();
	void setMatrix();
	void copyMatrix(Matrix *newMatrix);
	void enterCoeff();
	void memoryAllocPub() { memoryAlloc(); }

	void printMatrix();

	friend class List;

	friend ostream& operator<<(ostream& out, Matrix &matrix);
	friend istream& operator>>(istream& in, Matrix &matrix);
	friend ofstream& operator<<(ofstream& fout, Matrix &matr);
	friend ifstream& operator>>(ifstream& fin, Matrix &matr);
	friend ifstream& operator>>(ifstream& fin, List &list);

	friend float calculateDeterminant(float **matr, const int &demension);
	friend float calculateTrace(float **matr, const int &demension);

	~Matrix();
};