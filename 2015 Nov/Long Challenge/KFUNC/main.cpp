
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
#include<climits>
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

int f(int a){
    if(a < 10)
        return a;
    else
    {
        int sum=0;
        while(a){
            sum += a%10;
            a /= 10;
        }
        return f(sum);
    }
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t=20;
    unsigned long long int A,D,L,R;
    ull a,b,c,i,j,sum;
    ull ans;
    cin >> t;
    bool vis[11];
    ull prefix[11];
    //cout << ULLONG_MAX << endl;
    while(t--){
        scanf("%llu %llu %llu %llu",&A, &D, &L, &R);
        a = A + (((L-1)%9)*(D%9))%9;
        b = a%9;
        ms(vis,0);
        if(b==0)
            b = 9;
        //cout << b << endl;
        vis[b]=true;
        prefix[0] = 0;
        prefix[1] = b;
        sum = b;
        c = 1;
        forl(i,0,R-L){
            a = a + D;
            b = a%9;
            if(b == 0)
                b = 9;
           if(vis[b]){
              break;
           }
           //cout << b << endl;
           sum += b;
           c++;
           vis[b] = true;
           prefix[c] = prefix[c-1] + b;
        }
        
        ull t = (R-L+1)/c;
        ull r = (R-L+1)%c;
        ans = t*sum + prefix[r];
        cout << ans << endl;
    }
    return 0;
}
