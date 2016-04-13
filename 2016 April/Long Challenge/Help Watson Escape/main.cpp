
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include <bits/stdc++.h>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define MID(a, b) (a + ((b - a) >> 1))
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999
long long int mod = 1000000007;

ull square(ull a){
    a = a%mod;
    return (a*a)%mod;
}
ull moduloExponentiation(int base, int p){
    if(p==0)
        return 1;
    if(p==1)
        return base%mod;
    ull a;
    if(p&1){//odd
        a = moduloExponentiation(base,p-1);
        return (base*a)%mod;
    }else{
        a = moduloExponentiation(base,p/2);
        a = square(a);
        return a;
    }
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    ull n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n==1){
            cout << k << endl;
            continue;
        }
        if(k==1){
            if(n==1){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
            continue;
        }
        ull ans=k;
        ans = (ans*moduloExponentiation(k-1,n-1))%mod;
        cout << ans << endl;
    }
    return 0;
}
