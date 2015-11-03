
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

struct data
{
	unsigned long long int cnt[4];
	unsigned long long int good[4][4];
	
}prefix[1000002];

map<char, int> mp;

char in[1000002];

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    mp['c'] = 0;
    mp['h'] = 1;
    mp['e'] = 2;
    mp['f'] = 3;
    int n;
    gets(in+1);
    n = strlen(in+1);
    n++;
    int i,j,k,x,y;
    char a,b;
    int l,r;
    int q;
    scanf("%d",&q);
    
    getchar();
    
    ms(prefix[0].cnt,0);
    ms(prefix[0].good,0);
    
    forl(i,1,n)
    {
    	j = mp[in[i]];
    	
    	forl(k,0,4)
    	{
    		if(k == j)
			{
				prefix[i].cnt[j] = prefix[i-1].cnt[j] + 1;
			}
			else
			{
				prefix[i].cnt[k] = prefix[i-1].cnt[k];
			}
    	}
    	
    	forl(x,0,4)
    	{
    		forl(y,0,4)
    		{
    			if(x == y)
					continue;
    			if(y == j)
				{
					prefix[i].good[x][y] = prefix[i-1].good[x][y] + prefix[i-1].cnt[x];
				}
				else
				{
					prefix[i].good[x][y] = prefix[i-1].good[x][y];
				}
    		}
    	}
    }
    
    while(q--)
	{
		scanf("%c %c %d %d",&a,&b,&l,&r);
		getchar();
		int ind1 = mp[a];
		int ind2 = mp[b];
		unsigned long long int b_inside = prefix[r].cnt[ind2] - prefix[l-1].cnt[ind2];
		unsigned long long int ans = prefix[r].good[ind1][ind2];
		ans -= prefix[l-1].good[ind1][ind2];
		ans -= (prefix[l-1].cnt[ind1]*b_inside);
		printf("%llu\n",ans);
		//cout << ans << endl;
	}
    return 0;
}
