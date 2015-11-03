
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

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

long long int dp[101][101][2];
bool ch[101][101][2];
int arr[101];
long int mod;
int n;
long long int doit(int i, int j,int taken)
{
	if(i>j)
	{
		if(taken)
		return 1;
		return 0;
	}
	if(i == j)
	{
       if(taken)
	   return 1;
	   return 0;
	}
	if(ch[i][j][taken])
	   return dp[i][j][taken];
	
	long long int ans=0;
	int k;
	ans = 0;
	if(arr[i] < 0 && arr[i] == -arr[j])
	{
		ans +=  doit(i+1,j-1,1);
		ans %= mod;
	}
	
	
	for(k=i;k<j;k++)
	{
		ans += doit(i,k,0);
		ans %= mod;
		ans += doit(k+1,j,0);
		ans %= mod;
	}
	
	ch[i][j][taken] = true;
	dp[i][j][taken] = ans;
	return dp[i][j][taken];
}

bool check(long int bit)
{
	int i;
	stack<int> st;
	forl(i,0,n)
	{
		if(bit&(1<<i))
		{
			if(arr[i] < 0)
				st.push(arr[i]);
			else
			{
				if(st.empty())
				return false;
				int a = st.top();
				st.pop();
				if(a != -arr[i])
				   return false;
			}
		}
	}
	if(st.empty())
	return true;
	return false;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i,j,k;
    
    mod = 1000000007;
    while(cin >> n)
    {
    	forl(i,0,n)
    	{
    		cin >> arr[i];
    	}
    	
    	//memset(ch, false, sizeof(ch));
    	//memset(dp, 0, sizeof(dp));
    	//cout << (doit(0,n-1,0))%mod << endl;
    	if(n > 20)
    	{
    		cout << 0 << endl;
    		continue;
    	}
    	int cnt=0;
    	forl(i,0,(1<<n))
    	{
    		if(check(i))
    		cnt++;
    	}
    	
    	cout << cnt << endl;
    }
    return 0;
}
