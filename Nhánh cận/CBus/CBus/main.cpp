//
//  main.cpp
//  CBus
//
//  Created by Võ Đức Quân
//  23-04-2020
//

#include <bits/stdc++.h>
using namespace std;

#define Fr(i,a,b) for(int i=a;i<=b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define Frd(i,a,b) for(int i=a;i>=b;i--)
#define Ford(i,a,b) for(int i=a;i>b;i--)
#define dembit1(x) __builtin_popcountll(x)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
const int mod=1e9+7;
const int oo=INT_MAX-1;
const ll lloo=1e17+11;
const int N=30;
int n,k,a[N][N],cnt,amin;
ll ans;
bool dd[N],d[N];

void dfs(int u,int kn,ll cost)
{
    if(cnt==n+n)
    {
        ans=min(ans,cost+a[u][0]);
        return;
    }
    Fr(i,1,n) if(!dd[i] && kn)
    {
        //        ll g=cost+a[u][i];
        ll g=cost+1ll*amin*(n+n-cnt+2);
        if(g < ans)
        {
            dd[i]=d[n+i]=1,cnt++;
            dfs(i,kn-1,cost+a[u][i]);
            dd[i]=d[n+i]=0,cnt--;
        }
    }
    Fr(i,n+1,n+n) if(d[i] && !dd[i])
    {
        //        ll g=cost+a[u][i];
        ll g=cost+1ll*amin*(n+n-cnt+2);
        if(g<ans)
        {
            dd[i]=1,cnt++;
            dfs(i,kn+1,cost+a[u][i]);
            dd[i]=0,cnt--;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    amin=oo;
    ans=lloo;
    Fr(i,0,n+n) Fr(j,0,n+n)
    {
        scanf("%d",&a[i][j]);
        if(i!=j) amin=min(amin,a[i][j]);
    }
    dd[0]=1;
    dfs(0,k,0ll);
    printf("%lld",ans);
    return 0;
}
