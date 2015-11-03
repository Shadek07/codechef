
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
#define mod 1000000007
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

struct edge
{
	ull l1,l2;
	ull v1,v2;
}ed[50002];

unsigned long long int n,m,k;

int comp(edge e1, edge e2)
{
	if(e1.l1 < e2.l1)
		return 1;
	else if(e1.l1 == e2.l1 && e1.l2 > e2.l2)
		return 1;
	return 0;
	//if(e1.l2 < e2.l2)
		//return 1;
	//else if(e1.l2 == e2.l2 && e1.l1 < e2.l1)
		//return 1;
	//return 0;
}

unsigned long long int modpow(unsigned long long int base,unsigned long long int p)
{
	unsigned long long int ans=1;
	unsigned long long int y = base;
	while(p)
	{
		if(p&1)
		{
			ans = (ans%mod*y%mod)%mod;
			//if(ans >= mod)
				//ans%= mod;
		}
		y = ((y)%mod*(y)%mod)%mod;
		//if(y>=mod)
			//y%=mod;
		p >>=1;
	}
	return ans;
}
unsigned long long get_cnt(unsigned long long int l1)
{
	if(l1 <= 1)
		return 0;
	else
		return l1 - 1;
}

unsigned long long get_cnt1(unsigned long long int l2)
{
	if(l2 >= n)
		return 0;
	else
		return (n+1) - l2 - 1;
}

unsigned long long get_middle(unsigned long long int l1, unsigned long long int l2)
{
	unsigned long long int a = l2 - l1;
	if(a <= 1)
		return 0;
	else
		return a - 1;
}

bool earlier_end_point_check(int i, int j)
{
	if(((ed[i].l2 < ed[j].l1) || (ed[i].l2 == ed[j].l1 && ed[i].v2 == ed[j].v1) ))
	{
		return true;
	}
	return false;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    
    //cout << modpow(2,9) << endl;
    unsigned long long int res[42];
    cin >> n >> m >> k;
    int a,b,i,j;
    j = 0;
    forl(i,0,k)
    {
    	//cin >> ed[j].l1 >> ed[j].v1 >> ed[j].l2 >> ed[j].v2;
    	scanf("%d %d %d %d",&ed[j].l1, &ed[j].v1,&ed[j].l2,&ed[j].v2);
    	//if(ed[j].l2-ed[j].l1 == 1);
    	//else j++;
    	j++;
			
    }
    
    sort(ed,ed+j,comp);
    unsigned long long int ans = 0;
    /*if( k <= 2)
	{
		k = j;
		
		unsigned long long int p;
		forl(i,0,k)
		{
			if(ed[i].l1 <= 1)
				p = 0;
			else
				p = ed[i].l1 - 1;
			unsigned long long int p1;
			if(ed[i].l2 >= n)
				p1 = 0;
			else
				p1 = (n+1) - ed[i].l2 - 1;
			p += p1;
			ans = (ans + modpow(m,p))%mod;
		}
		
		if(k == 2 && ((ed[0].l2 < ed[1].l1) || (ed[0].l2 == ed[1].l1 && ed[0].v2 == ed[1].v1) ))
		{
			p = get_cnt(ed[0].l1) + get_middle(ed[0].l2,ed[1].l1) + get_cnt1(ed[1].l2);
			ans = (ans + modpow(m,p))%mod;
		}
		
		ans = (ans + modpow(m,n))%mod;
		//cout << ans << endl;
		printf("%llu\n",ans);
	}*/
	ull t3;
	if( k <= 40)
	{
		forl(i,0,k)
		{
			res[i] = modpow(m,get_cnt(ed[i].l1)); //direct
			forl(j,0,k) //via j
			{
				if(earlier_end_point_check(j,i))
				{
					t3 = modpow(m,get_middle(ed[j].l2,ed[i].l1))%mod;
					unsigned long long int t1 = ((res[j]%mod)*(t3))%mod;
					res[i] = (res[i] + t1)%mod;
				}
			}
		}
		
		ans = 0;
		forl(i,0,k)
		{
			t3 = modpow(m,(get_cnt1(ed[i].l2)))%mod;
			unsigned long long int t2 = ((res[i]%mod)*t3)%mod;
			ans = (ans + t2)%mod;
		}
		
		ans = (ans + modpow(m,n))%mod;
		
		printf("%llu\n",ans);
	}
	else
	{
		cout << 0 << endl;
	}
    return 0;
}
