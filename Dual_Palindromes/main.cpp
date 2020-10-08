/*
ID: kangzi1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 20;

void ten2base(char *a, int b, int base)
{
    int i = 0;
    while (b) {
        int c = b % base;
        if (c < 10) {
            a[i++] = c + '0';
        } else {
            a[i++] = c - 10 + 'A';
        }
        b /= base;
    }
    for (int j = 0; j < i / 2; j++) {
        swap (a[j], a[i - 1 - j]);
    }
}

bool ispalindrome(int b, int base)
{
    char a[maxn];
    memset (a, '\0', sizeof(a));
    ten2base (a, b, base);
    int l = strlen (a);
    for (int i = 0; i < l / 2; i++) {
        if (a[i] != a[l - 1 - i]) return false;
    }
    return true;
}

int main() {
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int n, s;
    scanf ("%d%d", &n, &s);
    int num = 0;
    for (int i = s + 1; ; i++) {
        int flag = 0;
        for (int j = 2; j <= 10; j++) {
            if (ispalindrome (i, j)) {
                flag++;
            }
            if (flag == 2) {
                printf ("%d\n", i);
                num++;
                break;
            }
        }
        if (num == n) break;
    }
    return 0;
}
