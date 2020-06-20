//
//  main.cpp
//  BCA
//
//  Created by Võ Đức Quân
//  23-04-2020
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> v[30], u[30];
int n, m;
ll c[30][30];

void input(){
    cin >> m >> n;
    for (int i = 1; i <= m;i++){
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++){
            int t; cin >> t;
            v[i].push_back(t);
        }
    }
    // Chuyển thành môn i có thể có ai dạy
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < v[i].size(); j++){
            u[v[i][j]].push_back(i);
        }
    }
    int y;
    cin >> y;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            c[i][j] = 0;
        }
    }
    for (int k = 1; k <= y; k++){
        int i,j;
        cin >> i >> j;
        c[i][j] = c[j][i] = 1;
    }
}
void cal(int i){
    
}
int main(){
    input();
//    for (int i = 1; i <= n; i++){
//        for (int j = 1; j <= n; j++){
//            if (j == n) cout << c[i][j] << endl;
//            else cout << c[i][j] << " ";
//        }
//    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < u[i].size(); j++){
            if(j == u[i].size() - 1) cout << u[i][j] << endl;
            else cout << u[i][j] << " ";
        }
    }
    return 0;
}


