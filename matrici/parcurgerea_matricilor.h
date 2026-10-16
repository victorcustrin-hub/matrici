#pragma once
#include <iostream>
using namespace std;



void afisare(int m[100][100],int l,int c) {

	for (int i = 0;i < l;i++) {
		for (int j = 0;j < c;j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

}


void afisareColoana(int m[100][100], int l, int c, int x) {
	
}