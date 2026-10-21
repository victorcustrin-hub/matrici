#pragma once
#include <iostream>
#include <iomanip>
using namespace std;



void afisare(int m[100][100],int l,int c) {

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

}

void afisareColoana(int m[100][100], int l, int x) {
	
	for (int i = 0;i < l;i++) {
		cout << m[i][x] << " ";
		cout << endl;
	 }
}




//FISA

//EXECRITIUL 1
//
int ex1a(int m[50][100], int l, int c) {
	int ct = 0;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (m[i][j] % 2 == 0 && i % 2 == 0 && j % 3 == 0) {
				ct++;
			}
		}
	}
	return ct;
}

void solutie1a() {
	//TEST 1 
	int m1[50][100] = { {4, 7, 16, 9, 11, 22},{13, 121, 5, 8, 25, 3},{6, 17, 33, 10, 2, 101},{49, 1, 44, 12, 7, 15} };
	int l1 = 4;
	int c1 = 6;
	cout << ex1a(m1, l1, c1) << endl;
	
	//TEST 2
	int m2[50][100] = { {-3, -10, -7, -9 },{-10, -2, -10, -8 },{ -11, -2, -12, -21 }};
	int l2 = 3;
	int c2 = 4;

	cout << ex1a(m2, l2, c2);

}
//

//
bool prim(int n) {
	if (n <= 1) {
		return false;
	}
	for (int k = 2;k <= n / 2;k++) {
		if (n % k == 0) {
			return false;
		}
	}
	return true;
}

void ex1b(int m[100][100], int l, int c) {
	int s = 0;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (prim(m[i][j]) && i % 2 == 0 && j % 2 != 0) {
				s = s + m[i][j];
			}
		}
	}
	cout << s;
}

void solutie1b() {
	//TEST 1 
	int m1[50][100] = { {4, 7, 16, 9, 11, 22},{13, 121, 5, 8, 25, 3},{6, 17, 33, 10, 2, 101},{49, 1, 44, 12, 7, 15} };
	int l1 = 4;
	int c1 = 6;
	ex1b(m1, l1, c1);
	cout << endl;

	//TEST 2
	int m2[50][100] = { {-3, -10, -7, -9 },{-10, -2, -10, -8 },{ -11, -2, -12, -21 } };
	int l2 = 3;
	int c2 = 4;

	ex1b(m2, l2, c2);

}
//

//
bool patrat_perfect(int n) {
	if (n < 0) {
		return false;
	}

	int x = round(sqrt(n));
	return(x * x == n);
}

int suma(int m[100][100], int c,int x) {
	int s = 0;
    
	for (int i = 0;i < c;i++) {
		s = s + m[x][i];
	}

	return s;
}

void ex1c(int m[100][100], int l, int c) {
	int s = 0;
	for (int i = 0;i < l;i++) {
		s = suma(m, c, i);
		for (int j = 0;j < c;j++) {
			if (patrat_perfect(m[i][j])) {
				m[i][j] = s;
			}
		}
	}

}

void solutie1c() {
	//TEST 1 
	int m1[50][100] = { {4, 7, 16, 9, 11, 22},{13, 121, 5, 8, 25, 3},{6, 17, 33, 10, 2, 101},{49, 1, 44, 12, 7, 15} };
	int l1 = 4;
	int c1 = 6;
	ex1c(m1, l1, c1);
	afisare(m1, l1, c1);
	cout << endl;

	//TEST 2
	int m2[50][100] = { {-3, -10, -7, -9 },{-10, -2, -10, -8 },{ -11, -2, -12, -21 } };
	int l2 = 3;
	int c2 = 4;

	ex1c(m2, l2, c2);
	afisare(m2, l2, c2);
}
//

//
int minim_pe_linie(int m[100][100], int c, int L) {
	int min = m[L][0];

	for (int i = 0;i < c;i++) {
		if (m[L][i] < min) {
			min = m[L][i];
		}
	}
	return min;
}

int maxim_pe_coloane(int m[100][100], int l, int C) {
	int max = m[0][C];

	for (int i = 0;i < l;i++) {
		if (m[i][C] > max) {
			max = m[i][C];
		}
	}
	return max;
}

void ex1d(int m[100][100], int l, int c, int L, int C) {
	int min = 0;
	int max = 0;
	
	int poz_min_i = 0;
	int poz_min_j = 0;
	int poz_max_i = 0;
	int poz_max_j = 0;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (i == L) {
				min = minim_pe_linie(m, j, L);
				poz_min_i = i;
				poz_min_j = j;
			}

			if (j == C) {
				max = maxim_pe_coloane(m, i, C);
				poz_max_i = i;
				poz_max_j = j;

			}
		}
	}

	int aux = m[poz_min_i][poz_min_j];
	m[poz_min_i][poz_min_j] = m[poz_max_i][poz_max_j];
	m[poz_max_i][poz_max_j] = aux;
}

void solutie1d() {
	//TEST 1 
	int m1[50][100] = { {4, 7, 16, 9, 11, 22},{13, 121, 5, 8, 25, 3},{6, 17, 33, 10, 2, 101},{49, 1, 44, 12, 7, 15} };
	int l1 = 4;
	int c1 = 6;
	
	int L1 = 1;
	int C1 = 2;

	ex1d(m1, l1, c1, L1, C1);
	afisare(m1, l1, c1);
	cout << endl;

	//TEST 2
	int m2[50][100] = { {-3, -10, -7, -9 },{-10, -2, -10, -8 },{ -11, -2, -12, -21 } };
	int l2 = 3;
	int c2 = 4;
	
	int L2 = 1;
	int C2 = 1;

	ex1d(m2, l2, c2, L2, C2);
	afisare(m2, l2, c2);
}
//

//
bool palindrom(int n) {
	if (n < 0) {
		return false;
	}

	int aux = n;
	int ogl = 0;

	while (aux != 0) {
		int cif = aux % 10;
		ogl = ogl * 10 + cif;
		aux = aux / 10;
	}

	return(ogl == n);
}

void ex1e(int m[100][100], int l, int c) {
	long long v[10000] = {};
	int ct = 0;

	for (int i = 0;i < c;i++) {
		for (int j = 0;j < l;j++) {
			if (palindrom(m[j][i])) {
				v[ct] = m[j][i];
				ct++;
			}
		}
	}

	if (ct == 0) {
		cout << "nu exista";
	}
	else {
		for (int i = 0;i < ct;i++) {
			cout << v[i] << " ";
		}
	}
}

void solutie1e() {
	//TEST 1 
	int m1[50][100] = { {4, 7, 16, 9, 11, 22},{13, 121, 5, 8, 25, 3},{6, 17, 33, 10, 2, 101},{49, 1, 44, 12, 7, 15} };
	int l1 = 4;
	int c1 = 6;
	ex1e(m1, l1, c1);
	cout << endl;

	//TEST 2
	int m2[50][100] = { {-3, -10, -7, -9 },{-10, -2, -10, -8 },{ -11, -2, -12, -21 } };
	int l2 = 3;
	int c2 = 4;

	ex1e(m2, l2, c2);
}
//

//
void ex1f(int m[100][100], int l, int c) {
	long max = -9999999;
	int s = 0;

	for (int i = 0;i < l;i++) {
		s = suma(m, c, i);
		cout << s << " ";
		if (s > max) {
			max = s;
		}
	}
	cout << endl;
	cout << "maxim: " << max << endl;
}

void solutie1f() {
	//TEST 1 
	int m1[50][100] = { {4, 7, 16, 9, 11, 22},{13, 121, 5, 8, 25, 3},{6, 17, 33, 10, 2, 101},{49, 1, 44, 12, 7, 15} };
	int l1 = 4;
	int c1 = 6;
	ex1f(m1, l1, c1);
	cout << endl;

	//TEST 2
	int m2[50][100] = { {-3, -10, -7, -9 },{-10, -2, -10, -8 },{ -11, -2, -12, -21 } };
	int l2 = 3;
	int c2 = 4;

	ex1f(m2, l2, c2);
}
//

//
int nr_cif_binare(int n) {
	int ct = 0;

	while (n != 0) {
		int cif = n % 10;
		if (cif == 0 || cif == 1) {
			ct++;
		}
		n = n / 10;
	}

	return ct;
}

void ex1g(int m[100][100], int l, int c) {
	int ct = 0;
	long max = -999999;
	int linie_rez = 0;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			ct = nr_cif_binare(m[i][j]);
			if (ct > max) {
				linie_rez = i;
				max = ct;
			}
		}
	}
	int s = suma(m,c,linie_rez);
	double medie = double(s) / c;
	cout << "linia " << linie_rez << ": " << fixed << setprecision(2) << medie;

}

void solutie1g() {
	//TEST 1 
	int m1[50][100] = { {4, 7, 16, 9, 11, 22},{13, 121, 5, 8, 25, 3},{6, 17, 33, 10, 2, 101},{49, 1, 44, 12, 7, 15} };
	int l1 = 4;
	int c1 = 6;
	ex1g(m1, l1, c1);
	cout << endl;

	//TEST 2
	int m2[50][100] = { {-3, -10, -7, -9 },{-10, -2, -10, -8 },{ -11, -2, -12, -21 } };
	int l2 = 3;
	int c2 = 4;

	ex1g(m2, l2, c2);
}
//

//EXERCITIUL 2
//
int cif_min(int n) {
	int min = 10;

	while (n != 0) {
		int cif = n % 10;
		if (cif < min) {
			min = cif;
		}
		n = n / 10;
	}
	return min;
}

void ex2a(int m[20][1000], int l, int c) {
	int max = -1;
	int rez = 0;

	for (int i = 0;i < l;i++) {
		max = 0;
		for (int j = 0;j < c;j++) {
			if (m[i][j] > max) {
				max = m[i][j];
			}
		}
		rez = rez * 10 + cif_min(max);
	}
	cout << rez;
}

void solutie2a() {
	//TEST 1 
	int m1[20][1000] = { {12, 30, 45, 18},{121, 46, 64, 121},{13, 31, 20, 102},{8, 121, 24, 74} };
	int l1 = 4;
	int c1 = 4;
	ex2a(m1, l1, c1);
	cout << endl;

	//TEST 2
	int m2[20][1000] = { {101, 7, 3, 2},{0, 11, 0, 5},{5, 13, 4, 1},{0, 9, 0, 9} };
	int l2 = 4;
	int c2 = 4;
	ex2a(m2, l2, c2);
}
//

//
int divizori_proprii(int n) {
	if (n <= 1) {
		return 0;
	}
	int ct = 0;
	for (int i = 2;i * i <= n;i++) {
		if (n % i == 0) {
			if (i * i == n) {
				ct++;
			}
			else {
				ct += 2;
			}
		}
	}
	return ct;
}

void ex2b(int m[20][1000], int l, int c) {
	double s = 0;
	int ct = 0;
	bool vf = 0;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			int aux = divizori_proprii(m[i][j]);
			if (aux >= 3 && aux <= 5) {
				s = s + m[i][j];
				ct++;
				vf = 1;
			}
		}
	}

	if (vf) {
		double rez = s / ct;
		cout << fixed << setprecision(2) << rez;
	}
	else {
		cout << "nu exista";
	}
}

void solutie2b() {
	//TEST 1 
	int m1[20][1000] = { {12, 30, 45, 18},{121, 46, 64, 121},{13, 31, 20, 102},{8, 121, 24, 74} };
	int l1 = 4;
	int c1 = 4;
	ex2b(m1, l1, c1);
	cout << endl;

	//TEST 2
	int m2[20][1000] = { {101, 7, 3, 2},{0, 11, 0, 5},{5, 13, 4, 1},{0, 9, 0, 9} };
	int l2 = 4;
	int c2 = 4;
	ex2b(m2, l2, c2);
}
//

//
bool palindrom_intre_ele(int a, int b) {
	int ogl = 0;

	while (a != 0) {
		int cif = a % 10;
		ogl = ogl * 10 + cif;
		a = a / 10;
	}

	return(ogl == b);
}

void ex2c(int m[20][1000], int l, int c, int L) {
	bool vf = 0;

	for (int i = 0;i < c - 1;i++) {
		for (int j = i + 1;j < c;j++) {
			if (palindrom_intre_ele(m[L][i], m[L][j])) {
				cout << m[L][i] << " " << m[L][j] << endl;
				vf = 1;
			}
		}
	}

	if (!vf) {
		cout << "Nu exista"<<endl;
	}
}

void solutie2c() {
	//TEST 1 
	int m1[20][1000] = { {12, 30, 45, 18},{121, 46, 64, 121},{13, 31, 20, 102},{8, 121, 24, 74} };
	int l1 = 4;
	int c1 = 4;
	int L1 = 1;
	ex2c(m1, l1, c1, L1);
	cout << endl;

	//TEST 2
	int m2[20][1000] = { {101, 7, 3, 2},{0, 11, 0, 5},{5, 13, 4, 1},{0, 9, 0, 9} };
	int l2 = 4;
	int c2 = 4;
	int L2 = 0;
	ex2c(m2, l2, c2, L2);
}
//

//
int cif_control(int n) {
	while (n > 9) {
		int s = 0;
		while (n != 0) {
			int cif = n % 10;
			s = s + cif;
			n = n / 10;
		}
		n = s;
	}
	return n;
}

void ex2d(int m[20][1000], int l, int c) {
	l--;
	c--;

	int rez = cif_control(m[l][c]);
	cout << rez;
}

void solutie2d() {
	//TEST 1 
	int m1[20][1000] = { {12, 30, 45, 18},{121, 46, 64, 121},{13, 31, 20, 102},{8, 121, 24, 74} };
	int l1 = 4;
	int c1 = 4;
	ex2d(m1, l1, c1);
	cout << endl;

	//TEST 2
	int m2[20][1000] = { {101, 7, 3, 2},{0, 11, 0, 5},{5, 13, 4, 1},{0, 9, 0, 9} };
	int l2 = 4;
	int c2 = 4;
	ex2d(m2, l2, c2);
}
//