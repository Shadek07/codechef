
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

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int sum[100002];
    char in[100002];
    int n,m;
    int i,j,k;
    scanf("%d %d",&n,&m);
    int t,x,y;
    getchar();
    gets(in);
    sum[0] = 0;
    //if(n<=1000)
    forl(i,0,n)
    {
    	sum[i+1] = sum[i] + (in[i] - '0');
    }
    //cout << sum[5] << endl;
    forl(k,0,m)
    {
    	scanf("%d %d %d",&t,&x,&y);
    	int cnt = 0;
    	if(t == 2)
		{			
			//if(n <= 1000)
			//{
				
				for(i = y; i>=x;i--)
				{
					forl(j,x-1,i)
					{
						if((sum[i] - sum[j]) %3 == 0)
							cnt++;
					}
				}
				cout << cnt << endl;
			
		}
		else
		{
			if(x <= 1000)
				in[x-1] = y + '0';
			
			forl(i,x-1,n)
			{
				sum[i+1] = sum[i] + (in[i] - '0');
			}
		}
		
    }
    return 0;
}

