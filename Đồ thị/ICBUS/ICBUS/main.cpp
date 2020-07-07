//
//  main.cpp
//  ICBUS
//
//  Created by ETADO on 7/6/20.
//  Copyright © 2020 ETADO. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
int n,k;
int C[N], D[N]; //Cost và số đỉnh có thể đi qua
int dist[N][N];
vector <int> graph[N]; //đồ thị các thành phố

void bfs(int source, int d[]){
    queue<int> Q;
    Q.push(source);
    for (int i = 1; i <= n; i++){
        d[i] = INT_MAX;
    }
    d[source] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int v: graph[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << d[i] << "  " ;
    }
    cout << "\n";
}

void caculate_dist (){
    for (int i = 1; i <= n; i++){
        bfs(i, dist[i]);
    }
}

int ans[N];
int visited[N];

void dijkstra(){
    for(int i = 0; i <= n; i++){
        ans[i] = INT_MAX;
        visited[i] = 0;
    }
    
    ans[1] = 0;
    int step = n;
    while (step--){
        int u = 0;
        for (int i = 1; i <= n; i++){
            if(visited[i] == 0 and ans[u] > ans[i])
                u = i;
        }
        if(u == 0) break;
        
        visited[u] = 1;
        for(int i = 1; i <= n; i++){
            if(dist[u][i] <= D[u])
                ans[i] = min(ans[i], ans[u] + C[u]);
        }
    }
    cout << ans[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> C[i] >> D[i];
    }
    int x1, x2;
    for(int i = 1; i <= k; i++){
        cin >> x1 >> x2;
        graph[x1].push_back(x2);
        graph[x2].push_back(x1);
    }
    caculate_dist();
    dijkstra();
}
