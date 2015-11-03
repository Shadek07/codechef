
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
#define M 1000000007
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

long int dp[1801][301][10];

int R,B,L;

long int doit(int r, int b, int l)
{
	long int &res = dp[r][b][l];
	
	if(b == 0)
	{
		if(r == 0)
		return 1;
		return 0;
	}
	
	if(6*b < r )
		return 0;
	
	if(dp[r][b][l] != -1)
		return dp[r][b][l];
    
    res = 0;
	
	if(r-6 >= 0)
		res = (res + doit(r-6,b-1,l))%M;
		
	if(r-4 >= 0)
	res = (res + doit(r-4,b-1,l))%M;
	
	if( (6*(b-1)) >= r)
	res = (res + doit(r,b-1,l))%M;	
	if((6*(b-1)) >= r)
	if(l-1 >= 0)
		res = (res + doit(r,b-1,l-1))%M;
    return res;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    //cin >> t;
    scanf("%d",&t);
    ms(dp,-1);
    while(t--)
	{
		//cin >> R >> B >> L;
		scanf("%d %d %d",&R,&B,&L);
		if( R > B*6)
		{
			//cout << 0 << endl;
			printf("%d\n",0);
			continue;
		}
		if( R&1)
		{
			printf("%d\n",0);
			continue;
		}
		
		if(dp[R][B][L] != -1)
		{
			printf("%d\n",dp[R][B][L]);
			//cout << "here\n";
			continue;
		}
		
		long int ans = doit(R,B,L);
		printf("%d\n",ans);
		
	}
    return 0;
}
