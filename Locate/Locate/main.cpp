//
//  main.cpp
//  Locate
//
//  Created by Võ Đức Quân
//  23-04-2020
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define MAX 1000

vector< vector<int> > res(2*MAX, vector<int>(2*MAX));
int result[MAX];
int n, L, C;
int x;
vector< pair<int, int> > mn, ml;

int main() {
    
    cin >> n;
    for (int k = 0; k < n; k++){
        result[k] = INT_MIN;
        cin >> L >> C;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++){
                if((cin >> x) && x) mn.push_back({i,j});
            }
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++){
                if((cin >> x) && x) ml.push_back({i,j});
            }
        for (int i = 0; i < mn.size(); i++){
            for (int j = 0; j < ml.size(); j++){
                res[mn[i].fi - ml[j].fi + L][mn[i].se - ml[j].se + C]++;
            }
        }
        
        for (int i = 0; i < 2*MAX; i++){
            for (int j = 0; j < 2*MAX; j++){
                if(res[i][j] > result[k]) result[k] = res[i][j];
            }
        }
        for (int i = 0; i < 2*MAX; i++){
            for (int j = 0; j < 2*MAX; j++){
                res[i][j] = 0;
            }
        }
        mn.clear();
        ml.clear();
    }
    for (int k = 0; k < n; k++)
        cout << result[k] << endl;
    return 0;
}
