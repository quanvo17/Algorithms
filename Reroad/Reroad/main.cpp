//
//  main.cpp
//  Reroad
//
//  Created by Võ Đức Quân
//  23-04-2020
//


#include <bits/stdc++.h>

#define MN 200005

using namespace std;

int res, n, q, p, c;
int a[MN];

int main() {
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = -1e9 - 1; a[n + 1] = 1e9 + 1;
    for(int i = 1; i <= n; i++)
        if (a[i] != a[i - 1])
            res += 1;
    
    cin >> q;
    while (q--) {
        cin >> p >> c;
        if (c != a[p]) {
            if (a[p - 1] == a[p + 1]) {
                if (c == a[p - 1])
                    res -= 2;
                if (a[p] == a[p - 1])
                    res += 2;
            } else {
                if ((a[p] == a[p - 1]) || (a[p] == a[p + 1]))
                {
                    if ((c != a[p - 1]) && (c != a[p + 1]))
                        res += 1;
                } else {
                    if ((c == a[p - 1]) || (c == a[p + 1]))
                        res -=1;
                }
            }
        }
        a[p] = c;
        cout << res << endl;
    }
}
