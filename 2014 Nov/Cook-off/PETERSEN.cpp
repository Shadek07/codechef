
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

vector<int> adj[10];
map<int, char> mp;

char in[100001];
int n;

string bfs(int st)
{
	string s = "";
	s += char(st+'0');
	int i,j,k;
	int cur = st;
	forl(i,0,n)
	{
		bool ch = false;
		forl(j,0,3)
		{
			k = adj[cur][j];
			if(in[i+1] == mp[k])
			{
				s += char(k+'0');
				ch = true;
				cur = k;
				break;
			}
		}
		if(ch == false)
		{
			string s1 = "";
			return s1;
		}
	}
	return s;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    
    mp[0] = 'A';
    mp[1] = 'B';
    mp[2] = 'C';
    mp[3] = 'D';
    mp[4] = 'E';
    mp[5] = 'A';
    mp[6] = 'B';
    mp[7] = 'C';
    mp[8] = 'D';
    mp[9] = 'E';
    
    adj[0].pb(1);
    adj[0].pb(4);
    adj[0].pb(5);
    
    adj[1].pb(0);
    adj[1].pb(2);
    adj[1].pb(6);
    
    adj[2].pb(1);
    adj[2].pb(3);
    adj[2].pb(7);
    
    adj[3].pb(2);
    adj[3].pb(4);
    adj[3].pb(8);
    
    adj[4].pb(0);
    adj[4].pb(3);
    adj[4].pb(9);
    
    adj[5].pb(0);
    adj[5].pb(8);
    adj[5].pb(7);
    
    adj[6].pb(1);
    adj[6].pb(8);
    adj[6].pb(9);
    
    adj[7].pb(2);
    adj[7].pb(5);
    adj[7].pb(9);
    
    adj[8].pb(3);
    adj[8].pb(5);
    adj[8].pb(6);
    
    adj[9].pb(4);
    adj[9].pb(6);
    adj[9].pb(7);
    
    int t,i,j,k;
    
    //cout << char('B'-'A'+'0') << endl;
    
    cin >> t;
    getchar();
    while(t--)
    {
    	gets(in);
    	n = strlen(in) - 1;
    	if(n == 0)
    	{
    		cout << char(in[0]-'A'+'0') << endl;
    		continue;
    	}
    	
    	string s;
    	s = bfs(in[0]-'A');
    	if(s.size() == 0)
    	{
    		s = bfs(in[0]-'A'+5);
    		if(s.size() == 0)
    		{
    			cout << -1 << endl;
    		}
    		else
    		{
    			cout << s << endl;
    		}
    	}
    	else
    	{
    		cout << s << endl;
    	}
    }
    
    return 0;
}
