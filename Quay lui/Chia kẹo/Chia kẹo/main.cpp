//
//  main.cpp
//  Chia kẹo
//
//  Created by Võ Đức Quân
//  20-04-2020
//
// Liệt kê tất cả các cách chia M kẹo cho n em bé sao cho em bé nào cũng có kẹo

#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
int A[MAX];
void xuat(int n){
    for (int i = 1; i < n+1; i++){
            if (i == n)
                cout << A[i] << endl;
            else cout << A[i] << " ";
    }
}
int f = 0;
void chiakeo(int k, int n, int a){
    int x, y;
    if (k == n){
        x = a - f;
        y = a - f;
    } else {
        x = a - f - n + k;
        y = 1;
    }
    for (int j = y; j < x + 1; j++){
        A[k] = j;
        f += j;
        if(k == n){
            xuat(n);
        } else{
            chiakeo(k+1, n, a);
        }
        f -= j;
    }
}
int main(){
    int a, n;
    cout << "Nhập số kẹo: ";
    cin >> a;
    cout << "Nhập số em cần chia: ";
    cin >> n;
    chiakeo(1, n, a);
    return 0;
}
