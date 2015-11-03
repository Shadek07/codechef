
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

vpii vpii1;

int comp(pii p1, pii p2)
{
	
	if(p1.second < p2.second)
		return 1;
	
	return 0;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n;
    int i,j,k;
    int a,b;
    int t;
    cin >> t;
    pii p1;
    while(t--)
	{
		scanf("%d",&n);
		vpii1.clear();
		forl(i,0,n)
		{
			scanf("%d %d",&a,&b);
			p1 = make_pair(a,b);
			vpii1.push_back(p1);
		}
		sort(all(vpii1),comp);
		int limit = -1;
		int ans = n;
		forl(i,0,n)
		{
			p1 = vpii1[i];
			if(p1.first <= limit)
			{
				ans--;
			}
			else
			{
				limit = p1.second;
			}
		}
		cout << ans << endl;
	}
    return 0;
}

