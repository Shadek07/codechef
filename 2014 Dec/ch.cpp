
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

map<int, int> mp;
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    long long int mx = -1;
    long long int ans;
    int n,k;
    int i,j;
    int t;
    long long int a;
    //cout << (2 & (1<<1)) << endl;
    //cout << (19^12^44^34^6634) << endl;
    cin >> t;
    int arr[10];
    vector<int> sets;
    while(t--)
    {
    	cin >> n >> k;
    	
    	forl(i,0,n)
    	{
    		cin >> arr[i];
    	}
    	mx = -1;
    	int ind;
    	if(n > 20)
    	goto nt;
    	for(i = 0;i<(1<<n);i++)
    	{
    		ans = k;
    		for(j = n-1; j>= 0; j--)
    		{
    			if((i & (1<<j)) != 0)
    			{
    				
    				ans ^= arr[j];
    				
    			}
    		}
    		if(ans > mx)
    		{
				mx = max(mx, ans);
				ind = i;
    		}
    		if(mp[ans])
    		mp[ans]++;
    		else
    		mp[ans]=1;
    		if(ans == 6651)
    		{
    			sets.push_back(i);
    		}
    	}
    	nt:
    	cout  << mx << endl;
    	cout << mp[mx] << endl;
    	cout << sets[0] << " " << sets[1] << " " << sets[2] << " " << sets[3] << endl;
    	
    }
    return 0;
}
