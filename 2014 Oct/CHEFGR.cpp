
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
    int t,n,m;
    int i,j,k;
    cin >> t;
    vector<int> v;
    int mx;
    while(t--)
    {
    	cin >> n >> m;
    	v.clear();
    	forl(i,0,n)
    	{
    		cin >> k;
    		v.push_back(k);
    	}
    	mx = *max_element(v.begin(), v.end());
    	int cnt = 0;
    	forl(i,0,n)
    	{
    		cnt += (mx-v[i]);
    	}
    	if(cnt > m)
    	{
    		cout << "No\n";
    		v.clear();
    		continue;
    	}
		if(cnt != 0)
		cnt = m - cnt;
    	if(cnt == 0 || (cnt > 0 && cnt%n == 0))
    	cout << "Yes\n";
    	else
    	cout << "No\n";
    	v.clear();
    }
    return 0;
}

