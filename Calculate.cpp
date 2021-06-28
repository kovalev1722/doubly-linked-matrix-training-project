#include <iostream>

using namespace std;

// Получение матрицы без i-й строки и j-го столбца
void getDetMatr(float **matr, float **p, const int &i, const int &j, const int &demension)
{
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki < demension - 1; ki++) { // проверка индекса строки
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < demension - 1; kj++) { // проверка индекса столбца
			if (kj == j) dj = 1;
			p[ki][kj] = matr[ki + di][kj + dj];
		}
	}
}

// Рекурсивное вычисление определителя
float calculateDeterminant(float **matr, const int &demension)
{
	int i, j, k, n;
	float det;

	float **p = new float*[demension];

	for (i = 0; i < demension; i++)
		p[i] = new float[demension];

	j = 0; det = 0;
	k = 1; //(-1) в степени i
	n = demension - 1;

	if (demension == 1) {
		det = matr[0][0];
		return(det);
	}
	if (demension == 2) {
		det = matr[0][0] * matr[1][1] - (matr[1][0] * matr[0][1]);
		return(det);
	}
	if (demension > 2) {
		for (i = 0; i < demension; i++) {
			getDetMatr(matr, p, i, 0, demension);
			det = det + k * matr[i][0] * calculateDeterminant(p, n);
			k = -k;
		}
	}
	return(det);
}

float calculateTrace(float **matr, const int &demension)
{

	float trace(0);
	for (int i = 0; i < demension; i++) {
		for (int j = 0; j < demension; j++) {
			if (j == i)
				trace += matr[i][j];
		}
	}
	return trace;
}