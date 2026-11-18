#pragma once
#include <iostream>
using namespace std;


//4.1
void afisare(int a[100][100], int n, int m) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int minim(int m[100][100], int l,int c, int &pozl, int &pozc) {
	int min = m[0][0];

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (m[i][j] < min) {
				min = m[i][j];
                pozl = i;
                pozc = j;
			}
		}
	}

	return min;
}

void stergere_linie(int m[100][100], int& l, int c, int poz)
{
    for (int i = poz; i < l - 1; i++){
        for (int j = 0; j < c; j++){
            m[i][j] = m[i + 1][j];
        }
    }
    l--;
}

void stergere_coloana(int m[100][100], int l, int& c, int poz)
{
    for (int i = 0; i < l; i++){
        for (int j = poz; j < c - 1; j++){
            m[i][j] = m[i][j + 1];
        }
    }
    c--;
}

void linia_coloana_minimului(int m[100][100], int l, int c) {
    int pozl = 0;
    int pozc = 0;

    if (l >= 1 && c > 1) {
        int min = minim(m, l, c, pozl, pozc);
        stergere_linie(m, l, c, pozl);
        stergere_coloana(m, l, c, pozc);
        afisare(m, l, c);
    }
    else {
        cout << "MATRICE VIDA" << endl;
    }

}

void solutie_1() {
    cout << "TEST 1" << endl;
    int m1[100][100] = { {4,9,2},{7,1,5},{8,3,6} };
    int l1 = 3;
    int c1 = 3;
    linia_coloana_minimului(m1, l1, c1);
    cout << endl;

    cout << "TEST 2" << endl;
    int m2[100][100] = { {1,5},{7,2} };
    int l2 = 2;
    int c2 = 2;
    linia_coloana_minimului(m2, l2, c2);
    cout << endl;

    cout << "TEST 3" << endl;
    int m3[100][100] = { {3} };
    int l3 = 1;
    int c3 = 1;
    linia_coloana_minimului(m3, l3, c3);
    cout << endl;
}
//

//4.2
bool vf_linie_monotona(int m[100][100], int l, int c) {
    bool crescator = true;
    bool descrescator = true;

    for (int i = 0;i < c - 1;i++) {

        if (m[l][i] < m[l][i+1]) {
            crescator = false;
        }
        if (m[l][i] > m[l][i+1]) {
            descrescator = false;
        }

    }

    return crescator || descrescator;
}

void linii_neordonate(int m[100][100], int &l, int c) {

    for (int i = l-1;i >= 0;i--) {
        if (!vf_linie_monotona(m, i, c)) {
            stergere_linie(m, l, c, i);
        }
    }

    if (l < 1) {
        cout << "MATRICE VIDA" << endl;
    }
    else {
        afisare(m, l, c);
    }

}

void solutie_2() {
    cout << "TEST 1" << endl;
    int m1[100][100] = { {1,2,3},{5,1,4},{2,8,3},{9,7,2} };
    int l1 = 4;
    int c1 = 3;
    linii_neordonate(m1, l1, c1);
    cout << endl;

    cout << "TEST 2" << endl;
    int m2[100][100] = { {1,3,2} };
    int l2 = 1;
    int c2 = 3;
    linii_neordonate(m2, l2, c2);
    cout << endl;
}
//

//??
bool prim(int n) {
    if (n <= 1) {
        return false;
    }
    for (int k = 2; k <= n / 2; k++) {
        if (n % k == 0) {
            return false;
        }
    }
    return true;
}

void al_doilea_nr_prim(int a[100][100], int& n, int& m) {
    int ctprim = 0;
    int lin = -1, col = -1;

    for (int i = 0; i < n && ctprim < 2; i++) {
        for (int j = 0; j < m && ctprim < 2; j++) {
            if (prim(a[i][j])) {
                ctprim++;
                if (ctprim == 2) {
                    lin = i;
                    col = j;
                }
            }
        }
    }

    if (ctprim < 2) {
        cout << "NU EXISTA" << endl;
        return;
    }

    for (int i = lin; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = a[i + 1][j];
        }
    }
    n--;

    for (int i = 0; i < n; i++) {
        for (int j = col; j < m - 1; j++) {
            a[i][j] = a[i][j + 1];
        }
    }
    m--;

    if (n == 0 || m == 0) {
        cout << "MATRICE VIDA" << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void solutie_3() {
    cout << "TEST 1" << endl;
    int m1[100][100] = { {4,7,9},{11,6,8},{10,12,13} };
    int l1 = 3;
    int c1 = 3;
    al_doilea_nr_prim(m1, l1, c1);
    cout << endl;

    cout << "TEST 2" << endl;
    int m2[100][100] = { {4,6},{9,7} };
    int l2 = 2;
    int c2 = 2;
    al_doilea_nr_prim(m2, l2, c2);
    cout << endl;
}
//

//??
bool palindrom_3_cif(int x) {
    if (x < 0) x = -x;

    return (x >= 100 && x <= 999 && (x / 100 == x % 10));
}

void sterge_col_palindrom(int a[100][100], int n, int& m) {
    for (int j = 0; j < m; j++) {
        bool vf = false;

        for (int i = 0; i < n; i++) {
            if (palindrom_3_cif(a[i][j])) {
                vf = true;
                break;
            }
        }

        if (vf) {
            for (int i = 0; i < n; i++) {
                for (int k = j; k < m - 1; k++) {
                    a[i][k] = a[i][k + 1];
                }
            }
            m--;
            j--;
        }
    }

    if (m == 0) {
        cout << "MATRICE VIDA" << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void solutie_4() {
    cout << "TEST 1" << endl;
    int m1[100][100] = { {121, 45, 78, 9},{12, 232, 78, 33},{15, 45, 100, 7} };
    int l1 = 3;
    int c1 = 4;
    sterge_col_palindrom(m1, l1, c1);
    cout << endl;

    cout << "TEST 2" << endl;
    int m2[100][100] = { {101,102} };
    int l2 = 1;
    int c2 = 2;
    sterge_col_palindrom(m2, l2, c2);
    cout << endl;

    cout << "TEST 3" << endl;
    int m3[100][100] = { {11,22},{33,44} };
    int l3 = 2;
    int c3 = 2;
    sterge_col_palindrom(m3, l3, c3);
    cout << endl;
}
//