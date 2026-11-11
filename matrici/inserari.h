#pragma once
#include <iostream>
using namespace std;

//5.1 ??
void inserare_coloana(int a[100][100], int n, int& m, int col) {
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= col; j--) {
            a[i][j + 1] = a[i][j];
        }
    }
    m++;
}

void zero_intre_coloane(int a[100][100], int n, int& m) {
    for (int j = m - 2; j >= 0; j--) {
        inserare_coloana(a, n, m, j + 1);

        for (int i = 0; i < n; i++) {
            a[i][j + 1] = 0;
        }
    }
}

void afisare(int a[100][100], int n, int m) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void solutie_1() {
    cout << "TEST 1" << endl;
    int m1[100][100] = { {1,2,3},{4,5,6} };
    int l1 = 2;
    int c1 = 3;
    zero_intre_coloane(m1, l1, c1);
    afisare(m1, l1, c1);
    cout << endl;

    cout << "TEST 2" << endl;
    int m2[100][100] = { {7},{8} };
    int l2 = 2;
    int c2 = 1;
    zero_intre_coloane(m2, l2, c2);
    afisare(m2, l2, c2);
    cout << endl;
}
//

//5.2 ??
int sumaLinie(int a[100][100], int m, int lin){
    int s = 0;
    for (int j = 0; j < m; j++)
    {
        s = s + a[lin][j];
    }
    return s;
}

void inserare_linie(int a[100][100], int& n, int m, int lin){
    for (int i = n - 1; i >= lin; i--) {
        for (int j = 0; j < m; j++) {
            a[i + 1][j] = a[i][j];
        }
    }
    n++;
}

void dublul_liniei_grele(int a[100][100], int& n, int m) {
    int lmax = 0;
    int smax = sumaLinie(a, m, 0);

    for (int i = 1; i < n; i++){
        int s = sumaLinie(a, m, i);

        if (s > smax){
            smax = s;
            lmax = i;
        }
    }

    inserare_linie(a, n, m, lmax + 1);
}

void solutie_2() {
    cout << "TEST 1" << endl;
    int m1[100][100] = { {1,2,3},{9,8,7},{5,7,9} };
    int l1 = 3;
    int c1 = 3;
    dublul_liniei_grele(m1, l1, c1);
    afisare(m1, l1, c1);
    cout << endl;

    cout << "TEST 2" << endl;
    int m2[100][100] = { {2,4},{3,3} };
    int l2 = 2;
    int c2 = 2;
    dublul_liniei_grele(m2, l2, c2);
    afisare(m2, l2, c2);
    cout << endl;

    cout << "TEST 3" << endl;
    int m3[100][100] = { {1,3},{2,9} };
    int l3 = 2;
    int c3 = 2;
    dublul_liniei_grele(m3, l3, c3);
    afisare(m3, l3, c3);
    cout << endl;
}
//