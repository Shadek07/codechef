
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

int M[100005][20];
map<int,bool> mp,mp1;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int arr[100005];
    int n,m;
    int x,y;
    unsigned long long int ans=0;
    int i,j,k;
    int a,b;
    unsigned long long int *pre;
    while(cin >> n)
    {
        mp.clear();
        mp1.clear();
        pre = new unsigned long long int[1000001];
        forl(i,0,n)
        {
            cin >> arr[i];
        }
        forl(i,0,n)
        {
            M[i][0] = i;
        }
        for(j=1;(1<<j) <= n;j++)
        {
            for(i=0;i+(1<<j) -1 < n;i++)
            {
                a = arr[ M[i][j-1] ];
                b = arr[ M[i+(1<<j-1)][j-1] ];
                if(a > b)
                {
                    M[i][j] = M[i][j-1];
                }
                else
                {
                    M[i][j] = M[i+(1<<j-1)][j-1];
                }
            }
        }
        
        cin >> m >> x >> y;
        ans = 0;       
        pre[0] = 0;
        bool a1,b1;
        a1 = b1 = false;
        unsigned long long int a2,b2;
        long long int lcm = -1;
        
        forl(i,1,m+1)
        {
            if(mp[x] && !a1)
            {
                a1=true;
                a2 = i-1;
            }
                
            if(mp1[y] && !b1)
            {
                b1 = true;
                b2 = i-1;
            }
            
            if(a1 && b1)
            {
                unsigned long long int t = 1;
                
                t = t * (a2 / gcd(t,a2));
                t = t * (b2 / gcd(t,b2));
                lcm = t;
                break;                              
            }
                     
            a = min(x,y);
            b = max(x,y);
            k = log10((b-a+1)*1.0)/ log10(2.0);
            if(a == b)
            {
                ans += arr[a];
                pre[i] += pre[i-1] + arr[a];
            }
            else
            {
                if(arr[ M[a][k] ] > arr[ M[b-(1<<k)+1][k] ])
                {
                    ans += arr[ M[a][k] ];
                    pre[i] += pre[i-1] + arr[ M[a][k] ];
                }
                else
                {
                    ans += arr[ M[b-(1<<k)+1][k] ];
                    pre[i] += pre[i-1] + arr[ M[b-(1<<k)+1][k] ];
                }
            }
            
            
            mp[x] = true;
            mp1[y] = true;
            x = (x + 7);
            while(x >= (n-1))
                x -= n-1;
            y = (y+11);
            while(y >= n)
                y -= n;
            //cout << pre[i+1] << endl;           
        }
        
        long long int mn = min(lcm,m);
        for(j=i;j<=mn;j++)
        {
            a = min(x,y);
            b = max(x,y);
            k = log10((b-a+1)*1.0)/ log10(2.0);
            if(a == b)
            {
                ans += arr[a];
                pre[i] += pre[i-1] + arr[a];
            }
            else
            {
                if(arr[ M[a][k] ] > arr[ M[b-(1<<k)+1][k] ])
                {
                    ans += arr[ M[a][k] ];
                    pre[i] += pre[i-1] + arr[ M[a][k] ];
                }
                else
                {
                    ans += arr[ M[b-(1<<k)+1][k] ];
                    pre[i] += pre[i-1] + arr[ M[b-(1<<k)+1][k] ];
                }
            }
            x = (x + 7);
            while(x >= (n-1))
                x -= n-1;
            y = (y+11);
            while(y >= n)
                y -= n;
        }
        
        if(lcm != -1 && m > lcm)
        {
            //cout << "--" << lcm << endl;
            long long int rem = m - (lcm);
            unsigned long long int dv = (rem/lcm);
            ans += (dv)*ans;
            long long int mod = m%lcm;
            if(mod < 0)
                mod += lcm;
            ans += pre[mod];
        }
        
        cout << ans << endl;
        delete [] pre;
        //delete pre;
    }
    return 0;
}
