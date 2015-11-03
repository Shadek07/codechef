
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

char in[100001];
int n;
int mx;
int F()
{
	mx = 0;
	int b = 0;
	int i;
	forl(i,0,n)
	{
		if(in[i] == '(')
		    b++;
		else
		   b--;
		mx = max(mx,b);
	}
	
	return mx;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i,j;
    int t;
    cin >> t;
    getchar();
    while(t--)
    {
		gets(in);
		n = strlen(in);
		int a = F();
		forl(i,0,a)
		cout << '(';
		forl(i,0,a)
		cout << ')';
		cout << endl;
    }
    return 0;
}
