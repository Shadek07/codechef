
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



//int find_level(int p)
//{
	//double x = p;
	//return floor(log10(x)/log10(2.0));
//}

int find_level(int p)
{
	long long int sum = 0;
	int i;
	forl(i,0,30)
	{
		sum += pow(2.0,i);
		if(sum >= p)
		return i;
	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    //maximum 29 levels
    int i;
    //int sum=0;
    //forl(i,0,30)
    //{
    	//sum += pow(2.0, i);
    	//cout << i << " " << sum << endl;
    //}
    
    //cout << find_level(1024) << endl;
    int q;
    cin >> q;
    getchar();
    char c1,c2;
    long int x,y;
    int level_x, level_y;
    set<int> st;
    int col=0; //color of root, 0 for black, 1 for red
    while(q--)
    {
    	cin >> c1 >> c2;
    	if(c2 == 'i')
    	{
    		col = col^1;
    	}
    	else
    	{
    		cin >> x >> y;
    		
    		if(x<y)
    		{
    			long int tmp = x;
    			x = y;
    			y = tmp;
    		}
    		
    		level_x = find_level(x);
    		level_y = find_level(y);
    		st.clear();
    		st.insert(x);
    		long int a,b;
    		a = x;
    		while(a != 1)
    		{
    			a/=2;
    			st.insert(a);
    		}
    		
    		a = y;
    		int cnt=0;
    		int cnt2=0;
    		double p;
    		while(true)
    		{
    			
    			if(st.find(a) != st.end())
    			{
    				cnt2=0;
    				while(x != a)
    				{
    					x /= 2;
    					cnt2++;
    				}
    				break;
    			}
    			a/= 2;
    			cnt++;                   
    		}
    		
    		long int col_cnt[2] = {0,0};
    		int x1,y1;
    		cnt2++;
    		
    		cnt2 += cnt;
    		
    		/*if(level_x%2 == 0)
    		{
    			x1 = ceil(cnt2*1.0/2);
    			col_cnt[col] += x1;
    			col_cnt[col^1] += (cnt2-x1);
    		}
    		else
    		{
    			x1 = ceil(cnt2*1.0/2);
    			col_cnt[col^1] += x1;
    			col_cnt[col] += (cnt2-x1);
    		}
    		
    		
    		if(level_y%2 == 0)
    		{
    			x1 = ceil(cnt*1.0/2);
    			col_cnt[col] += x1;
    			col_cnt[col^1] += (cnt-x1);
    		}
    		else
    		{
    			x1 = ceil(cnt*1.0/2);
    			col_cnt[col^1] += x1;
    			col_cnt[col] += (cnt-x1);
    		}*/
    		
    		//cout << col_cnt[0] << " " << col_cnt[1] << endl;
    		
    		if(c2 == 'b')
    		{
    			//cout << col_cnt[0] << endl;
    			if(level_x%2 == 0)
    			{
    				if(col == 0)
    				{
    					cout << (cnt2+1)/2 << endl;
    				}
    				else
    				{
    					cout << cnt2/2 << endl;
    				}
    			}
    			else
    			{
    				if(col == 0)
    				{
    					cout << cnt2/2 << endl;
    				}
    				else
    				{
    					cout << (cnt2+1)/2 << endl;
    				}
    			}
    		}
    		else //'r'
    		{
				//cout << col_cnt[1] << endl;
				if(level_x%2 == 0)
    			{
    				if(col == 0)
    				{
    					cout << cnt2/2 << endl;
    				}
    				else
    				{
    					cout << (cnt2+1)/2 << endl;
    				}
    			}
    			else
    			{
    				if(col == 0)
    				{
    					cout << (cnt2+1)/2 << endl;
    				}
    				else
    				{
    					cout << cnt2/2 << endl;
    				}
    			}
    		}
    		
    	}
    	getchar();
    }
   
    
    return 0;
}
