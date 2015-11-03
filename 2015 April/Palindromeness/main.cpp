
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

bool pal[100002][2];
int n;
char in[100001];
long long int palness[1002];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int i,j,k;
    cin >> t;
    getchar();
    while(t--){
        gets(in);
        n = strlen(in);
        if(n > 1000)
        {
            cout << 0 << endl;
            continue;
        }
        ms(pal,false);
        forl(i,0,n)
        pal[i][0] = true;
        forl(i,0,n-1)
        if(in[i] == in[i+1])
            pal[i][1] = true;
        else
            pal[i][1] = false;
        
        /*forl(k,3,n+1)
        {
            for(i=0;i+k-1 < n;i++)
            {
                j = i+k-1;
                if(pal[i+1][j-1] && in[i] == in[j])
                    pal[i][j] = true;
            }
        }*/
        long long int sum=n;
        bool pal_st[100002];
        bool pal_ahead[100002];
        
        forl(i,0,n)
        {
            int base = i-1;
            palness[i-base] = 1;
            pal_st[1] = true;
            forl(j,i+1,n)
            {
                int len = j-i+1;
                if(len == 2)
                {
                    pal_ahead[1] = true;
                    if(in[i] == in[j])
                    {
                        pal_st[2] = true;
                        sum += 2;
                    }
                        
                    else
                        pal_st[2] = false;
                    continue;
                }
                if(pal_ahead[len-2] && in[i] == in[j]){
                    pal_st[len] = true;
                }
                else
                {
                    pal_st[len] = false;
                }
                if(!pal_st[len])
                {
                    palness[j-base] = 0;
                }
                else
                {
                    sum += 1 + palness[len/2];
                    palness[j-base] = 1 + palness[len/2];
                }
            }
        }
        
        cout << sum << endl;
            
    }
    return 0;
}
