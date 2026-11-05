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

int sumaLinie(int a[100][100], int m, int lin)
{
    int s = 0;
    for (int j = 0; j < m; j++)
    {
        s += a[lin][j];
    }

    return s;
}

int sumaColoana(int a[100][100], int n, int col)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i][col];
    }

    return s;
}

void pozMinim(int a[100][100], int n, int m, int& lin, int& col)
{
    lin = 0;
    col = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] < a[lin][col])
            {
                lin = i;
                col = j;
            }
        }
    }
}

void pozMaxim(int a[100][100], int n, int m, int& lin, int& col)
{
    lin = 0;
    col = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > a[lin][col])
            {
                lin = i;
                col = j;
            }
        }
    }
}

int frecventaElement(int a[100][100], int n, int m, int x)
{
    int nr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == x)
            {
                nr++;
            }
        }
    }

    return nr;
}

bool linieCrescatoare(int a[100][100], int m, int lin)
{
    for (int j = 0; j < m - 1; j++)
    {
        if (a[lin][j] > a[lin][j + 1])
        {
            return false;
        }
    }

    return true;
}

bool linieDescrescatoare(int a[100][100], int m, int lin)
{
    for (int j = 0; j < m - 1; j++)
    {
        if (a[lin][j] < a[lin][j + 1])
        {
            return false;
        }
    }

    return true;
}

bool coloanaCrescatoare(int a[100][100], int n, int col)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i][col] > a[i + 1][col])
        {
            return false;
        }
    }

    return true;
}

bool coloanaDescrescatoare(int a[100][100], int n, int col)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i][col] < a[i + 1][col])
        {
            return false;
        }
    }

    return true;
}

//            lin
//  1 2 3      0          1 2 3
//  4 5 6      1   ->     7 8 9       n = 3 -> 2
//  7 8 9      2

//  n = 4      j=0  j=1  j=2  j=3
//   i=0       P    .    .    S        P: i == j
//   i=1       .    P    S    .        S: i + j == n - 1
//   i=2       .    S    P    .
//   i=3       S    .    .    P



int sumaDiagonalaPrincipala(int a[100][100], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i][i];
    }

    return s;
}

int sumaDiagonalaSecundara(int a[100][100], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i][n - 1 - i];
    }

    return s;
}

//  P x x x              
//  . P x x      i < j
//  . . P x
//  . . . P


//00 01 02   1 2 3
//10 11 12   4 5 6
//20 21 22   7 8 9

//i<n      j<n        s         j       i
//0<3      1<3       0+2=2      2       -
// -       2<3       2+3=5      3       -
//         3<3 nu      -        -       1
//1<3 da   2<3       5+6=11     3       -
// -       3<3 nu      -        -       2
//2<3 da   3<3 nu      -        -       3
//3<3 nu

//s=11

int sumaDeasupraDiagonaleiPrincipale(int a[100][100], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            s += a[i][j];
        }
    }

    return s;
}
                            
//  P . . .                  
//  x P . .      i > j
//  x x P .
//  x x x P

//00 01 02   1 2 3
//10 11 12   4 5 6
//20 21 22   7 8 9


int sumaSubDiagonalaPrincipala(int a[100][100], int n)
{
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            s += a[i][j];
        }
    }

    return s;
}

//  x x x S
//  x x S .      i + j < n - 1
//  x S . .
//  S . . .

int sumaDeasupraDiagonaleiSecundare(int a[100][100], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            s += a[i][j];
        }
    }

    return s;
}

//  . . . S
//  . . S x      i + j > n - 1
//  . S x x
//  S x x x

int sumaSubDiagonalaSecundara(int a[100][100], int n)
{
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            s += a[i][j];
        }
    }

    return s;
}

//  P x x x S
//  . P x S .    deasupra ambelor diagonale: i < j si i + j < n - 1
//  . . X . .
//  . S . P .
//  S . . . P

int sumaNord(int a[100][100], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n - 1 - i; j++)
        {
            s += a[i][j];
        }
    }

    return s;
}

//  P . . . S
//  . P . S .    sub ambele diagonale: i > j si i + j > n - 1
//  . . X . .
//  . S x P .
//  S x x x P

int sumaSud(int a[100][100], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j < i; j++)
        {
            s += a[i][j];
        }
    }

    return s;
}

//  P . . . S
//  x P . S .    i > j si i + j < n - 1
//  x x X . .
//  x S . P .
//  S . . . P

int sumaVest(int a[100][100], int n)
{
    int s = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = j + 1; i < n - 1 - j; i++)
        {
            s += a[i][j];
        }
    }

    return s;
}

//  P . . . S
//  . P . S x    i < j si i + j > n - 1
//  . . X x x
//  . S . P x
//  S . . . P

int sumaEst(int a[100][100], int n)
{
    int s = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = n - j; i < j; i++)
        {
            s += a[i][j];
        }
    }

    return s;
}

void stergereLinie(int a[100][100], int& n, int m, int lin)
{
    for (int i = lin; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = a[i + 1][j];
        }
    }
    n--;
}

void stergereColoana(int a[100][100], int n, int& m, int col)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = col; j < m - 1; j++)
        {
            a[i][j] = a[i][j + 1];
        }
    }
    m--;
}

//  face loc pe linia lin: liniile de la lin in jos coboara cu una,
//  apoi completezi tu a[lin][0..m-1]

void inserareLinie(int a[100][100], int& n, int m, int lin)
{
    for (int i = n - 1; i >= lin; i--)
    {
        for (int j = 0; j < m; j++)
        {
            a[i + 1][j] = a[i][j];
        }
    }
    n++;
}

void inserareColoana(int a[100][100], int n, int& m, int col)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= col; j--)
        {
            a[i][j + 1] = a[i][j];
        }
    }
    m++;
}

void interschimbareLinii(int a[100][100], int m, int l1, int l2)
{
    for (int j = 0; j < m; j++)
    {
        int aux = a[l1][j];
        a[l1][j] = a[l2][j];
        a[l2][j] = aux;
    }
}

void interschimbareColoane(int a[100][100], int n, int c1, int c2)
{
    for (int i = 0; i < n; i++)
    {
        int aux = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = aux;
    }
}

void sortareCrescLinie(int a[100][100], int m, int lin)
{
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i - 1; j++)
        {
            if (a[lin][j] > a[lin][j + 1])
            {
                int aux = a[lin][j];
                a[lin][j] = a[lin][j + 1];
                a[lin][j + 1] = aux;
            }
        }
    }
}

void sortareLiniiDupaColoana(int a[100][100], int n, int m, int col)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
        {
            if (a[k][col] > a[k + 1][col])
            {
                interschimbareLinii(a, m, k, k + 1);
            }
        }
    }
}

//        0 0 0 0 0
//        0 1 1 1 0
//        0 1 2 1 0
//        0 1 1 1 0
//        0 0 0 0 0
// chenarul k: liniile k .. n-1-k, coloanele k .. m-1-k

int nrChenare(int n, int m)
{
    int mic = n;
    if (m < mic)
    {
        mic = m;
    }

    return (mic + 1) / 2;
}

//  5 x 3, k = 1: o singura coloana -> 3 elemente, nu 2*3 + 2*1 - 4

int nrElementeChenar(int n, int m, int k)
{
    int l = n - 2 * k;
    int c = m - 2 * k;
    if (l <= 0 || c <= 0)
    {
        return 0;
    }
    if (l == 1)
    {
        return c;
    }
    if (c == 1)
    {
        return l;
    }

    return 2 * l + 2 * c - 4;
}

//  sus:     a[k][k]         -> a[k][m-1-k]
//  dreapta: a[k+1][m-1-k]   -> a[n-1-k][m-1-k]
//  jos:     a[n-1-k][m-2-k] -> a[n-1-k][k]       doar daca n-1-k > k
//  stanga:  a[n-2-k][k]     -> a[k+1][k]         doar daca m-1-k > k

void afisareChenar(int a[100][100], int n, int m, int k)
{
    int i1 = k, j1 = k, i2 = n - 1 - k, j2 = m - 1 - k;

    for (int j = j1; j <= j2; j++)
    {
        cout << a[i1][j] << " ";
    }
    for (int i = i1 + 1; i <= i2; i++)
    {
        cout << a[i][j2] << " ";
    }
    if (i2 > i1)
    {
        for (int j = j2 - 1; j >= j1; j--)
        {
            cout << a[i2][j] << " ";
        }
    }
    if (j2 > j1)
    {
        for (int i = i2 - 1; i > i1; i--)
        {
            cout << a[i][j1] << " ";
        }
    }
}

int sumaChenar(int a[100][100], int n, int m, int k)
{
    int i1 = k, j1 = k, i2 = n - 1 - k, j2 = m - 1 - k;
    int s = 0;

    for (int j = j1; j <= j2; j++)
    {
        s += a[i1][j];
    }
    for (int i = i1 + 1; i <= i2; i++)
    {
        s += a[i][j2];
    }
    if (i2 > i1)
    {
        for (int j = j2 - 1; j >= j1; j--)
        {
            s += a[i2][j];
        }
    }
    if (j2 > j1)
    {
        for (int i = i2 - 1; i > i1; i--)
        {
            s += a[i][j1];
        }
    }

    return s;
}

int maximChenar(int a[100][100], int n, int m, int k)
{
    int i1 = k, j1 = k, i2 = n - 1 - k, j2 = m - 1 - k;
    int mx = a[i1][j1];

    for (int j = j1; j <= j2; j++)
    {
        if (a[i1][j] > mx)
        {
            mx = a[i1][j];
        }
    }
    for (int i = i1 + 1; i <= i2; i++)
    {
        if (a[i][j2] > mx)
        {
            mx = a[i][j2];
        }
    }
    if (i2 > i1)
    {
        for (int j = j2 - 1; j >= j1; j--)
        {
            if (a[i2][j] > mx)
            {
                mx = a[i2][j];
            }
        }
    }
    if (j2 > j1)
    {
        for (int i = i2 - 1; i > i1; i--)
        {
            if (a[i][j1] > mx)
            {
                mx = a[i][j1];
            }
        }
    }

    return mx;
}

void algoritmSpirala(int a[100][100], int n, int m)
{
    for (int k = 0; k < nrChenare(n, m); k++)
    {
        afisareChenar(a, n, m, k);
    }
    cout << endl;
}

void exemple()
{
    int a[100][100] = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 }
    };
    int n = 4, m = 5;

    cout << "--- matricea ---" << endl;
    afisare(a, n, m);

    cout << endl << "--- parcurgere ---" << endl;
    cout << "sumaLinie(1) = " << sumaLinie(a, m, 1) << ", sumaColoana(2) = " << sumaColoana(a, n, 2) << endl;
    int lin, col;
    pozMinim(a, n, m, lin, col);
    cout << "minimul " << a[lin][col] << " pe linia " << lin << ", coloana " << col << endl;
    pozMaxim(a, n, m, lin, col);
    cout << "maximul " << a[lin][col] << " pe linia " << lin << ", coloana " << col << endl;
    cout << "frecventaElement(13) = " << frecventaElement(a, n, m, 13) << endl;
    cout << "linieCrescatoare(0) = " << linieCrescatoare(a, m, 0) << ", linieDescrescatoare(0) = " << linieDescrescatoare(a, m, 0) << endl;
    cout << "coloanaCrescatoare(4) = " << coloanaCrescatoare(a, n, 4) << ", coloanaDescrescatoare(4) = " << coloanaDescrescatoare(a, n, 4) << endl;

    cout << endl << "--- chenare ---" << endl;
    cout << "nrChenare(4, 5) = " << nrChenare(n, m) << endl;
    for (int k = 0; k < nrChenare(n, m); k++)
    {
        cout << "chenarul " << k << ": ";
        afisareChenar(a, n, m, k);
        cout << "-> " << nrElementeChenar(n, m, k) << " elemente, suma " << sumaChenar(a, n, m, k)
             << ", maxim " << maximChenar(a, n, m, k) << endl;
    }

    cout << endl << "--- algoritmSpirala ---" << endl;
    algoritmSpirala(a, n, m);

    cout << endl << "--- stergereLinie 1 ---" << endl;
    int b[100][100] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int nb = 3, mb = 3;
    stergereLinie(b, nb, mb, 1);
    afisare(b, nb, mb);

    cout << endl << "--- stergereColoana 0 ---" << endl;
    stergereColoana(b, nb, mb, 0);
    afisare(b, nb, mb);

    cout << endl << "--- inserareLinie: dupa linia 0, dublul ei ---" << endl;
    int c[100][100] = {
        { 1, 2, 3 },
        { 7, 8, 9 }
    };
    int nc = 2, mc = 3;
    inserareLinie(c, nc, mc, 1);
    for (int j = 0; j < mc; j++)
    {
        c[1][j] = 2 * c[0][j];
    }
    afisare(c, nc, mc);

    cout << endl << "--- inserareColoana: inaintea coloanei 0, suma liniei ---" << endl;
    inserareColoana(c, nc, mc, 0);
    for (int i = 0; i < nc; i++)
    {
        c[i][0] = c[i][1] + c[i][2] + c[i][3];
    }
    afisare(c, nc, mc);

    cout << endl << "--- interschimbareLinii 0 si 2 ---" << endl;
    interschimbareLinii(c, mc, 0, 2);
    afisare(c, nc, mc);

    cout << endl << "--- interschimbareColoane 0 si 3 ---" << endl;
    interschimbareColoane(c, nc, 0, 3);
    afisare(c, nc, mc);

    cout << endl << "--- sortareCrescLinie 0 ---" << endl;
    sortareCrescLinie(c, mc, 0);
    afisare(c, nc, mc);

    cout << endl << "--- sortareLiniiDupaColoana 1 ---" << endl;
    int d[100][100] = {
        { 3, 30, 1 },
        { 1, 10, 2 },
        { 2, 20, 3 }
    };
    sortareLiniiDupaColoana(d, 3, 3, 1);
    afisare(d, 3, 3);

    cout << endl << "--- diagonale si zone (matrice patratica) ---" << endl;
    int p[100][100] = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 }
    };
    afisare(p, 5, 5);
    cout << "diagonala principala " << sumaDiagonalaPrincipala(p, 5) << ", secundara " << sumaDiagonalaSecundara(p, 5) << endl;
    cout << "deasupra principalei " << sumaDeasupraDiagonaleiPrincipale(p, 5) << ", sub principala " << sumaSubDiagonalaPrincipala(p, 5) << endl;
    cout << "deasupra secundarei " << sumaDeasupraDiagonaleiSecundare(p, 5) << ", sub secundara " << sumaSubDiagonalaSecundara(p, 5) << endl;
    cout << "nord " << sumaNord(p, 5) << ", sud " << sumaSud(p, 5) << ", est " << sumaEst(p, 5) << ", vest " << sumaVest(p, 5) << endl;
}
