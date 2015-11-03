
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

long long int k;
long double x;
long long int lst;

int find_last_sweep()
{
	unsigned long long int sum = 0;
	int i=0;
	while(true)
	{
		sum += pow(2.0, i);
		if(sum >= k)
		{
			lst = sum - pow(2.0, i);
		    return i;
		}
		i++;
	}
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    int i,j;
    long long int remaining;
    double a,b,c;
    while(t--)
    {
    	cin >> x >> k;
    	if(k == 1)
    	{
    		cout << x/2 << endl;
    		continue;
    	}
    	
    	i = find_last_sweep();
    	remaining = k - lst;
    	
    	a = x/pow(2.0,i+1);
    	b = a*2.0;
    	c = a;
    	c += b*(remaining-1);
    	printf("%.10lf\n",c);
    	//cout << c << endl;
    }
    return 0;
}
