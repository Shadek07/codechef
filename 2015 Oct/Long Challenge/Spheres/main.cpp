
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<sstream>
#include<stack>
#include<list>
#include <bitset>
#include<iomanip>
#include <fstream>
#include<ctime>

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define MX 1000000

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define MOD 1000000007
#define ulli unsigned long long int
ulli radiCount[1001];
map<int,ulli> mpUp;
map<int,ulli> mpDown;
ulli dp[1001][1001];
void mxAssign(int &mx, int b){
    mx = max(mx,b);
}
void mnAssign(int &mn, int b){
    mn = min(mn,b);
}
ulli modMinimize(ulli a, ulli b){
    return ((a%MOD)*(b%MOD))%MOD;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n,m,c;
    int i,j,k;
    int a,b;
    scanf("%d %d %d",&n,&m,&c);
    mpUp.clear();
    mpDown.clear();
    int mx,mn;
    mx = 1;
    mn = 1000;
    bool vis[1001];
    ms(vis,false);
    int cnt = 0;
    forl(i,0,n){
        scanf("%d",&a);
        vis[a]=true;
        mxAssign(mx,a);
        mnAssign(mn,a);
        if(mpUp[a])
            mpUp[a]++;
        else
            mpUp[a] = 1;
    }
    forl(i,0,m){
        scanf("%d",&a);
        if(vis[a]){
            cnt++;
            vis[a] = false;
        }
        mxAssign(mx,a);
        mnAssign(mn,a);
        if(mpDown[a])
            mpDown[a]++;
        else
            mpDown[a] = 1;
    }
    forl(i,mn,mx+1){
        radiCount[i] = modMinimize(mpUp[i],mpDown[i]);
    }
    int x = cnt-1;
    int y = min(x,c);
    ulli prefix[1001];
    ulli next[1001];
    for(i=mx; i>=mn;i--){
        dp[0][i] = radiCount[i]%MOD;
        if(i == mx)
            prefix[i] = dp[0][i]%MOD;
        else
            prefix[i] = (prefix[i+1] + dp[0][i])%MOD;
    }
    bool fir=true;
    forl(k,1,y+1){
        for(i=mx-k;i>=mn;i--){
            dp[k][i] = modMinimize(prefix[i+1],radiCount[i]);
            if(i == mx-k){
                next[i] = dp[k][i]%MOD;
            }
            else{
                next[i] = (next[i+1] + dp[k][i])%MOD;
            }
        }
        if(k==1){
            //cout << next[mn];
            printf("%llu",next[mn]);
            fir = false;
        }
        
        else
            //cout << " " << next[mn];
            printf(" %llu",next[mn]);
        //memcpy ( &prefix, &next, sizeof(next) );
        forl(i,mn,mx-k+1){
            prefix[i] = next[i];
        }
    }
    forl(i,y+1,c+1){
        if(fir){
           printf("0");
           fir = false; 
        }
        else
            printf(" 0");
    }
    cout << endl;
    return 0;
}
