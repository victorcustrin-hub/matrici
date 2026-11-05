#pragma once
#include <iostream>
using namespace std;

//1.1
int suma(int m[100][100], int c, int l) {
	int s = 0;

	for (int i = 0;i < c;i++) {
		s = s + m[l][i];
	}

	return s;
}

void linia_cu_suma_max(int m[100][100], int l, int c) {
	int s = 0;
	int max = -1;
	int poz = 0;

	for (int i = 0;i < l;i++) {
		s = suma(m, c, i);
		
		if (s > max) {
			max = s;
			poz = i;
		}
	}

	cout << "linia " << poz << " , suma " << max << endl;
}

void solutie_1() {
	cout << "TEST 1" << endl;
	int m1[100][100] = { {1,2,3},{4,6,8},{5,7,2} };
	int l1 = 3;
	int c1 = 3;
	linia_cu_suma_max(m1, l1, c1);
	cout << endl;

	cout << "TEST 2" << endl;
	int m2[100][100] = { {1,2},{3,0} };
	int l2 = 2;
	int c2 = 2;
	linia_cu_suma_max(m2, l2, c2);
	cout << endl;
}
//

//1.2
bool vf_coloana_monotona(int m[100][100], int l, int c) {

	bool crescator = true;
	bool descrescator = true;
	for (int i = 0;i < l - 1;i++) {

		if (m[i][c] < m[i + 1][c]) {
			crescator = false;
		}
		if (m[i][c] > m[i + 1][c]) {
			descrescator = false;
		}

	}

	return crescator || descrescator;
}

int coloane_ordonate(int m[100][100], int l, int c) {
	int ct = 0;

	for (int i = 0;i < c;i++) {
		if (vf_coloana_monotona(m, l, i)) {
			ct++;
		}
	}

	return ct;
}

void solutie_2() {
	cout << "TEST 1" << endl;
	int m1[100][100] = { {1,9,5},{2,7,5},{3,8,5} };
	int l1 = 3;
	int c1 = 3;
	cout<<coloane_ordonate(m1, l1, c1);
	cout << endl;

	cout << "TEST 2" << endl;
	int m2[100][100] = { {3,4},{2,5},{1,4} };
	int l2 = 3;
	int c2 = 2;
	cout<<coloane_ordonate(m2, l2, c2);
	cout << endl;

	cout << "TEST 3" << endl;
	int m3[100][100] = { {4,1,7} };
	int l3 = 1;
	int c3 = 3;
	cout << coloane_ordonate(m3, l3, c3);
	cout << endl;
}
//

//1.3
//functie ce afisaeaza elementul si elementul minim dintro matrice
void maxim_minim_matrice(int m[100][100], int l, int c,int &lmax,int&cmax,int&lmin,int&cmin) {
	int max = m[0][0];
	int min = m[0][0];

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (m[i][j] >= max) {
				max = m[i][j];
				lmax = i;
				cmax = j;
			}

			if (m[i][j] <= min) {
				min = m[i][j];
				lmin = i;
				cmin = j;
			}
		}
	}

}

void solutie_3() {
	cout << "TEST 1" << endl;
	int m1[100][100] = { {3,8},{5,1},{9,4} };
	int l1 = 3;
	int c1 = 2;
	int lmax1, cmax1, lmin1, cmin1 = 0;
	maxim_minim_matrice(m1, l1, c1, lmax1, cmax1, lmin1, cmin1);
	cout <<  abs((lmax1 - lmin1)) + abs((cmax1 - cmin1)) << endl;

	cout << "TEST 2" << endl;
	int m2[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int l2 = 3;
	int c2 = 3;
	int lmax2, cmax2, lmin2, cmin2 = 0;
	maxim_minim_matrice(m2, l2, c2, lmax2, cmax2, lmin2, cmin2);
	cout << abs((lmax2 - lmin2)) + abs((cmax2 - cmin2));
}
//


