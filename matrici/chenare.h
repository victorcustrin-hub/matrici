#pragma once
#include <iostream>
using namespace std;

//       0  1  2  3

// 0    00 01 02 03
// 1    10 11 12 13
// 2    20 21 22 23
// 3    30 31 32 33
// 4    40 41 42 43

void afisare_chenar(int a[100][100], int n, int m,int k) {
	
	int i1 = k;
	int j1 = k;

	int i2 = n - 1 - k;
	int j2 = m - 1 - k;

	for (int j = j1;j <= j2;j++) {
		cout << a[i1][j] << " ";
	}
	cout << endl;

	for (int i = i1 + 1;i <= i2;i++) {
		cout << a[i][j2] << " ";
	}
	cout << endl;

	for (int j = j2 - 1;j >= j1;j--) {
		cout << a[i2][j] << " ";
	}
	cout << endl;

	for (int i = i2 - 1;i >= i1 + 1;i--) {
		cout << a[i][j1]<<" ";
	}
}
//


//      0   1  2

// 0    00 01 02 
// 1    10 11 12
// 2    20 21 22
// 3    30 31 32
// 4    40 41 42


//3.1
int elemente_chenar(int n, int m, int k) {
	int i1 = k;
	int j1 = k;
	int i2 = n - 1 - k;
	int j2 = m - 1 - k;
	int ct = 0;

	for (int j = j1;j <= j2;j++) {
		ct++;
	}
	for (int i = i1 + 1;i <= i2;i++) {
		ct++;
	}
	for (int j = j2 - 1;j >= j1;j--) {
		ct++;
	}
	for (int i = i2 - 1;i >= i1 + 1;i--) {
		ct++;
	}

	return ct;
}

int nr_chenare(int l, int c) {
	int min = l;

	if (c < min) {
		min = c;
	}

	return (min + 1) / 2;
}

int nr_elemente_chenare(int n, int m) {
	int k = 0;
	int ct = 0;
	int nr = nr_chenare(n, m);

	while (k < nr) {
		ct = elemente_chenar(n, m, k);
		cout << "Chenar " << k << ": " << ct << endl;
		k++;
	}

	return ct;
}

void solutie_1() {
	int n = 5;
	int m = 3;

	cout << nr_elemente_chenare(n, m);
}
//


//3.2
int suma_chenar(int a[100][100], int n, int m, int k) {
	int i1 = k;
	int j1 = k;
	int i2 = n - 1 - k;
	int j2 = m - 1 - k;

	int s = 0;

	for (int j = j1;j <= j2;j++) {
		s = s + a[i1][j];
	}
	for (int i = i1 + 1;i <= i2;i++) {
		s = s + a[i][j2];
	}
	for (int j = j2 - 1;j >= j1;j--) {
		s = s + a[i2][j];
	}
	for (int i = i2 - 1;i >= i1 + 1;i--) {
		s = s + a[i][j1];
	}

	return s;
}

void solutie_2() {
	int a[100][100] ={{1, 2,  3, 4},
		              {5, 6,  7, 8},
		              {9, 10,11,12},
		              {13,14,15,16},
		              {17,18,19,20} };
	int l = 5;
	int c = 4;
	int k = 2;

	int r = suma_chenar(a, l, c, k);
	if (k < nr_chenare(l,c)) {
		cout << r << endl;
	}
	else {
		cout << "NU EXISTA" << endl;
	}
}
//