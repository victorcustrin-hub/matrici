#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

//7 12 - 5 23 2           00 01 02 03 04          i+j=4  j=4-i
//4 31 19 - 8 37          10 11 12 13 14
//0 6 11 73 29            20 21 22 23 24
//- 2 233 15 5 44         30 31 32 33 34
//9 - 6 71 317 13         40 41 42 43 44

// diagonala sec: 04 13 22 31 40  => i+j==n-1
int sumaElementelorDePeDiagonalaPrincipala(int m[100][100], int n) {
	int s = 0;

	for (int i = 0;i < n;i++) {
		s = s + m[i][n-1 - i];
	}
	return s;
}

void solutie1a() {
	//TEST 1
	int m1[100][100] = { {7,12,-5,23,2}, {4,31,19,-8,37},{0,6,11,73,29},{-2,233,15,5,44},{9, -6,71,317,13} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	cout<<sumaElementelorDePeDiagonalaPrincipala(m1,n1);
	cout << endl;

	int m2[100][100] = { { -5,0, -12, 8},{-3, -7, 4, -10},{-9, 2, 0, -1},{ 6, -4, -8, -2 } };
    int n2 = 4;
	cout << "TEST 2" << endl;
	cout<<sumaElementelorDePeDiagonalaPrincipala(m2, n2);
}
//

//7 12 - 5 23 2           00 01 02 03 04        
//4 31 19 - 8 37             11 12 13 14
//0 6 11 73 29                   22 23 24
//- 2 233 15 5 44                   33 34
//9 - 6 71 317 13                       44

// j>i


//i      i<5        j      j<5      af          j
//0      0<5        1      1<5      01          2
//                         2<5      02          3
//                         3<5      03          4
//                         4<5      04          5
//                         5<5 
// 
// 1    1<5       2,5
// 2    2<5       3,5
// 
// 
//   
int sumaDeasupraDiagonaleiPrincipale(int m[100][100],int n) {
	int s = 0;
	
	/*for (int i = 0;i < n;i++) {
		for (int j =0;j < n;j++) {
			if (i < j) {
				s += m[i][j];
			}
		}
	 }*/

	for (int i = 0;i < n;i++) {
		for (int j = i+1;j < n;j++) {
			s += m[i][j];
		}
	}

	return s;
}

void solutie1b() {
	//TEST 1
	int m1[100][100] = { {7,12,-5,23,2}, {4,31,19,-8,37},{0,6,11,73,29},{-2,233,15,5,44},{9, -6,71,317,13} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	cout << sumaDeasupraDiagonaleiPrincipale(m1, n1);
	cout << endl;

	int m2[100][100] = { { -5,0, -12, 8},{-3, -7, 4, -10},{-9, 2, 0, -1},{ 6, -4, -8, -2 } };
	int n2 = 4;
	cout << "TEST 2" << endl;
	cout << sumaDeasupraDiagonaleiPrincipale(m2, n2);
}
//

//
//7 12 - 5 23 2           00 01 02 03 04       
//4 31 19 - 8 37          10 11 12 13 14
//0 6 11 73 29            20 21 22 23 24
//- 2 233 15 5 44         30 31 32 33 34
//9 - 6 71 317 13         40 41 42 43 44

void sortare_diagonala_principala_descrescator(int m[100][100], int n) {
	bool sortat = true;

	do {
		sortat = true;
		for (int i = 0;i < n - 1;i++) {
			int x = i + 1;
			if (m[x][x] > m[i][i]) {
				int aux = m[x][x];
				m[x][x] = m[i][i];
				m[i][i] = aux;
				sortat = false;
			}
		}

	} while (sortat == false);

}

//
//7 12 - 5 23 2           00 01 02 03 04       diagonala principala   
//4 31 19 - 8 37          10 11 12 13 14         00 11 22 33 44 i==j
//0 6 11 73 29            20 21 22 23 24
//- 2 233 15 5 44         30 31 32 33 34
//9 - 6 71 317 13         40 41 42 43 44
void afisare_diag_principala(int m[100][100], int n) {

	for (int i = 0;i < n;i++) {
		cout << m[i][i] << " ";
	}

}

void solutie1c() {
	//TEST 1
	int m1[100][100] = { {7,12,-5,23,2}, {4,31,19,-8,37},{0,6,11,73,29},{-2,233,15,5,44},{9, -6,71,317,13} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	sortare_diagonala_principala_descrescator(m1, n1);
	afisare_diag_principala(m1, n1);
	cout << endl;

	int m2[100][100] = { { -5,0, -12, 8},{-3, -7, 4, -10},{-9, 2, 0, -1},{ 6, -4, -8, -2 } };
	int n2 = 4;
	cout << "TEST 2" << endl;
	sortare_diagonala_principala_descrescator(m2, n2);
	afisare_diag_principala(m2, n2);
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
//7 12 - 5 23 2                       04         
//4 31 19 - 8 37                   13 14        i+j>n-1
//0 6 11 73 29                  22 23 24
//- 2 233 15 5 44            31 32 33 34
//9 - 6 71 317 13         40 41 42 43 44
int ct_elemente_superprime_sub_siagonala_secundara(int m[100][100],int n){
	int ct = 0;

	for (int i = 1;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i + j > n - 1) {
				if (superprim(m[i][j])) {
					ct++;
				}
			}
		}
	}

	return ct;
}

void solutie1d() {
	//TEST 1
	int m1[100][100] = { {7,12,-5,23,2}, {4,31,19,-8,37},{0,6,11,73,29},{-2,233,15,5,44},{9, -6,71,317,13} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	cout<<ct_elemente_superprime_sub_siagonala_secundara(m1, n1);
	cout << endl;

	int m2[100][100] = { { -5,0, -12, 8},{-3, -7, 4, -10},{-9, 2, 0, -1},{ 6, -4, -8, -2 } };
	int n2 = 4;
	cout << "TEST 2" << endl;
	cout<<ct_elemente_superprime_sub_siagonala_secundara(m2, n2);
	
}
//

//
//7 12 - 5 23 2           00 01 02 03 04       
//4 31 19 - 8 37          10 11 12 13
//0 6 11 73 29            20 21 22
//- 2 233 15 5 44         30 31
//9 - 6 71 317 13         40

//j<n-1(cu fiecare line scade n)
int suma_elem_deasupra_diag_secundare(int m[100][100], int n) {
	int s = 0;
	int aux = n - 1;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < aux;j++) {
			s = s + m[i][j];
		}
		aux--;
	}

	return s;

}

void solutie1e() {
	//TEST 1
	int m1[100][100] = { {7,12,-5,23,2}, {4,31,19,-8,37},{0,6,11,73,29},{-2,233,15,5,44},{9, -6,71,317,13} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	cout << suma_elem_deasupra_diag_secundare(m1, n1);
	cout << endl;

	int m2[100][100] = { { -5,0, -12, 8},{-3, -7, 4, -10},{-9, 2, 0, -1},{ 6, -4, -8, -2 } };
	int n2 = 4;
	cout << "TEST 2" << endl;
	cout << suma_elem_deasupra_diag_secundare(m2, n2);

}
//
 
//
//7 12 - 5 23 2           00 01 02 03 04   
//4 31 19 - 8 37             11 12 13        
//0 6 11 73 29                  22
//- 2 233 15 5 44         
//9 - 6 71 317 13      
// 

//deasupra diag principala+deasupra diag secundara => 01,02,03,12,  => i<j && i+j < n-1
void medie_aritm_regiune_nord(int m[100][100], int n) {
	int s = 0;
	int ct = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i < j && i + j < n - 1) {
				s = s + m[i][j];
				ct++;
			}
		}
	}

	double medie = (double)s / ct;
	cout << fixed << setprecision(2) << medie << endl;
}

void solutie1f() {
	//TEST 1
	int m1[100][100] = { {7,12,-5,23,2}, {4,31,19,-8,37},{0,6,11,73,29},{-2,233,15,5,44},{9, -6,71,317,13} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	medie_aritm_regiune_nord(m1, n1);
	cout << endl;

	int m2[100][100] = { { -5,0, -12, 8},{-3, -7, 4, -10},{-9, 2, 0, -1},{ 6, -4, -8, -2 } };
	int n2 = 4;
	cout << "TEST 2" << endl;
	medie_aritm_regiune_nord(m2, n2);

}
//

//

//7 12 - 5 23 2            
//4 31 19 - 8 37          
//0 6 11 73 29                  22
//- 2 233 15 5 44            31 32 33
//9 - 6 71 317 13         40 41 42 43 44

//elemente sub diag principala+sub diag secundara => i > j && i+j > n-1
int ct_elem_negative_regiune_sud(int m[100][100], int n) {
	int ct = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i > j && i + j > n-1 && m[i][j]<0) {
				ct++;
			}
		}
	}

	return ct;
}

void solutie1g() {
	//TEST 1
	int m1[100][100] = { {7,12,-5,23,2}, {4,31,19,-8,37},{0,6,11,73,29},{-2,233,15,5,44},{9, -6,71,317,13} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	cout << ct_elem_negative_regiune_sud(m1, n1);
	cout << endl;

	int m2[100][100] = { { -5,0, -12, 8},{-3, -7, 4, -10},{-9, 2, 0, -1},{ 6, -4, -8, -2 } };
	int n2 = 4;
	cout << "TEST 2" << endl;
	cout << ct_elem_negative_regiune_sud(m2, n2);

}
//

//
//7 12 - 5 23 2                       04       
//4 31 19 - 8 37                   13 14
//0 6 11 73 29                  22 23 24
//- 2 233 15 5 44                  33 34
//9 - 6 71 317 13                     44

//elem regiune est: 14,23,24,34 => deasupra diag principale, sub diag secundara => i<j && i+j > n-1
int ct_elem_pare_regiune_est(int m[100][100], int n) {
	int ct = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i < j && i + j > n - 1 && m[i][j] % 2 == 0) {
				ct++;
			}
		}
	}

	return ct;
}

void solutie1h() {
	//TEST 1
	int m1[100][100] = { {7,12,-5,23,2}, {4,31,19,-8,37},{0,6,11,73,29},{-2,233,15,5,44},{9, -6,71,317,13} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	cout << ct_elem_pare_regiune_est(m1, n1);
	cout << endl;

	int m2[100][100] = { { -5,0, -12, 8},{-3, -7, 4, -10},{-9, 2, 0, -1},{ 6, -4, -8, -2 } };
	int n2 = 4;
	cout << "TEST 2" << endl;
	cout << ct_elem_pare_regiune_est(m2, n2);

}
//

//

//7  12 -5  23 2         00  
//4  31 19 -8 37         10 11      
//0   6 11 73 29         20 21 22
//-2 233 15 5 44         30 31
//9 -6 71 317 13         40


//10,20,21,30 => elemente sub diag principala+deasupra diag secundara => i>j && i+j<n-1
int element_maxim_vest(int m[100][100], int n) {
	int max = m[1][0];

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i > j && i + j < n - 1) {
				if (m[i][j] > max) {
					max = m[i][j];
				}
			}
		}
	}

	return max;
}

void solutie1i() {
	//TEST 1
	int m1[100][100] = { {7,12,-5,23,2}, {4,31,19,-8,37},{0,6,11,73,29},{-2,233,15,5,44},{9, -6,71,317,13} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	cout << element_maxim_vest(m1, n1);
	cout << endl;

	int m2[100][100] = { { -5,0, -12, 8},{-3, -7, 4, -10},{-9, 2, 0, -1},{ 6, -4, -8, -2 } };
	int n2 = 4;
	cout << "TEST 2" << endl;
	cout << element_maxim_vest(m2, n2);

}
//

//00 01 02 03 04
//10 11 12 13 14
//20 21 22 23 24
//30 31 32 33 34
//40 41 42 43 44


//PROBLEMA 2

// 12 47 121 7 4
//40 18 303 9 35
//5 88 60 1331 70
//15 16 47 48 7
//32 11 7 47 96

//00 01 02 03 04
//10 11 12 13 14
//20 21 22 23 24
//30 31 32 33 34
//40 41 42 43 44


//diag principala => linie si coloana egale i==j
int cmmdc_diag_principala(int m[100][100], int n) {
	int rez = abs(m[0][0]);

	for (int i = 1;i < n;i++) {
		int a = rez;
		int b = abs(m[i][i]);

		while (b != 0) {
			int r = a % b;
			a = b;
			b = r;
		}

		rez = a;
	}

	return rez;

}

void solutie2a() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	cout << cmmdc_diag_principala(m1, n1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;
	cout << "TEST 2" << endl;
	cout << cmmdc_diag_principala(m2, n2);

}
//

//

// 12 47 121 7 4
//40 18 303 9 35
//5 88 60 1331 70
//15 16 47 48 7
//32 11 7 47 96

//00 01 02 03 04
//10 11 12 13 14
//20 21 22 23 24
//30 31 32 33 34
//40 41 42 43 44

//conditie: m[i][j] == m[j][i]
void vf_simetrie_diagonala_principala(int m[100][100], int n) {
	bool vf = 1;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (m[i][j] != m[j][i]) {
				vf = false;
			}
		}
	}

	if (vf) {
		cout << "DA" << endl;
	}
	else {
		cout << "NU" << endl;
	}

}

void solutie2b() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	vf_simetrie_diagonala_principala(m1, n1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;
	cout << "TEST 2" << endl;
	vf_simetrie_diagonala_principala(m2, n2);

}
//

//
bool prim_egal_ultim(int n) {
	n = abs(n);
	int cif = n % 10;

	while (n > 9) {
		n = n / 10;
	}

	return(cif == n);
}

void ct_numere_cu_cifrele_de_la_margine_egale(int m[100][100], int n) {
	int ctN = 0;
	int ctS = 0;
	int ctV = 0;
	int ctE = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (prim_egal_ultim(m[i][j])) {
				if (i < j && i + j < n - 1) {
					ctN++;
				}
				else if (i < j && i + j > n - 1) {
					ctE++;
				}
				else if (i > j && i + j > n - 1) {
					ctS++;
				}
				else if (i > j && i + j < n - 1) {
					ctV++;
				}
			}
		}
	}

	int max = ctN;
	char reg = 'N';

	if (ctS > max) {
		max = ctS;
		reg = 'S';
	}
	if (ctV > max) {
		max = ctV;
		reg = 'V';
	}
	if (ctE > max) {
		max = ctE;
		reg = 'E';
	}

	cout << reg << ": " << max << endl;
	//daca sunt egale??
}

void solutie2c() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	ct_numere_cu_cifrele_de_la_margine_egale(m1, n1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;
	cout << "TEST 2" << endl;
	ct_numere_cu_cifrele_de_la_margine_egale(m2, n2);

}
//

//
int cif_control(int n) {
	n = abs(n);
	if (n == 0) {
		return 0;
	}

	int r = n % 9;
	if (r == 0) {
		return 9;
	}

	return r;

}

//triunghi inferior diag secundare:
//            04
//         13 14
//      22 23 24
//   31 32 33 34
//40 41 42 43 44

//conditie:i+j>=n-1
void inlocuire_cu_cif_de_control(int m[100][100], int n, int k) {
	int cif = cif_control(k);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i + j >= n - 1) {
				if (m[i][j] == k) {
					m[i][j] = cif;
				}
			}
		}
	}

}

void afisare(int m[100][100], int n) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void solutie2d() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	int k1 = 47;
	cout << "TEST 1 " << endl;
	inlocuire_cu_cif_de_control(m1, n1, k1);
	afisare(m1, n1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;
	int k2 = -12;
	cout << "TEST 2" << endl;
	inlocuire_cu_cif_de_control(m2, n2, k2);
	afisare(m2, n2);

}
//

//
bool vf_toate_cifrele_in_matrice(int m[100][100], int n) {
	
	for (int i = 0;i < n;i++) {
		int fr[10]{};
		for (int j = 0;j < n;j++) {
			fr[m[i][j]]++;
			if (fr[m[i][j]] > 1) {
				return false;
			}
		}
	}

	for (int i = 0;i < n;i++) {
		int fr[10]{};
		for (int j = 0;j < n;j++) {
			fr[m[j][i]]++;
			if (fr[m[j][i]] > 1) {
				return false;
			}
		}
	}

	return true;
}

void solutie2f() {
	//TEST 1
	int n1 = 9;
	int m1[100][100] = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{4, 5, 6, 7, 8, 9, 1, 2, 3},
		{7, 8, 9, 1, 2, 3, 4, 5, 6},
		{2, 3, 4, 5, 6, 7, 8, 9, 1},
		{5, 6, 7, 8, 9, 1, 2, 3, 4},
		{8, 9, 1, 2, 3, 4, 5, 6, 7},
		{3, 4, 5, 6, 7, 8, 9, 1, 2},
		{6, 7, 8, 9, 1, 2, 3, 4, 5},
		{9, 1, 2, 3, 4, 5, 6, 7, 8}
	};
	cout << "TEST 1 " << endl;
	if (vf_toate_cifrele_in_matrice(m1, n1)) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}
	cout << endl;

	int n2 = 9;
	int m2[100][100] = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{1, 2, 3, 4, 5, 6, 7, 8, 9}
	};
	cout << "TEST 2" << endl;
	if (vf_toate_cifrele_in_matrice(m2, n2)) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}
//

//
void cif_control_nr_par(int m[100][100], int n) {
	int v[100000]{};
	int ct = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int cif = cif_control(m[i][j]);
			if (cif % 2 == 0) {
				v[ct] = m[i][j];
				ct++;
			}
		}
	}

	for (int i = 0;i < ct;i++) {
		cout << v[i] << " ";
	}
}

void solutie2g() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	cif_control_nr_par(m1, n1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;
	cout << "TEST 2" << endl;
	cif_control_nr_par(m2, n2);
}
//

//
void sortat_elemente_vector_crescator(int v[],int s,int d) {
	bool sortat = true;

	do {
		sortat = true;
		for (int i = s;i < d;i++) {
			if (v[i] > v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortat = false;
			}
		}

	} while (sortat == false);

}

void sortat_elemente_vector_descrescator(int v[], int s, int d) {
	bool sortat = true;

	do {
		sortat = true;
		for (int i = s;i < d;i++) {
			if (v[i] < v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortat = false;
			}
		}

	} while (sortat == false);

}

void sortat_vector(int m[100][100], int n) {
	int v[100000]{};
	int ct = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int cif = cif_control(m[i][j]);
			if (cif % 2 == 0) {
				v[ct] = m[i][j];
				ct++;
			}
		}
	}

	int mijloc = ct / 2;

	if (mijloc > 1) {
		sortat_elemente_vector_crescator(v, 0, mijloc - 1);
	}

	if (ct - mijloc > 1) {
		sortat_elemente_vector_descrescator(v, mijloc, ct - 1);
	}

	for (int i = 0;i < ct;i++) {
		cout << v[i] << " ";
	}

}

void solutie2h() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	sortat_vector(m1, n1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;
	cout << "TEST 2" << endl;
	sortat_vector(m2, n2);
}
//

//??
//00 01 02 03 04      
//10 11 12 13 14
//20 21 22 23 24
//30 31 32 33 34
//40 41 42 43 44

void interschimbare_elemente_matrice(int m[100][100], int n) {

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int aux = m[i][j];
			m[i][j] = m[n - 1 - i][j];
			m[n - 1 - i][j] = aux;
		}
	}

}

void solutie2i() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	interschimbare_elemente_matrice(m1, n1);
	afisare(m1, n1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;
	cout << "TEST 2" << endl;
	interschimbare_elemente_matrice(m2, n2);
	afisare(m2, n2);
}
//

//
int elem_maxim_sud(int m[100][100], int n) {
	int S = -99999999;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j && i + j > n - 1) {
				if (m[i][j] > S) {
					S = m[i][j];
				}
			}
		}
	}

	return S;

}

int elem_minim_nord(int m[100][100], int n) {
	int N = 99999999;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j && i + j < n - 1) {
				if (m[i][j] < N) {
					N = m[i][j];
				}
			}
		}
	}

	return N;

}

void interschimbare_elemente_matrice_S_N(int m[100][100], int n) {
	int N = elem_minim_nord(m, n);
	int S = elem_maxim_sud(m, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j] == N) {
				m[i][j] = S;
			}
			else if (m[i][j] == S) {
				m[i][j] = N;
			}
		}
	}

}

void solutie2j() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	interschimbare_elemente_matrice_S_N(m1, n1);
	afisare(m1, n1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;

	cout << "TEST 2" << endl;
	interschimbare_elemente_matrice_S_N(m2, n2);
	afisare(m2, n2);
}
//

//??
int suma_cif(int n) {
	n = abs(n);
	int s = 0;
	while (n != 0) {
		int cif = n % 10;
		s = s + cif;
		n = n / 10;
	}
	return s;
}

//            04
//         13
//      22
//   31
//40

void sortat_descresc_diag_secundara_suma(int m[100][100], int n) {

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i + j == n - 1) {
				
			}
		}
	}

}

void solutie2k() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	cout << "TEST 1 " << endl;
	sortat_descresc_diag_secundara_suma(m1, n1);
	afisare(m1, n1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;

	cout << "TEST 2" << endl;
	sortat_descresc_diag_secundara_suma(m2, n2);
	afisare(m2, n2);
}
//

//??
int frecventa(int n,int k) {
	n = abs(n);
	int ct = 0;

	if (n == 0 && k == 0) {
		return 1;
	}

	while (n != 0) {
		int cif = n % 10;
		if (cif == k) {
			ct++;
		}
		n = n / 10;
	}
	return ct;
}

void frecventa_cif_k(int m[100][100], int n,int k) {
	int f = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			f = f + frecventa(m[i][j], k);
		}
	}
	cout << f << endl;
}

void solutie2l() {
	//TEST 1
	int m1[100][100] = { {12,47,121,7,4}, {40,18,303,9,35},{5, 88, 60, 1331, 70},{15, 16, 47, 48, 7},{32, 11, 7, 47, 96} };
	int n1 = 5;
	int k1 = 1;
	cout << "TEST 1 " << endl;
	frecventa_cif_k(m1, n1, k1);
	cout << endl;

	int m2[100][100] = { {-6, -15, -15, 9},{-15, -9, 4, -3},{-15, 4, 0, -12},{9, -3, -12, -6} };
	int n2 = 4;
	int k2 = 0;
	cout << "TEST 2" << endl;
	frecventa_cif_k(m2, n2, k2);
}