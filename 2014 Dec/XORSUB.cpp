
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
long long int ans;

bool check(long long int with)
{
	int j;
	bool ok = false;
	for(j = 31; j>= 0; j--)
	{
		if((ans & (1<<j)) != 0 && (with & (1<<j)) != 0)
		{
			return false;
		}
		if((ans & (1<<j)) == 0 && (with & (1<<j)) != 0)
		{
			ok = true;
		}
	}
	return ok;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    
    int n,k;
    int i,j;
    int t;
    long long int a;
    long long int cur;
    //cout << (2 & (1<<1)) << endl;
    cin >> t;
    bool taken[1001];
    int arr[1001];
    while(t--)
    {
    	cin >> n >> k;
    	ans = k;
    	cur = k;
    	memset(taken, false, sizeof(taken));
    	
    	forl(i,0,n)
    	{
    		cin >> arr[i];
    		cur = max(arr[i],cur^arr[i]);
    		ans = max(cur,ans);
    	}
    	
    	
    	cout << ans << endl ;
    	
    }
    return 0;
}
