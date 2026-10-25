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
	n = abs(n);
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
	cout << "TEST 1:" << endl;
	int m1[20][1000] = { {12, 30, 45, 18},{121, 46, 64, 121},{13, 31, 20, 102},{8, 121, 24, 74} };
	int l1 = 4;
	int c1 = 4;
	ex2d(m1, l1, c1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[20][1000] = { {101, 7, 3, 2},{0, 11, 0, 5},{5, 13, 4, 1},{0, 9, 0, 9} };
	int l2 = 4;
	int c2 = 4;
	ex2d(m2, l2, c2);
}
//
//
void ex2e_si_f(int m[100][100], int l, int c) {
	//
	int f[10]{};

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (i % 2 != 0 && j % 2 == 0) {
				int aux = abs(m[i][j]);
				if (aux == 0) {
					f[0]++;
				}
				else {
					while (aux != 0) {
						int cif = aux % 10;
						f[cif]++;
						aux = aux / 10;
					}
				}
			}
		}
	}
	cout << "e) " << endl;
	for (int i = 0;i < 10;i++) {
		if (f[i] != 0) {
			cout << i << ":" << f[i] << endl;
		}
	}
	//
	cout << endl;
	//
	cout << "f) ";
	bool vf = 0;
	for (int i = 9;i >= 1;i--) {
		while (f[i] != 0) {
			cout << i;
			f[i]--;
			vf = 1;
		}
	}
	if (vf) {
		while (f[0] != 0) {
			cout << 0;
			f[0]--;
		}
	}
	else if (f[0] > 0) {
		cout << 0;
	}
	cout << endl;

}

void solutie2_e_si_f() {
	//TEST 1 
	int m1[100][100] = { {12, 30, 45, 18},{121, 46, 64, 121},{13, 31, 20, 102},{8, 121, 24, 74} };
	int l1 = 4;
	int c1 = 4;
	cout << "TEST 1" << endl;
	ex2e_si_f(m1, l1, c1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {101, 7, 3, 2},{0, 11, 0, 5},{5, 13, 4, 1},{0, 9, 0, 9} };
	int l2 = 4;
	int c2 = 4;
	ex2e_si_f(m2, l2, c2);
}
//

//
void ex2g(int m[100][100], int l, int c) {
	int f[10]{};

	for (int i = 1;i < l - 1;i++) {
		for (int j = 1;j < c - 1;j++) {
			int aux = abs(m[i][j]);
			if (aux == 0) {
				f[0]++;
			}
			else {
				while (aux != 0) {
					int cif = aux % 10;
					f[cif]++;
					aux = aux / 10;
				}
			}

		}
	}

	for (int i = 0;i < 10;i++) {
		if (f[i] == 0) {
			cout << i;
		}
	}

}

void solutie2g() {
	//TEST 1 
	int m1[100][100] = { {12, 30, 45, 18},{121, 46, 64, 121},{13, 31, 20, 102},{8, 121, 24, 74} };
	int l1 = 4;
	int c1 = 4;
	cout << "TEST 1" << endl;
	ex2g(m1, l1, c1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {101, 7, 3, 2},{0, 11, 0, 5},{5, 13, 4, 1},{0, 9, 0, 9} };
	int l2 = 4;
	int c2 = 4;
	ex2g(m2, l2, c2);
}
//

//
void ex2h(int m[100][100], int l, int c, int k, int y) {
	int ct = 0;
	int vf = 0;

	for (int i = 0;i < l && vf == 0;i++) {
		for (int j = 0;j < c;j++) {
			if (m[i][j] == y) {
				ct++;
			}

			if (ct == k) {
				cout << "linia " << i << ", coloana " << j << endl;
				vf = 1;
				break;
			}

		}
	}

	if (!vf) {
		cout << "Nu exista";
	}

}

void solutie2h() {
	//TEST 1 
	int m1[100][100] = { {12, 30, 45, 18},{121, 46, 64, 121},{13, 31, 20, 102},{8, 121, 24, 74} };
	int l1 = 4;
	int c1 = 4;
	int k1 = 2;
	int y1 = 121;
	cout << "TEST 1" << endl;
	ex2h(m1, l1, c1, k1, y1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {101, 7, 3, 2},{0, 11, 0, 5},{5, 13, 4, 1},{0, 9, 0, 9} };
	int l2 = 4;
	int c2 = 4;
	int k2 = 3;
	int y2 = 9;
	ex2h(m2, l2, c2, k2, y2);
}
//
void ex2i_si_j(int m[100][100], int l, int c, int col, int k) {
	bool vf = true;
	bool vf2 = 0;
	do {
		vf = true;
		for (int i = 0;i < l - 1;i++) {
			if (m[i][col] > m[i + 1][col]) {
				int aux = m[i][col];
				m[i][col] = m[i + 1][col];
				m[i + 1][col] = aux;
				vf = false;
			}
		}

	} while (vf == false);

	cout << "i) " << endl;
	afisare(m, l, c);
	cout << endl;
	cout << "j) " << endl;

	for (int i = 0;i < l;i++) {
		if (m[i][col] == k) {
			cout << "linia " << i;
			vf2 = 1;
		}
	}
	if (!vf2) {
		cout << "Nu exista";
	}
}

void solutie2_i_si_j() {
	//TEST 1 
	int m1[100][100] = { {12, 30, 45, 18},{121, 46, 64, 121},{13, 31, 20, 102},{8, 121, 24, 74} };
	int l1 = 4;
	int c1 = 4;
	int k1 = 18;
	int col1 = c1 - 1;
	cout << "TEST 1" << endl;
	ex2i_si_j(m1, l1, c1, col1, k1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {101, 7, 3, 2},{0, 11, 0, 5},{5, 13, 4, 1},{0, 9, 0, 9} };
	int l2 = 4;
	int c2 = 4;
	int k2 = 0;
	int col2 = c2 - 1;
	ex2i_si_j(m2, l2, c2, col2, k2);
}

//

//EXERCOTIUL 3
//
void ex3a(int m[100][100], int l, int c) {
	bool vf = true;

	do {
		vf = true;
		for (int i = 0;i < l - 1;i++) {
			if (m[i][0] > m[i + 1][0]) {
				for (int j = 0;j < c;j++) {
					int aux = m[i][j];
					m[i][j] = m[i + 1][j];
					m[i + 1][j] = aux;
				}
				vf = false;
			}
		}

	} while (vf == false);

	afisare(m, l, c);
}

void solutie3a() {
	//TEST 1 
	int m1[100][100] = { {12, 233, 8, 233, 12},{7, 10, 101, 52, 4},{3, 23, 39, 32, 3},{29, 11, 1, 11, 29} };
	int l1 = 4;
	int c1 = 5;
	cout << "TEST 1" << endl;
	ex3a(m1, l1, c1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {10},{-13},{1},{31} };
	int l2 = 4;
	int c2 = 1;
	ex3a(m2, l2, c2);
}
// 

//
bool vfBinar(int n) {
	bool vf = 1;
	if (n == 0) {
		return true;
	}

	while (n != 0) {
		int cif = n % 10;
		if (cif > 1) {
			return false;
		}
		n = n / 10;
	}
	return true;
}

void ex3b(int m[100][100], int l, int c) {
	int ct = 0;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (vfBinar(abs(m[i][j]))) {
				ct++;
			}
		}
	}

	cout << ct;

}

void solutie3b() {
	//TEST 1 
	int m1[100][100] = { {12, 233, 8, 233, 12},{7, 10, 101, 52, 4},{3, 23, 39, 32, 3},{29, 11, 1, 11, 29} };
	int l1 = 4;
	int c1 = 5;
	cout << "TEST 1" << endl;
	ex3b(m1, l1, c1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {10},{-13},{1},{31} };
	int l2 = 4;
	int c2 = 1;
	ex3b(m2, l2, c2);
}
//

//??
bool superprim(int n) {
	if (n <= 1) {
		return false;
	}

	while (n > 0) {
		if (prim(n) == false) {
			return false;
		}
		n = n / 10;
	}
	return true;
}

void ex3c(int m[100][100], int l, int c) {

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (superprim(m[i][j])) {
				cout << m[i][j] << " ";
			}
		}
	}

}

void solutie3c() {
	//TEST 1 
	int m1[100][100] = { {12, 233, 8, 233, 12},{7, 10, 101, 52, 4},{3, 23, 39, 32, 3},{29, 11, 1, 11, 29} };
	int l1 = 4;
	int c1 = 5;
	cout << "TEST 1" << endl;
	ex3c(m1, l1, c1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {10},{-13},{1},{31} };
	int l2 = 4;
	int c2 = 1;
	ex3c(m2, l2, c2);
}
//

//
void ex3d(int m[100][100], int l, int c) {

	for (int i = 0;i < l;i++) {
		if (i % 2 == 0) {
			for (int j = 0;j < c;j++) {
				cout << m[i][j] << " ";
			}
		}
		else {
			for (int j = c - 1;j >= 0;j--) {
				cout << m[i][j] << " ";
			}
		}
	}

}

void solutie3d() {
	//TEST 1 
	int m1[100][100] = { {12, 233, 8, 233, 12},{7, 10, 101, 52, 4},{3, 23, 39, 32, 3},{29, 11, 1, 11, 29} };
	int l1 = 4;
	int c1 = 5;
	cout << "TEST 1" << endl;
	ex3d(m1, l1, c1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {10},{-13},{1},{31} };
	int l2 = 4;
	int c2 = 1;
	ex3d(m2, l2, c2);
}
//

//??
void ex3e(int m[100][100], int l, int c) {
	int ct = 0;

	for (int i = 0;i < l;i++) {
		int st = 0;
		int dr = c - 1;
		bool vf = true;
		do {
			if (m[i][st] != m[i][dr]) {
				vf = false;
			}
			st++;
			dr--;
		} while (vf == true && st < dr);

		if (vf == true) {
			ct++;
		}
	}
	cout << ct << endl;
}

void solutie3e() {
	//TEST 1 
	int m1[100][100] = { {12, 233, 8, 233, 12},{7, 10, 101, 52, 4},{3, 23, 39, 32, 3},{29, 11, 1, 11, 29} };
	int l1 = 4;
	int c1 = 5;
	cout << "TEST 1" << endl;
	ex3e(m1, l1, c1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {10},{-13},{1},{31} };
	int l2 = 4;
	int c2 = 1;
	ex3e(m2, l2, c2);
}
//

//??
int oglindit(int n) {
	int ogl = 0;
	n = abs(n);
	while (n != 0) {
		int cif = n % 10;
		ogl = ogl * 10 + cif;
		n = n / 10;
	}
	return ogl;
}

int cmmdc(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void ex3f(int m[100][100], int l, int c) {
	bool vf = true;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			int aux = m[i][j];
			int ogl = oglindit(aux);

			if (cmmdc(aux, ogl) != 1) {
				vf = false;
				break;
			}
		}
		if (!vf) {
			break;
		}
	}

	if (vf) {
		cout << "DA" << endl;
	}
	else {
		cout << "NU" << endl;
	}
}

void solutie3f() {
	//TEST 1 
	int m1[100][100] = { {12, 233, 8, 233, 12},{7, 10, 101, 52, 4},{3, 23, 39, 32, 3},{29, 11, 1, 11, 29} };
	int l1 = 4;
	int c1 = 5;
	cout << "TEST 1" << endl;
	ex3f(m1, l1, c1);
	cout << endl;

	//TEST 2
	cout << "TEST 2" << endl;
	int m2[100][100] = { {10},{-13},{1},{31} };
	int l2 = 4;
	int c2 = 1;
	ex3f(m2, l2, c2);
}
//