#pragma once

void add(List &list);
void insert(List &list);
void print(List &list);
void remove(List &list);
void search(List &list);
void search(List &list, const int &position);
void filter(List &lsit, List &filtList);
void saveFile(List &list);
void readFile(List &list);

void readCommand(List &list, List &filtList);
void help();
void startProgram();