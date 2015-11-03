
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
#define isPowerOfTwo(S) (!(S & (S - 1)))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

int power(int p)
{
    int ans = 1;
    int cnt = 0;
    while(ans < p)
    {
        cnt++;
        ans *= 2;
    }
    return cnt;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    long int s,c,k;
    unsigned long long int ans;
    int a;
    int i;
    while(t--)
    {
        cin >> s >> c >> k;
        
        if(s == 0 && c == 0)
        {
            cout << 0 << endl;
            continue;
        }
        
        else if(k == 1)
        {
            if(s == 0)
            {
                ans = 0;
            }
            else
            {
                a = s - 1;
                ans = pow(2.0,a) - 1;
                ans *= 2;
                ans += 3;
            }
            if(c > 0)
            {
                int st;
                if(s == 0)
                    st = 0;
                else
                    st = s-1;
                forl(i,st,c)
                {
                    ans += pow(2.0,i+1);
                }
            }            
            printf("%llu\n",ans);
            continue;
        }
        else if(c == 0)
        {
            if(s == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                if(k > s)
                {
                    cout << 0 << endl;
                }
                else if(k == s)
                {
                    cout << 3 << endl;
                }
                else
                {
                    a = s - k;
                    ans = pow(2.0,a) - 1;
                    ans *= 2;
                    ans += 3;
                    printf("%llu\n",ans);
                }
            }        
        }
        else
        {
            if(s == 0)
            {
                ans = 0;
            }
            else
            {
                if(k > s)
                {
                    ans = 0;
                }
                else if(k == s)
                {
                    ans = 3;
                }
                else
                {
                    a = s - k;
                    ans = pow(2.0,a) - 1;
                    ans *= 2;
                    ans += 3;
                    //printf("%llu\n",ans);
                }
            }
            int p = s - k + 1;
            if( p > 0 && p <= c )
            {
                ans += pow(2.0,p);
            }
            printf("%llu\n",ans);
        }
    }
    return 0;
}
