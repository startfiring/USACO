/*
ID: yinzong2
PROG: beads
LANG: C++
*/
#define MARK

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int n;
string s;
int main() {
#ifdef MARK
    freopen("beads.in", "r" ,stdin);
    freopen("beads.out", "w", stdout);
#endif
    cin >> n >> s;
    s = s+s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        int cnt = 0;
        int state = 0;
        if ('w' == c) {
            state = 0;
        } else {
            state = 1;
        }
        int j = i;
        while (state <= 2) {
            while (j < n+i && ((s[j] == c) || 'w' == s[j])) {
                j++;
                cnt++;
            }
            state++;
            c = s[j];
        }
        if (ans < cnt){
            ans = cnt;
        }
    }
    cout << ans << endl;
    return 0;
}