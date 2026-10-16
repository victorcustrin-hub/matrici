#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void citire(int a[100][100], int& n, int& m) {
	ifstream fin("matrice.in");
	fin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			fin >> a[i][j];
		}
	}
}
//     0  1   2
// 
// 0   12 32 11                                 12   32  11     
// 1   98 21 33
// 2   87 65 22
//n=3,m=3
//  
// i<3    j<3     af   j   i
// 0<3    0<3     12   1  
//        1<3     32   2
//        2<3     11   3
//        3<3     endl     1
// 1<3    0<3     98   1
//        1<3     21   2
//        2<3     33   3
//        3<3     endl     2
//2<3     0<3     87   1
//        1<3     65   2
//        2<3     22   3   
//        3<3     endl     3
//3<3 nu

void afisare(int a[100][100], int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void scriere(int a[100][100], int n, int m) {
	ofstream fout("matrice.out");
	fout << n << " " << m << endl;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			fout << a[i][j] << " ";
		}
		fout << endl;
	}
}
