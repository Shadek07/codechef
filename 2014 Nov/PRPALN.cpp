
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

int out;

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i;
    char in[100001];
    int t;
    cin >> t;
    getchar();
    bool palin;
    int j,k,len;
    int cnt[26];
    while(t--)
    {
    	gets(in);
    	palin = false;
    	len = strlen(in);
    	memset(cnt, 0, sizeof(cnt));
    	forl(i,0,len)
    	{
    		cnt[in[i]-'a']++;
    	}
    	
    	int odd_cnt=0;
    	
    	forl(i,0,26)
    	{
    		if(cnt[i]%2==1)
    		odd_cnt++;
    	}
    	
    	if(len%2 == 1)//odd
    	{
    		if(odd_cnt != 1)
    		{
    			cout << "NO\n";
    			continue;
    		}   			
    			
    	}
    	else
    	{
    		if(odd_cnt > 2)
    		{
    			cout << "NO\n";
    			continue;
    		}
    	}
    	
    	int x = 0;
    	int y = len-1;
    	while(x<y && in[x] == in[y])
    	{
    		x++;
    		y--;
    	}
    	
    	if(y<x)
    	{
    		cout << "YES\n";
    		continue;
    	}
    	int arr[2] = {x,y};
    	
    	forl(k,0,2)
    	{
    		out = arr[k];
    		if(len%2 == 1 && cnt[in[out]-'a']%2 == 0)
    		continue;
    		i = -1;
    		j = len;
    		bool ch = true;
    		while(i<j)
    		{
    			i++;
    			if(i == out)
    			i++;
    			j--;
    			if(j == out)
    			j--;
    			if(in[i] != in[j])
    			{
    				ch = false;
    				break;
    			}
    		}
    		if(ch)
    		{
    			palin = true;
    			break;
    		}
    	}
    	
    	if(palin)
    	cout << "YES\n";
    	else
    	cout <<"NO\n";
    }
    return 0;
}
