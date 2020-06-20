//
//  main.cpp
//  Signal
//
//  Created by Võ Đức Quân
//  23-04-2020
//


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int b;
    cin >> n >> b;
    int N = 200001;
    int a[N];
    int p[N];
    
    
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = max(p[i-1],a[i]);
    }
    
    int res = -1;
    int s = a[n];
    for(int i = n; i>1; i-- ){
        int x = p[i-1] - a[i];
        int y = s - a[i];
        if(min(x,y) >= b){
            res = max(res,x+y);
        }
        s = max(s,a[i]);
    }
    
    
    cout << res;
    
    
    
    
}
