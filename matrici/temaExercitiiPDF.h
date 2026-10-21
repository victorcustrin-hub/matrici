#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


//EXERCITIUL 1
//
void ex1a(int m[100][100],int l,int c) {
	int ct = 0;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (m[i][j] % 2 == 0 && i % 2 == 0 && j % 3 == 0) {
				ct++;
			}
		}
	}

	cout << ct;

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

void ex1b(int m[100][100],int l,int c) {
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
//

//
bool patrat_perfect(int n) {
	if (n < 0) {
		return false;
	}

	int x = round(sqrt(n));
	return(x * x == n);
}

void afisare(int m[100][100], int l,int c) {
	
	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

}

void ex1c(int m[100][100], int l, int c) {
	int s = 0;

	for (int i = 0;i < l;i++) {
		for (int x = 0;x < c;x++) {
			s = s + m[i][x];
		}
		for (int j = 0;j < c;j++) {
			if (patrat_perfect(m[i][j])) {
				m[i][j] = s;
			}
		}
		s = 0;
	}

}
//

//??
void ex1d(int m[100][100], int l, int c, int L, int C) {
	int min = m[L][0];
	int max = m[0][C];

	int poz_min_i = L;
	int poz_min_j = 0;
	
	int poz_max_i = 0;
	int poz_max_j = C;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (i == L) {
				if (m[i][j] < min) {
					min = m[i][j];
					 poz_min_i = i;
					 poz_min_j = j;
				}
			}

			if (j == C) {
				if (m[i][j] >= max) {
					max = m[i][j];
					poz_max_i = i;
					poz_max_j = j;
				}
			} 

		}
	}

	int aux = m[poz_min_i][poz_min_j];
	m[poz_min_i][poz_min_j] = m[poz_max_i][poz_max_j];
	m[poz_max_i][poz_max_j] = aux;
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

void ex1e(int m[100][100],int l,int c) {
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
//

//
void ex1f(int m[100][100], int l, int c) {
	long max = -9999999;
	int s = 0;

	for (int i = 0;i < l;i++) {
		s = 0;
		for (int j = 0;j < c;j++) {
			s = s + m[i][j];
		}
		cout << s << " ";
		if (s > max) {
			max = s;
		}
	}
	cout << endl;
	cout << "maxim: " << max << endl;
}
//

//
void ex1g(int m[100][100], int l, int c) {
	int ct = 0;
	long max = -999999;
	int linie_rez = 0;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			ct = 0;
			int aux = m[i][j];
			while (aux != 0) {
				int cif = aux % 10;
				if (cif == 0 || cif == 1) {
					ct++;
				}
				aux = aux / 10;
			}
			if (ct > max) {
				linie_rez = i;
				max = ct;
			}
		}
	}
	int s = 0;
	for (int j = 0;j < c;j++) {
		s = s + m[linie_rez][j];
	}
	double medie = double(s)/c;
	cout << "linia " << linie_rez << ": " << fixed << setprecision(2) << medie;

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

void ex2a(int m[100][100],int l,int c) {
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

void ex2b(int m[100][100], int l, int c) {
	double s = 0;
	int ct = 0;
	bool vf = 0;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (divizori_proprii(m[i][j]) >= 3 && divizori_proprii(m[i][j]) <= 5) {
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

void ex2c(int m[100][100], int l, int c,int L) {
	bool vf = 0;

	for (int i = 0;i < c - 1;i++) {
		for (int j = i + 1;j < c;j++) {
			if (palindrom_intre_ele(m[L][i], m[L][j])) {
				cout << m[L][i] << " "<< m[L][j] << endl;
				vf = 1;
			}
		}
	}
	

	if (!vf) {
		cout << "nu exista";
	}
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

void ex2d(int m[100][100], int l, int c) {
	l--;
	c--;

	int rez = cif_control(m[l][c]);
	cout << rez;
}
//

//
void ex2e_si_f(int m[100][100], int l, int c) {
	//
	int f[10]{};

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (i % 2 != 0 && j % 2 == 0) {
				int aux = m[i][j];
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
	cout << "e) ";
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
//

//
void ex2g(int m[100][100],int l,int c) {
	int f[10]{};

	for (int i = 1;i < l - 1;i++) {
		for (int j = 1;j < c - 1;j++) {
			int aux = m[i][j];
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
//

//
void ex2h(int m[100][100], int l, int c,int k,int y) {
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
		cout << "nu exista";
	}

}
//
void ex2i_si_j(int m[100][100], int l, int c,int col,int k) {
	bool vf = true;
	bool vf2 = 0;
	do {
		vf = true;
		for (int i = 0;i < l - 1;i++) {
			if (m[i][col] > m[i+1][col]) {
				int aux = m[i][col];
				m[i][col] = m[i + 1][col];
				m[i + 1][col] = aux;
				vf = false;
			}
		}

	} while (vf == false);

	cout << "i) ";
	cout << endl;
	afisare(m, l, c);
	cout << endl;
	cout << "j) ";

	for (int i = 0;i < l;i++) {
		if (m[i][col] == k) {
			cout << "linia " << i;
			vf2 = 1;
		}
	}
	if (!vf2) {
		cout << "nu exista";
	}
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
//

//??
bool superprim(int n) {

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
				cout<<m[i][j]<<" ";
			}
		}
	}

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
//
