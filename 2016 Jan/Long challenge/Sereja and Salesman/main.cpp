
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
#include<climits>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

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
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 101
#define INF 9999999
#define SZ 10
#define MOD 1000000007
map<int, int> mp;
int n,m;
int total;

int dp[MAX][1025][SZ];
int fact[MAX];
bool adjMat[SZ][SZ];
int getMult(long long a, long long b){
    long long res = ((a%MOD)*(b%MOD))%MOD;
    return res;
}

int doit(int index, int mask, int last){
    long long ans = 0;
    long long tmp;
    if(index == n){
        return 1;
    }
    if(dp[index][mask][last] != -1){
        return dp[index][mask][last];
    }
    int mask_check = ((1<<(total-1))-1)<<1;
    if(mask_check == mask){
        ans = fact[n-index];
        dp[index][mask][last] = ans;
        return ans;
    }
    int i;
    forl(i,1,total){
        if((mask & (1<<i)) == 0 && !adjMat[last][i]){
            ans = (ans + doit(index+1,mask|(1<<i), i) )%MOD;
        } 
    }
    
    int num = n - (total - 1);
    if(num){
        int more = num - (index - __builtin_popcount(mask) );
        if(more > 0){
            tmp = doit(index+1,mask,0);
            ans = (ans +  getMult(tmp,more))%MOD;
        }
    }
    
    dp[index][mask][last] = ans;
    return ans;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int i,j,k;
    cin >> t;
    
    int a,b;
    long long ans;
    long long tmp;
    fact[0] = 1;
    forl(i,1,MAX){
        fact[i] = getMult(fact[i-1],i);
    }
    while(t--){
        scanf("%d %d",&n,&m);
        mp.clear();
        total = 1;
        ms(adjMat,false);
        forl(i,0,m){
            scanf("%d %d",&a,&b);
            if(!mp[a])
                mp[a] = total++;
            if(!mp[b]){
                mp[b] = total++;
            }
            adjMat[mp[a]][mp[b] ] = true;
            adjMat[mp[b]][ mp[a]] = true;
        }
        if(n > 100){
            cout << 0 << endl;
            continue;
        }
        ms(dp,-1);
        ans = 0;
        ans = doit(0,0,0);
        cout << ans << endl;
    }
    return 0;
}
