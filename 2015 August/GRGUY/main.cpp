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
char in[2][1000002];
int n;
int doit(int start)
{
    int i=0;
    int cnt=0;
    while(i+1 < n)
    {
        if(in[start][i+1] == '.')
        {
            i++;
        }
        else if(in[1^start][i+1] == '.')
        {
            start ^= 1;
            i++;
            cnt++;
        }
        else
        {
            return -1;
        }
    }
    return cnt;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    getchar();
    int a;
    while(t--)
    {
        gets(in[0]);
        gets(in[1]);
        n = strlen(in[0]);
        int ans = 10000007;
        if(in[0][0] == '.')
        {
            a = doit(0);
            if(a != -1)
                ans = min(ans,a);
        }
        if(in[1][0] == '.')
        {
            a = doit(1);
            if(a != -1)
                ans = min(ans,a);
        }
        if(ans == 10000007)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            cout << ans << endl;
        }        
    }
    return 0;
}
