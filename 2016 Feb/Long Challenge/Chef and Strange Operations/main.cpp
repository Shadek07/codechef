
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
ull arr[MAX];
ull x,n,m;
ull MOD = 1000000007LLU;
ull numerator, denominator;

ull MultMod(ull a, ull b){
    return ((a%MOD)*(b%MOD))%MOD;
}
ull AddMod(ull a, ull b){
    return ((a%MOD)+(b%MOD))%MOD;
}

ull modPow(ull a, ull x, ull p) {
    ull res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x >>= 1;
    }
    return res;
}

ull modInverse(ull a, ull p) {
    //calculates the modular multiplicative of a mod.
    return modPow(a, MOD-2, MOD);
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int i,j,k;
    //cout << modPow(2, 15, 355644) << endl;
    scanf("%d",&t);
    ull ans;
    while(t--){
        scanf("%llu %llu %llu",&n,&x,&m);
        forl(i,0,n){
            scanf("%llu",&arr[i]);
        }
        if(x == 1){
            printf("%llu\n", arr[0]%MOD);
            continue;
        }
        if(x == 2){
            ans = arr[1];
            ull mult = MultMod(arr[0], m);
            ans = AddMod(ans, mult );
            printf("%llu\n", ans);
            continue; 
        }
        numerator = m%MOD;
        denominator = 1;
        ans = arr[x-1]%MOD;
        ull a,b;
        a = m;
        b = 1;
        for(i=x-2;i>=0;i--){
            ull tmp = ( numerator* modInverse(denominator,MOD) ) % MOD;
            tmp = MultMod(tmp, arr[i]);
            ans = AddMod(ans, tmp);
            
            a = AddMod(a,1LLU);
            b++;
            numerator = MultMod(numerator, a);
            denominator = MultMod(denominator, b);
        }
        printf("%llu\n", ans);
    }
    return 0;
}
