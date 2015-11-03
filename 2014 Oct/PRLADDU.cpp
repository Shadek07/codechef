
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

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n;
    int a[100001];
    int b;
    int i,j,k;
	int t;
	cin >> t;
	long long int ans;
	int cur;
	while(t--)
	{
		cin >> n;
		forl(i,0,n)
		{
			cin >> a[i];
		}

		ans = 0;
		if(n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		forl(i,1,n)
		{
			b = a[i-1];
			cur = a[i];
			if(b < 0)
			{
				if(cur < 0)
				{
					ans += abs(b);
					a[i] -= abs(b);
				}
				else if(cur >= 0)
				{
					if(cur >= abs(b))
					{
						a[i] += b;
						ans += abs(b);
					}
					else
					{
						a[i] += b;
						ans += abs(b);
					}
				}

			}
			else if(b > 0)
			{
				if(cur < 0)
				{
					if(cur >= abs(b))
					{
						a[i] += b;
						ans += abs(b);
					}
					else
					{
						a[i] += b;
						ans += b;
					}
				}
				else if(cur >= 0)
				{
					a[i] += b;
					ans += b;
				}
			}

		}

		cout << ans << endl;
	}
    return 0;
}

