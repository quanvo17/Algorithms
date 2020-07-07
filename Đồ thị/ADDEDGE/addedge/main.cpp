//
//  main.cpp
//  addedge
//
//  Created by ETADO on 7/6/20.
//  Copyright © 2020 ETADO. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> edge[100050];
vector<int> bridgeEdge[100050];
int d[100050];
int low[100050];
int visited[100050];
int parent[100050];
int64_t ans = 0;
int t = 0;
void  dfs(int u){
    visited[u] = 1;
    d[u] = low[u] = ++t;
    for(int v : edge[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(low[v] > d[u]){
                //                cout << "canh cau (" << u << "," << v << ")\n";
                bridgeEdge[u].push_back(v);
                bridgeEdge[v].push_back(u);
            }
        } else if(parent[u] != v){
            low[u] = min(low[u], d[v]);
        }
        
    }
}

void dfs1(int u, int64_t &cnt){
    visited[u] = 1;
    cnt++;
    for(int v : bridgeEdge[u]){
        if(!visited[v]){
            dfs1(v,cnt);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    int x1, x2;
    for(int i = 0; i < m; i++){
        cin >> x1 >> x2;
        edge[x1].push_back(x2);
        edge[x2].push_back(x1);
    }
    
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
        parent[i] = 0;
    }
    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            
            dfs(i);
        }
    }
    
    
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    int64_t cnt = 0;
    for(int i = 1; i <= n; i++){
        if(bridgeEdge[i].size() > 0){
            if(!visited[i]){
                dfs1(i,cnt);
                ans += (cnt-2)*(cnt-1)/2;
                cnt = 0;
            }
        }
    }
    
    cout << ans;
    
}

