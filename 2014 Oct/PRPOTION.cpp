
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
    vector<int> r[3];
    int r1, g1, b1;
    int m;
    int t;
    cin >> t;
    int i,a,b,c;
    int ind;
    int mx;
    while(t--)
    {
    	cin >> r1 >> g1 >> b1 >> m;
    	r[0].clear();
    	r[1].clear();
    	r[2].clear();
    	
    	forl(i,0,r1)
    	{
    		cin >> a;
    		r[0].push_back(a);
    	}
    	
    	forl(i,0,g1)
    	{
    		cin >> a;
    		r[1].push_back(a);
    	}
    	forl(i,0,b1)
    	{
    		cin >> a;
    		r[2].push_back(a);
    	}
    	
    	while(m--)
    	{
    		ind = 0;
    		
    		mx = *max_element(r[0].begin(), r[0].end());
    		
    		a = *max_element(r[1].begin(), r[1].end());
    		if(a > mx)
    		{
				ind = 1;
				mx = a;
    		}
    		
    		a = *max_element(r[2].begin(), r[2].end());
    		if(a > mx)
    		{
				ind = 2;
				mx = a;
    		}
    		
    		if(mx == 0)
    		break;
    		
    		forl(i,0,r[ind].size())
    		{
    			r[ind][i]/=2;
    		}
    	}
    	
    	mx = *max_element(r[0].begin(), r[0].end());
    		
		a = *max_element(r[1].begin(), r[1].end());
		if(a > mx)
		{
			ind = 1;
			mx = a;
		}
		
		a = *max_element(r[2].begin(), r[2].end());
		if(a > mx)
		{
			ind = 2;
			mx = a;
		}
		
		cout << mx << endl;
    }
    return 0;
}

