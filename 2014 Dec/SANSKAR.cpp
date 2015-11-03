
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

bool taken[25];
bool found;
long int intens[25];
long int per;
int f;
int n;
long int mn;

map< pair<pair<int,int>, long int>, bool> mp;

map< pair<pair<int,int>, long long int>, bool> mp_long;

void doit(int bit,long long int sum, int cnt)
{
	if(cnt == f-1 && sum == 0)
	{
		found = true;
		return;
	}
	long int maxi=0;
	int ind;
	int i,j;
	
	pair<pair<int,int>, long int> struc;
	pair<pair<int,int>,long long int> struc_long;
	pair<int,int> pr;
	pr = make_pair(bit,cnt);
	struc = make_pair(pr,sum);
	struc_long = make_pair(pr,sum);
	if(sum >= 2147483646 && mp_long[struc_long])
	return;
	if(sum < 2147483646 && mp[struc])
	return;
	forl(i,0,n)
	{
		if(taken[i] == 0 && maxi < intens[i])
		{
			ind = i;
			maxi = intens[i];
		}
	}
	if(sum + intens[ind] == per)
	{
		taken[ind] = true;
		doit(bit|(1<<ind),0, cnt+1);
		taken[ind] = false;
	}
	else if((per - sum - intens[ind]) >= mn)
	{
		taken[ind] = true;
		doit(bit|(1<<ind),sum + intens[ind], cnt);
		taken[ind] = false;
	}
	
	if(found)
	return;
	
	forl(i,0,n)
	{
		if(found)
		return;
		if(taken[i] == false && sum + intens[i] <= per)
		{
			//cout << "inside\n";
			
			if(sum + intens[i] == per)
			{
				taken[i] = true;
				doit(bit|(1<<i),0, cnt+1);
				taken[i] = false;
			}
			else if((per - sum - intens[i]) >= mn)
			{
				taken[i] = true;
				doit(bit|(1<<i),sum + intens[i], cnt);
				taken[i] = false;
			}
		}
	}
	
	if(sum<2147483646)
	mp[struc] = true;	
	else
	mp_long[struc_long] = true;
	
}

bool divisible(int by)
{
	bool ch=true;
	int i;
	forl(i,0,n)
	{
		if(intens[i]%10 != 0)
		   return false;
	}
	return ch;
}
bool all_zero()
{
	int i;
	forl(i,0,n)
	{
		if(intens[i] != 0)
		   return false;
	}
	return true;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int i,j,k;
    long int test = 1e10;
    cout << test << endl;
    cin >> t;
    
    long long int sum;
    long long int mx;
	int zero_cnt;
	int arr_revised[22];
	bool ch[22];
    while(t--)
    {
    	cin >> n >> f;
    	mp.clear();
    	mp_long.clear();
    	
    	sum = 0;
    	zero_cnt = 0;
    	memset(ch, true, sizeof(ch));
    	forl(i,0,n)
    	{
    		cin >> intens[i];
    		sum += intens[i];
    		
    		if(intens[i] == 0)
				zero_cnt++;
    		if(i == 0)
    		{
				mn = intens[0];
				mx = intens[0];
    		}
    		else
    		{
				mn = min(mn,intens[i]);
				mx = max(mx,intens[i]);
    		}
    	}
    	
    	sort(intens, intens+n);
    	
    	while(divisible(1000) && !all_zero())
    	{
    		forl(i,0,n)
    		   intens[i] /= 1000;
    	}
    	while(divisible(100)&& !all_zero())
    	{
    		forl(i,0,n)
    		   intens[i] /= 100;
    	}
    	while(divisible(10)&& !all_zero())
    	{
    		forl(i,0,n)
    		   intens[i] /= 10;
    	}
    	while(divisible(5)&& !all_zero())
    	{
    		forl(i,0,n)
    		   intens[i] /= 5;
    	}
    	while(divisible(2)&& !all_zero())
    	{
    		forl(i,0,n)
    		   intens[i] /= 2;
    	}
    	while(divisible(3)&& !all_zero())
    	{
    		forl(i,0,n)
    		   intens[i] /= 3;
    	}
    	
    	sum = 0;
    	forl(i,0,n)
    	{
    		sum += intens[i];
    	}
    	
    	per = sum/f;
    	if(sum%f != 0)
    	{
    		cout << "no\n";  		
    		continue;
    	}
    	if(mx > per)
    	{
    		cout << "no\n";  		
    		continue;
    	}
    	
    	//cout << per << endl;
    	found = false;
    	memset(taken, false, sizeof(taken));
    	doit(0,0,0);
    	if(found)
    	cout << "yes\n";
    	else
    	cout << "no\n";
    }
    return 0;
}
