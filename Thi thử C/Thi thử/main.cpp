//
//  main.cpp
//  Thi thử
//
//  Created by Võ Đức Quân
//  24-04-2020
//

#include <bits/stdc++.h>
#define Max 20000
typedef long long ll;
using namespace std;
int a[Max], n, m, M;
ll test = 0;
ll dem = 0;

void Try(int i){
    if(i == n) cout << dem;
    else{
        if (a[i] > M) Try(i+1);
        else{
            for (int j = i; j < n; j++){
                test += a[j];
                if (test > M) break;
                else {
                    if(test >= m) dem += 1;
                }
            }
            test = 0;
            Try(i+1);
        }
    }
}

int main(){
    cin >> n >> m >> M;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0 ; i < n; i++){
        if (a[i] >= m && a[i] <= M) dem += 1;
        test = a[i];
        for (int j = i + 1; j < n; j++){
            test += a[j];
            if (test >= m && test <= M) dem += 1;
        }
    }
    cout << dem;
    return 0;
}
