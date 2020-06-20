//
//  main.cpp
//  Xếp hậu
//
//  Created by Võ Đức Quân
//  20-04-2020
//


#include <bits/stdc++.h>
using namespace std;

int a[100];
int OK(int x, int y){
    for(int i = 1; i <= x ;i++)
        if(a[i] == y || abs(i-x) == abs(a[i] - y) )
            return 0;
    return 1;
}
void Xuat(int n){
    for (int i = 1; i <= n; i++){
        cout << a[i] <<" ";
    }
    cout << endl;
}
void Try(int i, int n){
    for (int j = 1; j <= n; j++){
        // thử đặt quân hậu vào các cột từ 1 đến n
        if (OK(i, j)){
            //nếu cách đặt này thỏa mãn thì lưu lại vị trí
            a[i] = j;
            if (i == n) Xuat(n);
            //nếu đặt xong quân hậu thứ n thì xuất ra một kết quả
            Try(i+1, n);
            //đệ quy cho trường hợp ở cột i+1
        }
    }
}
int main(){
    int n;
    cout << "Nhap so n = ";
    cin >> n;
    cout << "Những cách xếp hậu là:" << endl;
    Try(1, n);
    return 0;
}
