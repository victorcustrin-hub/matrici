#pragma once
#include <iostream>
using namespace std;

//2.1

//00 01 02
//10 11 12
//20 21 22
void sume(int m[100][100], int n) {
	int deasupra_diag_prin = 0;
	int sub_diag_prin = 0;
	int deasupra_diag_sec = 0;
	int sub_diag_sec = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i < j) {
				deasupra_diag_prin = deasupra_diag_prin + m[i][j];
			}

			if (j < i) {
				sub_diag_prin = sub_diag_prin + m[i][j];
			}

			if (i + j < n - 1) {
				deasupra_diag_sec = deasupra_diag_sec + m[i][j];
			}

			if (i + j > n - 1) {
				sub_diag_sec = sub_diag_sec + m[i][j];
			}

		}
	}
	cout << deasupra_diag_prin << " " << sub_diag_prin << " " << deasupra_diag_sec << " " << sub_diag_sec << endl;
}

void solutie_1() {
	cout << "TEST 1" << endl;
	int m1[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int n1 = 3;
	sume(m1, n1);
	cout << endl;

	cout << "TEST 2" << endl;
	int m2[100][100] = { {1,2},{3,4} };
	int n2 = 2;
	sume(m2, n2);
	cout << endl;

	cout << "TEST 3" << endl;
	int m3[100][100] = { {5} };
	int n3 = 1;
	sume(m3, n3);
	cout << endl;
}