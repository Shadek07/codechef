
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

char in[1000002];
int ind1, ind2;
map<char, int> mp;

struct node
{
	unsigned long long int cnt[4]; //c,h,e,f
	unsigned long long int str[4][4];
}T[2097155];

void precalculate(int n, int l, int r)
{
	if(l == r)
	{
		ms(T[n].str,0);
		ms(T[n].cnt,0);
		T[n].cnt[mp[in[l]]] = 1;
		return;
	}
	
	int mid = (l+r)/2;
	precalculate(2*n+1,l,mid);
	precalculate(2*n+2,mid+1,r);
	int i,j;
	int lft = 2*n+1;
	int rht = 2*n+2;
	forl(i,0,4)
	{
		T[n].cnt[i] = T[lft].cnt[i] + T[rht].cnt[i];
	}
	forl(i,0,4)
	{
		forl(j,0,4)
		{
			if(i == j)
				continue;
			T[n].str[i][j] = T[lft].str[i][j] + T[rht].str[i][j] + (T[lft].cnt[i]*T[rht].cnt[j]);
		}
	}
}

unsigned long long int query(int n, int l, int r, int ql, int qr)
{
	if(l >= ql && r <= qr)
	{
		return T[n].str[ind1][ind2];
	}
	unsigned long long int ans = 0;
	int mid = (l+r)/2;
	if(ql <= mid)
		ans +=  query(2*n+1,l,mid,ql,qr);
	if(qr >= mid+1)
		ans +=  query(2*n+2,mid+1,r,ql,qr);
	return ans;
	
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    mp['c'] = 0;
    mp['h'] = 1;
    mp['e'] = 2;
    mp['f'] = 3;
    int q;
    char a,b;
    int l,r;
    int len;
    //T = (node *)malloc(sizeof(int)*20*26505000);
    while(gets(in))
	{
		
		scanf("%d",&q);
		len = strlen(in);
		precalculate(0,0,len-1);
		//cout << T[0].cnt[0] << endl;
		//cout << T[0].str[0][1] << endl;
		getchar();
		while(q--)
		{
			scanf("%c %c %d %d",&a,&b,&l,&r);
			getchar();
			ind1 = mp[a];
			ind2 = mp[b];
			l--;
			r--;
			unsigned long long int ans = query(0,0,len-1,l,r);
			cout << ans << endl;
		}
		
	}
    return 0;
}
