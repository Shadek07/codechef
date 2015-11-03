
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

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

int gcd1(int a, int b)
{
    if (b == 0) return a;
    return gcd1(b, a%b);
}

int gcd(int a, int b)
{
    while( b != 0)
	{
		int t = a;
		a = b;
		b = t%b;
	}
	return a;
}

map<pii, int> mp;
map<int,bool> mpleft,mpright;
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int prefix[100001];
    int suffix[100001];
    int a[100001];
    int n,q;
    int i,j,k;
    int t;
    scanf("%d",&t);
    int l,r;
    while(t--)
	{
		//cin >> n >> q;
		scanf("%d %d",&n,&q);
		forl(i,0,n)
			scanf("%d", &a[i]);
		
		mp.clear();
		mpleft.clear();
		mpright.clear();
	    prefix[0] = a[0];
	    forl(i,1,n)
	    {
	    	if(!mpleft[a[i]])
			{
				prefix[i] = gcd(prefix[i-1],a[i]);
				mpleft[a[i]] = true;
			}
			else
				prefix[i] = prefix[i-1];	    	
	    }
	    
	    /*suffix[n-1] = a[n-1];
	    for(i = n-2;i>=0;i--)
		{
			if(!mpright[a[i]])
			{
				suffix[i] = gcd(suffix[i+1],a[i]);
				mpright[a[i]] = true;
			}
			else
			{
				suffix[i] = suffix[i+1];
			}
			
		}*/
		
		forl(i,0,q)
		{
			
			scanf("%d %d", &l, &r);
			l--;
			r--;
			int ans = -1;
			if(l-1>=0)
				ans = prefix[l-1];
			forl(i,r+1,n)
			{
				if(ans == -1)
					ans = a[i];
				else
					ans = gcd(ans, a[i]);
			}
			cout << ans << endl;
		}
	}
    return 0;
}

