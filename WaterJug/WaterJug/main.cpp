//
//  main.cpp
//  WaterJug
//
//  Created by Võ Đức Quân
//  23-04-2020
//


#include <bits/stdc++.h>
using namespace std;

//Tìm ước chung lớn nhất của 2 số a, b;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int Try(int fromCap, int toCap, int d){
    int from = fromCap; //đặt lượng nước trong bình hiện tại và bình đích
    int to = 0;
    
    int step = 1;
    
    // Thoát vòng lặp khi một trong 2 bình có đủ nước cần
    while (from != d && to != d){
        //biến chứa lượng nước nhiều nhất đổ được từ bình này qua bình kia
        int temp = min(from, toCap - to);
        //đổ temp lít nước từ bình from qua to
        to += temp;
        from -= temp;
        step++; // tăng số bước đổ
        if (from == d || to == d)// vừa đổ nếu đầy bình thì thoát ra
            break;
        
        if (from == 0) { // Nếu bình gốc hết thì đổ đầy bình và tăng số bước
            from = fromCap;
            step++;
        }
        
        if (to == toCap) { // Nếu bình đích đầy thì đổ hết nước trong bình và tăng số bước
            to = 0;
            step++;
        }
    }
    return step;
}
int minSteps(int m, int n, int d){
    if(m > n)
        swap(m, n);
    if (d > n) // nếu lượng nước cần lớn hơn bình max thì không thể đong
        return -1;
    if ((d % gcd(n,m)) != 0) // nếu lượng nước cần không chia hết số ước chung lớn nhất của 2 số thì không có kết quả
        return -1;
    return min(Try(m, n, d), Try(n, m, d)); // trả về kết quả nhỏ nhất của 2 trường hợp
}

int main() {
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << minSteps(a, b, c);
    return 0;
}
