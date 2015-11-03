
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

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

bool check(long long int remaining,long long int cur,long long int sum)
{
	if(remaining < 0)
		return true;
	long long int a,b;
	a = remaining*cur;
	b = (2*(cur+1) + (remaining-1))*remaining;
	b /= 2;
	if( sum >= a && sum <= b)
		return true;
	return false;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    long long int n,s;
    long long int i,j,k;
    cin >> t;
    while(t--)
	{
		cin >> n >> s;
		long long int cur = 1;
		long long int rS = s - 1;
		i = 2;
		while(i<=n)
		{
			if(check(n-i,cur,rS-cur))
			{
				rS -= cur;
			}
			else
			{
				cur++;
				rS -= cur;
			}
			
			i++;
		}
		
		cout << n-cur << endl;
	}
    return 0;
}


