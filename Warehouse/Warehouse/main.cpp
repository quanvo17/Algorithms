//
//  main.cpp
//  Warehouse
//
//  Created by ETADO on 5/19/20.
//  Copyright © 2020 ETADO. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define fi first
#define se second
const int maxn = 1e5;
const int mod = 1e9 + 7;
int n,T,d;
int a[1005], t[1005];
int dp[1005][105];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    cin >> n >> T >> d;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> t[i];
    for(int i=1; i<=n; i++) dp[i][t[i]] = a[i];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=T; j++) {
            for(int k=1; k<=min(i-1,d); k++) {
                if(t[i] < j) dp[i][j] = max(dp[i][j], dp[i-k][j-t[i]] + a[i]);
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) for(int j=1; j<=T; j++) ans = max(ans, dp[i][j]);
    cout << ans;
    return 0;
}
