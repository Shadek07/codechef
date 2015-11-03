
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

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    int n,m,k;
    int i,j,a,b;
    bool ch[101], ch2[101], ch3[101];
    bool ch1[101];
    while(t--)
    {
        cin >> n >> m >> k;
        ms(ch,false);
        ms(ch1,true);
        ms(ch2,true);
        forl(i,0,m)
        {
            cin >> a;
            ch[a] = true;
            ch1[a] = false;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        forl(i,0,k)
        {
            cin >> a;
            if(ch[a])
                cnt1++;
            ch2[a] = false;
        }
        forl(i,1,n+1)
        if(ch1[i] && ch2[i])
            cnt2++;
        cout << cnt1 << " " << cnt2 << endl;
    }
    return 0;
}
