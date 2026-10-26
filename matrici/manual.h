#pragma once
#include <iostream>
#include <fstream>
using namespace std;


//1
void afisare(int m[100][100], int l,int c) {
	
	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

}

void ex1(int N,int x) {
	int m[100][100]{};
	int l = N;
	int c = N;

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			if (i == 0 || j == 0) {
				m[i][j] = x;
			}
			else {
				m[i][j] = m[i - 1][j] + m[i][j - 1];
			}
		}
	}

	afisare(m, l, c);

}

void solutie1() {
	int N = 5;
	int x = 3;

	ex1(N, x);
}
//

//2
void ex2(int M, int N,int m[100][100]) {
	int max = 0;
	int s = 0;

	for (int i = 0;i < M;i++) {
		max = m[i][0];
		for (int j = 0;j < N;j++) {
			if (max < m[i][j]) {
				max = m[i][j];
			}
		}
		s = s + max;
	}

	cout << s;

}

void solutie2() {
	int M = 3;
	int N = 4;
	int m[100][100] = { {32,71,3,5},{ 10,12,6,9 },{ 74,55,6,3 } };

	ex2(M, N, m);
}
//

//3
void ex3(int M, int N, int m[100][100]) {
	int min = 0;
	int s = 0;

	for (int i = 0;i < N;i++) {
		min = m[0][i];
		for (int j = 0;j < M;j++) {
			if (min > m[j][i]) {
				min = m[j][i];
			}
		}
		s = s + min;
	}

	cout << s;

}

void solutie3() {
	int M = 3;
	int N = 4;
	int m[100][100] = { {32,71,3,5},{ 10,12,6,9 },{ 74,55,6,3 } };

	ex3(M, N, m);
}
//

//4
void ex4(int N) {
	int m[100][100];

	for (int i = 0;i < N;i++) {
		cin >> m[0][i];
	}

	for (int i = 1;i < N;i++) {
		int aux = m[i - 1][0];
		for (int j = 0;j < N - 1;j++) {
			m[i][j] = m[i - 1][j + 1];
		}
		m[i][N - 1] = aux;
	}

	afisare(m, N, N);
}

void solutie4() {
	int N = 4;
	ex4(N);
}
//

//5
void ex5(int N,int m[100][100],int x) {
	int ct = 0;

	for (int i = 0;i < N;i++) {
		if (m[0][i] % x == 0) {
			ct++;
		}
		if (m[N - 1][i] % x == 0) {
			ct++;
		}
	}

	for (int i = 1;i < N-1;i++) {
		if (m[i][0] % x == 0) {
			ct++;
		}
		if (m[i][N - 1] % x == 0) {
			ct++;
		}
	}

	cout << ct;
	
}

void solutie5() {
	int N = 4;
	int x = 4;
	int m[100][100] = { {5,2,4,3},{8,2,4,1},{6,4,1,5},{8,4,5,2} };

	ex5(N,m,x);
}
//

//
void ex6(int M,int N, int m[100][100]) {
	bool vf2 = false;

	for (int i = 0;i < M;i++){
		bool vf = true;

		for (int j = 0;j < N - 1;j++) {
			if (m[i][j] != m[i][j + 1]) {
				vf = false;
				break;
			}
		}
		if (vf) {
			cout << i + 1 << " " << m[i][0] << endl;
			vf2 = true;
		}
	}

	if (!vf2) {
		cout << "Nu exista" << endl;
	}

}

void solutie6() {
	int M = 3;
	int N = 4;
	int m[100][100] = { {5,5,5,5},{8,2,4,1},{8,8,8,8} };

	ex6(M, N, m);
}
//

//
void ex7(int M, int N, int m[100][100]) {
	int ct = 0;

	for (int i = 1;i < N;i++) {
		bool vf = true;
		for (int j = 0;j < M;j++) {
			if (m[j][i] == m[j][0]) {
				vf = false;
				break;
			}
		}
		if (vf) {
			ct++;
		}
	}
	cout << ct;
}

void solutie7() {
	int M = 3;
	int N = 4;
	int m[100][100] = { {0,1,1,1},{1,1,0,0},{1,1,0,0} };

	ex7(M, N, m);
}
//

//
void ex8(int N) {
	int m[100][100]{};
	m[0][0] = 1;

	for (int i = 0;i < N;i++) {
		for (int j = 1;j < N;j++) {
			if (i > 0 && j == 1) {
				m[i][j - 1] = m[i - 1][N - 1] + N;
			}

			if (i % 2 == 0) {
				m[i][j] = m[i][j - 1] + 1;
			}
			else {
				m[i][j] = m[i][j - 1] - 1;
			}
			
		}
	}

	afisare(m, N, N);

}

void solutie8() {
	int N = 4;
	ex8(N);
}
//



