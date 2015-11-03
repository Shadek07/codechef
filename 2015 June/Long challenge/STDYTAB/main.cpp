
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
#define MOD 1000000000
long long int dp[2001][2001];
long long int ncr[4001][2001];
long long int prev[2001];
int n,m;
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    //cin >> t;
    scanf("%d",&t);
    int i,j,k;
    //long long int **ncr = new long  long int*[4001];
    //long long int *prev = new long long int[2001];
    
    /*forl(i,0,4001)
    {
        ncr[i] = new long long int[2001];
    }*/
    /*forl(i,0,4001)
    {
        forl(j,0,2001)
            ncr[i][j] = 0;
    }*/
    
    //ms(ncr,0);
    
    ncr[0][0] = 1;
    forl(i,1,4001)
    {
        ncr[i][0] = 1;
        ncr[0][i] = 0;
    }
    
    forl(i,1,4001)
    {
        ncr[i][0] = 1;
        int mn = min(2001,i+1);
        forl(j,1,mn)
        {
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%MOD;
        }
    }
    //cout << ncr[2000][200] << endl;
    while(t--)
    {
        //cin >> n >> m;
        scanf("%d %d",&n,&m);
        ms(dp,0);
        prev[0] = 1;
        dp[0][0] = 1;
        forl(i,1,m+1)
        {
            dp[0][i] = ncr[i+m-1][m-1];
            prev[i] = (prev[i-1] + dp[0][i]);
            if(prev[i] >= MOD)
                prev[i] -= MOD;
        }
        //cout << dp[0][0] << endl;
        long long int ans = 0;
        forl(i,1,n)
        {
            long long int cur = 0;
            long long int tmp[m+1];
            dp[i][0] = (0 + ((prev[0])*(ncr[m-1][m-1]))%MOD);
            tmp[0] = dp[i][0];
            for(j=1;j<=m;j++)
            {
                //forl(k,0,j+1)
                //{
                   //dp[i][j] = (dp[i][j] + ((dp[i-1][k]%MOD)*(ncr[j+m-1][m-1]%MOD))%MOD)%MOD;            
                //}
                dp[i][j] = (0 + ((prev[j])*(ncr[j+m-1][m-1]))%MOD); 
                tmp[j] = (tmp[j-1] + dp[i][j]);
                if(tmp[j] >= MOD)
                    tmp[j] -= MOD;
            }
            /*for(j=0;j<=m;j++)
            {
                prev[j] = tmp[j];
            }*/
            
            memcpy(prev,tmp,(m+1)*(sizeof(long long int)));
            //if(i == n-1)
            //{
                //ans = (ans + dp[n-1][i]%MOD)%MOD;
            //}
        }
        
        forl(i,0,m+1)
        {
            //ans = (ans + ((dp[n-1][i]%MOD)*(ncr[i+m-1][m-1]%MOD))%MOD)%MOD;
            ans = (ans + dp[n-1][i]);
            if(ans >= MOD)
                ans -= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
