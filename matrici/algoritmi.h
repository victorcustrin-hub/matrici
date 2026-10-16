#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void citire(int a[][1000], int& n, int& m) {
	ifstream fin("matrice.in");
	fin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			fin >> a[i][j];
		}
	}
}

void afisare(int a[][1000], int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
