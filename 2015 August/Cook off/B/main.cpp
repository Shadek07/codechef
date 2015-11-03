
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
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005


int main()
{
    int t;
    
    
    long long int i,j,n;
    /*forl(j,1,100000)
    {
        forl(i,1,2000000)
        {
            if((i^(i+1)) == j)
            {
                cout << j << " " << i << endl;
                break;
            }
        }
    }*/
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        
        
        long long int t = 1;
        do
        {
            t *= 2;
        }while(t <= n);
        if(t == n+1)
        {
            cout << n/2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        
    }
    return 0;
}
