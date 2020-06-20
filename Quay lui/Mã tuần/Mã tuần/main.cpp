//
//  main.cpp
//  Mã tuần
//
//  Created by Võ Đức Quân
//  20-04-2020
//


#include <bits/stdc++.h>
#define MAX 8
using namespace std;

int A[MAX][MAX];
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
// Những nước đi hợp lệ: abs(X[i] + Y[i]) =3
int dem = 0;//Số bước đi
int n;// Số phần tử của bàn cờ bạn muốn tạo

void xuat() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(j == n - 1)
                cout << A[i][j] << endl;
            else cout << A[i][j] << " ";
    cout << endl;
}

void dichuyen(int x, int y){
    ++dem;
    A[x][y] = dem;
    for(int i = 0; i < 8; i++){
        if (dem == n*n){
            cout << "Các bước đi là: " << endl;
            xuat();
            exit(0);
        }
        int u = x + X[i];
        int v = y + Y[i];// tạo bước đi mới
        if(u >= 0 && u < n && v >= 0 && v < n&& A[u][v] == 0)
            dichuyen(u, v);
    }
    //Nếu không tìm được bước đi thì ta phải trả lại các giá trị ban đầu
    --dem;
    A[x][y] = 0;
}

int main() {
    cout << "Nhap n: ";
    cin >> n;
    int a, b;
    cout << "Nhap vi tri ban dau.\nx: ";
    cin>>a;
    cout << "y: ";
    cin >> b;
    dichuyen(a, b);
    //Nếu không tìm được bước đi thì sẽ thông báo
    cout << "Khong tim thay duong di.";
}
