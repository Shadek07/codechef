
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

long long int dp[101][101];
bool ch[101][101];
int arr[101];
long int mod;
int n;
long long int doit(int i, int j)
{
	if(i>=j)
	{
		return 1;
	}
	if(arr[i] > 0)
	   return doit(i+1,j);
	   
	if(ch[i][j])
	   return dp[i][j];
	
	int a,b,c,d;
	
	long long int ans= doit(i+1,j);
	
	//if(arr[i] < 0 && arr[i] == -arr[j])
	//{
		//ans +=  doit(i+1,j-1);
		//ans %= mod;
	//}
	long long int t1;
	long long int t2;
	long long int t3;
	for(a=i+1;a<=j;a++)
	{
		if(arr[a] == -arr[i])
		{										
			t1 = doit(i+1,a-1);
			t2 = doit(a+1,j);
			t3 = ((t1%mod)*(t2%mod))%mod;
			ans += t3;
			ans %= mod;
			
		}
	}
	
	ch[i][j] = true;
	dp[i][j] = ans;
	return ans;
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
    	
    	memset(ch, false, sizeof(ch));
    	memset(dp, 0, sizeof(dp));
    	cout << (doit(0,n-1))%mod << endl;
    	   	
    }
    return 0;
}
