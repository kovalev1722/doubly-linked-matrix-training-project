#include <iostream>
#include <string>
#include <fstream>
#include "Calculate.h"
#include "Matrix.h"
using namespace std;

void Matrix::memoryAlloc()
{
	m_matr = new float*[m_demension];
	for (int i = 0; i < m_demension; ++i)
		m_matr[i] = new float[m_demension];
}

Matrix::Matrix()
	: m_demension{ 0 }, m_matr{ nullptr }, m_determinant{ 0 }, m_trace{ 0 }, m_prev{ nullptr }, m_next{ nullptr }
{

}

Matrix::Matrix(const Matrix &copy)
	: m_demension{ copy.m_demension }, m_matr{ nullptr }, m_determinant{ copy.m_determinant },
	m_trace{ copy.m_trace }, m_prev{ nullptr }, m_next{ nullptr }
{
	memoryAlloc();
	for (int i = 0; i < m_demension; ++i)
		for (int j = 0; j < m_demension; ++j)
			m_matr[i][j] = copy.m_matr[i][j];
}

Matrix& Matrix::operator=(const Matrix &from)
{
	this->~Matrix();
	m_demension = from.m_demension;
	memoryAlloc();
	for (int i = 0; i < m_demension; ++i)
		for (int j = 0; j < m_demension; ++j)
			m_matr[i][j] = from.m_matr[i][j];

	m_determinant = from.m_determinant;
	m_trace = from.m_trace;

	return *this;
}

void Matrix::setMatrix()
{
	setDemension();
	memoryAlloc();
	enterCoeff();
	m_determinant = calculateDeterminant(m_matr, m_demension);
	m_trace = calculateTrace(m_matr, m_demension);
	cout << "\nDeteminant is: " << m_determinant << "\nTrace is: " << m_trace << "\n" << endl;
}

void Matrix::copyMatrix(Matrix *newMatrix)
{
	m_demension = newMatrix->getDemension();
	memoryAlloc();
	float **temp = newMatrix->getMatr();
	m_determinant = newMatrix->getDeterminant();
	m_trace = newMatrix->getTrace();

	for (int i = 0; i < m_demension; ++i)
		for (int j = 0; j < m_demension; ++j)
			m_matr[i][j] = temp[i][j];
}

void Matrix::setDemension()
{

	while (1) {
		cout << "\nEnter the demension of the matrix: ";

		int demension;
		double d_demension;
		cin >> d_demension;
		cin.clear(),
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		demension = static_cast<int>(d_demension);

		if (demension == d_demension && demension > 0) {
			m_demension = demension;
			return;
		}
		else {
			cout << "There is no such matrix." << endl;
			cin.clear(),
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
	}
}

void Matrix::enterCoeff()
{
	cout << "Enter the matrix coefficients.\n" << endl;

	for (int i = 0; i < m_demension; i++) {
		for (int j = 0; j < m_demension; j++) {
			cout << "[" << i + 1 << "]" << "[" << j + 1 << "]: ";
			cin >> m_matr[i][j];
			if (!cin.fail()) {
				cin.clear(),
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			while (cin.fail()) {
				cout << "This is not a number." << endl;

				cin.clear(),
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "[" << i + 1 << "]" << "[" << j + 1 << "]: ";
				cin >> m_matr[i][j];
			}
		}
	}
}

void Matrix::printMatrix()
{
	cout << "Demension = " << m_demension << endl;
	cout << "Determinant = " << m_determinant << endl;
	cout << "Trace = " << m_trace << "\n" << endl;
	for (int i = 0; i < m_demension; i++) {
		for (int j = 0; j < m_demension; j++) {
			cout << "\t" << m_matr[i][j];
		}
		cout << endl;
	}
	cout << "\n******************************************" << endl;
}

ostream& operator<<(ostream& out, Matrix &matr)
{
	out << "Demension = " << matr.getDemension() << endl;
	out << "Determinant = " << matr.getDeterminant() << endl;
	out << "Trace = " << matr.getTrace() << "\n" << endl;
	for (int i = 0; i < matr.getDemension(); i++) {
		for (int j = 0; j < matr.getDemension(); j++) {
			out << "\t" << matr.getMatr()[i][j];
		}
		out << endl;
	}
	out << "\n******************************************" << endl;
	return out;
}

istream& operator>>(istream& in, Matrix &matr)
{
	matr.setMatrix();
	return in;
}

ofstream& operator<<(ofstream& fout, Matrix &matr)
{
	fout << "Demension = " << matr.getDemension() << endl;
	fout << "Determinant = " << matr.getDeterminant() << endl;
	fout << "Trace = " << matr.getTrace() << "\n" << endl;
	for (int i = 0; i < matr.getDemension(); i++) {
		for (int j = 0; j < matr.getDemension(); j++) {
			fout << "\t" << matr.getMatr()[i][j];
		}
		fout << endl;
	}
	fout << "\n******************************************" << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Matrix &matr)
{
		int demension;
		fin >> demension;

		matr.m_demension = demension;
		matr.memoryAlloc();

		for (int i = 0; i < demension; ++i)
			for (int j = 0; j < demension; ++j)
				fin >> matr.m_matr[i][j];

		matr.m_determinant = calculateDeterminant(matr.m_matr, demension);
		matr.m_trace = calculateTrace(matr.m_matr, demension);

	return fin;
}

Matrix::~Matrix()
{
	cout << "Matrix Destructor start" << endl;
	for (int i = 0; i < m_demension; ++i)
		delete[] m_matr[i];
	delete[] m_matr;
}