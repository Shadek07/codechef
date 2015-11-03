
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

int comp(pii p1, pii p2)
{
	if(p1.first < p2.first)
	return 1;
	else return 0;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int n,m;
    int i,j,k,a,b;
    char c;
	cin >> t;
	pii p1;
	vpii vp;
	long long int ans = 1;
	int arr[100001];
	while(t--)
	{
		cin >> n >> m;
		
		vp.clear();
		memset(arr,0,sizeof(arr));
		forl(i,0,m)
		{
			cin >> c >> a;
			getchar();
			
			b = c - 'A' + 1;
			//p1.first = a;
			//p1.second = b;
			//vp.push_back(p1);
			arr[a] = b;
		}
		
		//sort(vp.begin(), vp.end(), comp);
		ans = 1;
		int prev;
		for(i=1;i<=n;i++)
		{
			if(arr[i] != 0)
			{
				prev = i;
				break;
			}
		}
		//cout << prev << endl;
		i++;
		
		for(;i<=n;i++)
		{
			//cout << vp[i].first << " " <<  vp[i-1].first << endl;
			if(arr[i] != 0 && arr[i] != arr[prev])
			{
				a = i - prev;
				a += 2;
				//cout << arr[i] << " " << arr[prev] << endl;
				//cout << a << endl;
				ans %= 1000000009;
				ans = (ans*a)%1000000009;
				prev = i;
			}
		}
		
		cout << ans << endl;
		
		
	}
    return 0;
}
