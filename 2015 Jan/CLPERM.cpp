
#pragma comment(linker,"/STACK:16777216")
#pragma warning ( disable: 4786)
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
typedef long long LL;
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
	vector<unsigned long long int> v;
	int i,j,k;
	int num;
	unsigned long long int n; 
	unsigned long long int not_found;
	int t;
	cin >> t;
	unsigned long long int a,b,c,mx;
	unsigned long long int info[100002][2];
	int cnt;
	
	while(t--)
	{
		cin >> n >> num;
		v.clear();
		forl(i,0,num)
		{
			cin >> j;
			v.push_back(j);
		}		
		
		sort(all(v));
		
		if(num == 0)
		{
			mx = (n)*(n+1);
			mx /= 2;
			mx ++;
			if(mx%2 == 0)
			{
				cout << "Mom\n";
			}
			else
			{
				cout << "Chef\n";
			}
			continue;
		}
		if(num == n)
		{
			cout << "Chef\n";
			continue;
		}
		if(v[0] == 1)
		{
			cout << "Chef\n";
			continue;
		}
		mx = (v[0])*(v[0]-1);
		mx /= 2;
		//cout << mx << endl;
		j = 0;
		
		forl(i,1,num)
		{
			if(v[i] - v[i-1] - 1 > 0)
			{
				info[j][0] = v[i-1]+1;
				info[j][1] = v[i] - v[i-1] - 1;
				j++;
			}
			
		}
		if(v[num-1] != n)
		{
			info[j][0] = v[num-1]+1;
			info[j][1] = n - v[num-1];
			j++;
		}
		
		forl(i,0,j)
		{
			if(info[i][1] > 0)
			{
				a = info[i][0];
				c = info[i][1];
				if(a > mx +1)
				{
					break;
				}
				b = ((a + a + c-1)*c)/2;
				mx += b;
				//cout << mx << endl;				
			}
		}
		//cout << mx << endl;
		not_found = mx+1;
		//cout << not_found << endl;
		if(not_found%2 == 0)
		{
			cout << "Mom\n";
		}
		else
		{
			cout << "Chef\n";
		}
		
	}
	
}
