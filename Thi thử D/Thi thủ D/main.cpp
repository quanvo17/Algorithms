//
//  main.cpp
//  Thi thủ D
//
//  Created by Võ Đức Quân
//  24-04-2020
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    const int Max = 1e6;
    int n, dem = 0, result, maxtl = 0, maxdoi = 0;
    int a[Max];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++){
        if((a[i-1] > a[i]) && (a[i+1] > a[i])){
            for (int j = i + 1; j < n; j++){
                if(a[j] > a[j-1]) dem += 1;
                else break;
            }
            result = dem;
            dem = 0;
            for (int j = i - 1; j >= 0; j --){
                if(a[j] > a[j+1]) dem += 1;
                else break;
            }
            result = min(result, dem);
            maxtl = max(result, maxtl);
        }
        dem = 0;
        if((a[i-1] < a[i]) && (a[i+1] < a[i])){
            for (int j = i + 1; j < n; j++){
                if(a[j] < a[j-1]) dem += 1;
                else break;
            }
            result = dem;
            dem = 0;
            for (int j = i - 1; j >= 0; j --){
                if(a[j] < a[j+1]) dem += 1;
                else break;
            }
            result = min(result, dem);
            maxdoi = max(result, maxdoi);
        }
    }
    cout << maxdoi << " "<< maxtl;
    return 0;
}
