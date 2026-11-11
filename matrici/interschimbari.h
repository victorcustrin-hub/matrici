#pragma once
#include <iostream>
using namespace std;

//6.1
void interschimbare_linii(int a[100][100], int m, int l1, int l2) {
    for (int j = 0; j < m; j++) {
        int aux = a[l1][j];
        a[l1][j] = a[l2][j];
        a[l2][j] = aux;
    }
}


void liniile_in_oglinda(int m[100][100], int l, int c) {



}
