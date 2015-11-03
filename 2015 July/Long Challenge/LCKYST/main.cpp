
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

#define MAX 1005

unsigned long long int ans;
int cnt;
void doit(unsigned long long a, unsigned long long int base)
{
    cout << "--" << a << endl;
    if(a > MAX)
        return;
    unsigned long long int b = a*base,c;
    int i=0;
    c = b;
    while(b%10 == 0)
    {
        b /= 10;
        i++;
    }
    if(cnt < i || (cnt == i and ans > c))
    {
        cnt = i;
        ans = c;
    }
    doit(a*10+4,base);
    doit(a*10+7,base);
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n;
    unsigned long long int a;
    
    cin >> n;
    while(n--)
    {
        cin >> a;   
        ans = a;
        unsigned long long int b = a,base=1;
        cnt = 0;
        while(b%10 == 0)
        {
            cnt++;
            b/=10;
            base *= 10;
        }
        
        while(b%10 == 5)
        {
            b *= 4;
            while(b%10 == 0)
            {
                b /= 10;
                base *= 10;
            }
        }
        
        b *= base;
        cout << b << endl;       
    }
    return 0;
}

