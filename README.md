# doubly-linked-matrix-training-project

Цель учебного проекта - создать двусвязный список в котором будут храниться объекты содержащие в себе квадратные матрицы NxN, их определитель, размерность и след матрицы; а так же реализовать перегрузку операторов, чтобы было удобно добавлять и удалять объекты класса(матрицы);

#### main.cpp - запуск программы
#### ioConsole.cpp - консольный интерфейс
#### List.cpp - класс двусвязного списка
#### Matrix.cpp - класс матрицы
#### Calculate.cpp - вычисление определителя и следа матрицы.

#### fileRead.txt - матрицу можно задать не только в консоли, но и через .txt файл. В этот файл можно записать матрицу, которую мы хотим считать и добавить в формате:
###### 1 строка - размерность матрицы
###### 2 ... (n + 1) строки - эл-ты матрицы, написанные через пробел. Каждая новая строка, это следующая строка матрицы.
