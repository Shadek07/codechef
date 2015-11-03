
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
#define ll  long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

long long int MOD;

unsigned long long factMod1(unsigned long long int n, unsigned long long int p)
{
	unsigned long long int res = 1;
	unsigned long long int i;
	unsigned long long int m;
	while(n > 0)
	{
		for (i = 1, m = n % p; i <= m; i++) 
		{
			res = (res * i) % p;
			if(res == 0)
				return 0;
		}
			
         if ((n /= p) % 2 > 0) res = p - res; 
         if(res == 0)
				return 0;
	}
	return res%p;
}


ll powmod(ll a, ll b)
{
  ll x=1,y=a;
  while(b)
  {
    if(b&1)
    {
      //x*=y; 
      x = (x%MOD*y%MOD)%MOD;
      //if(x>=MOD)x%=MOD;
    }
  
    //y*=y; if(y>=MOD)y%=MOD;
    y = (y%MOD*y%MOD)%MOD;
    b>>=1;
    
  }
  return x;
} 




int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    long long int n,m;
     long long int ans = 0;
     long long int p;
    long long int p1;
    
    
    scanf("%lld %lld",&n,&m);
    //cout << n << " " << m << endl;
    long long int * fact = new  long long int[10000002];
    fact[0] = fact[1] = 1;
    long long int i;
    forl(i,2,m+2)
    {
    	long long int temp = i;
    	fact[i] = ((fact[i-1])%m*(temp)%m)%m;
    }
    
    MOD = m;
    //unsigned long long int x = powmod(2,10000005);
    
    //cout << fact[3] << endl;
    long long int pi[100002];
    forl(i,0,n)
    {
    	scanf("%lld",&pi[i]);
    }
    
    sort(pi,pi+n);
    reverse(pi,pi+n);
    
    forl(i,0,n)
    {
    	//scanf("%llu",&p);
    	p = pi[i];
    	long long int t = 0;
    	
    	if(p&1)
		{
			t = (p+1);
			t /= 2;
			t = ((t)%m*(p)%m)%m;
			t = ((t)%m*(p)%m)%m;
		}
		else
		{
			t = (p);
			t /= 2;
			t = ((t)%m*(p+1)%m)%m;
			t = ((t)%m*(p)%m)%m;
		}
		

		//t = (t + factMod(p+1,m))%m;
		//t -= 1;
		
		long long int temp = 0;
		if(p+1 < m)
			temp = fact[p+1]%m;
	     
		//unsigned long long int j;
		//forl(j,2,p+2)
		//{
			//temp = (temp*j)%m;
		//}
		//t = (t+temp)%m;
		ans = (ans + t + temp)%m;
		
		//ans = (ans + neg)%m;
		
    }
    long long int neg = -n;
	while(neg < 0)
			neg += m;
	ans = (ans+neg)%m;
    printf("%lld\n",(ans));
    
    return 0;
}

