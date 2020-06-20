//
//  main.cpp
//  gold mine 2
//
//  Created by ETADO on 5/19/20.
//  Copyright © 2020 ETADO. All rights reserved.
//

#include<bits/stdc++.h>

using namespace std;
int n,l1,l2;
int a[100001];
int l[100001];

int dp(int x){
    if(l[x]<0){
        for(int i=l1;i<=l2;++i){
            if(x-i>=1) l[x] = max(l[x], dp(x-i) + a[x]);
        }
        l[x] = max(l[x], a[x]);
        if(x>=2) l[x] = max(l[x], dp(x-1));
    }
    return l[x];
}

int main(){
    scanf("%d%d%d",&n,&l1,&l2);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    memset(l,-1,sizeof(l));
    cout << dp(n);
    return 0;
}
