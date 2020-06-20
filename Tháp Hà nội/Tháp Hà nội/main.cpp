//
//  main.cpp
//  Tháp Hà nội
//  Created by Võ Đức Quân
//  20-04-2020
//


#include <bits/stdc++.h>
using namespace std;
int i=0;
void move(int n, char start, char finish, char spare){
    if(n==1){
        cout << "Chuyen tu coc " << start << "sang coc" << finish << endl;
        i++;
        return ;
    } else{
        move(n-1,start, spare, finish);
        move(1,start, finish, spare);
        move(n-1,spare, finish, start);
    }
}
int main(){
    int n;
    cout << "Nhap so luong dia: ";
    cin >> n;
    move(n, 'A', 'B', 'C');
    cout << "Tong so lan chuyen dia la: " << i << endl;
    return 0;
}

