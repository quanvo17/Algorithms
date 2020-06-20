//
//  main.cpp
//  BCAP
//
//  Created by Võ Đức Quân
//  24-04-2020
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define fi first
#define se second
int n,m;
ll ma = 1e18;
ll h[22], ans[5], c[22][22];
int a[22];
void cal(int i){
    for(int j=1; j<=m; j++){
        int ch = 1;
        for(int k = 1; k <= i-1; k++) {
            if(c[j][a[k]] == 1) ch = 0;
        }
        if(ch==1) {
            if(i<n) {
                a[i] = j; ans[j] += h[i];
                ll tmp = 0; for(int k=1; k<=m; k++) tmp = max(tmp, ans[k]);
                if(tmp < ma) {
                    cal(i+1);
                }
                a[i] = 0; ans[j] -= h[i];
            }
            else {
                a[i] = j; ans[j] += h[i];
                ll tmp = 0;
                for(int k=1; k<=m; k++) tmp = max(tmp, ans[k]);
                if(tmp < ma) {
                    ma = tmp;
                    // for(int k=1; k<=n; k++) cout << a[k] <<" ";
                    //cout << " " << ma <<endl;
                }
                a[i] = 0; ans[j] -= h[i];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> h[i];
    }
    
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> c[i][j];
    cal(1);
    if(ma==1e18) cout << -1;
    else cout << ma;
    return 0;
}
