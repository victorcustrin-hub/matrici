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