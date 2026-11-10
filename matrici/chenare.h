#pragma once
#include <iostream>
using namespace std;

//3.1 ??
int nr_elemente_chenar(int n, int m) {
    int l = n - 2;
    int c = m - 2;

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

    return 0;
}