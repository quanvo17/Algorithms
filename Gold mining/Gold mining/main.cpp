//
//  main.cpp
//  Gold mining
//
//  Created by ETADO on 5/5/20.
//  Copyright © 2020 ETADO. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define fi first
#define se second
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n,l,r;
int a[10]; // chứa giá trị từng mỏ vàng
ll f[20];// lưu giá trị lớn nhất của các trường hợp đi tới mỏ vàng đó
int ma[20], d[20];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    cin >> n >> r >> l;
    for(int i=1; i<=n; i++) cin >> a[i]; // nhập giá trị từng mỏ vàng
    for(int i=1; i<=r; i++) {
        f[i] = a[i]; // Lấy trước các giá trị của các mỏ vàng đến r vì khoảng cách phải >= r
    }
    int top = 0;
    for(int i = r+1; i <= n; i++) {
        while(top > 0 && f[d[top]] <= f[i-r]) top--;
        d[++top] = i-r;
        int res = top;
        while(res>0 && d[res]>=i-l) res--;
        
        f[i] = f[d[res+1]] + a[i];
    }
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, f[i]);
    }
    cout << ans;
    
    return 0;
}
