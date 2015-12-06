
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


map<pii, set<pii> >  mp;

pii getPair(int a, int b){
    if(a == 0)
        return make_pair(0,0);
    if(a < 0 && b < 0)
        return make_pair(abs(a), abs(b));
    if((a < 0 && b > 0) || (a > 0 && b < 0))
        return make_pair(-abs(a), abs(b));
    return make_pair(a,b);
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int n;
    int i,j,k;
    cin >> t;
    int ans;
    int a,b,c;
    pii p1,p2;
    while(t--){
        mp.clear();
        ans = 0;
        scanf("%d",&n);
        set<pii> xparallel;
        set<pii> yparallel;
        int gcd,gcd2;
        forl(i,0,n){
            scanf("%d %d %d",&a,&b,&c);
            if(a == 0){
                gcd = __gcd(abs(b),abs(c));
                if(c == 0){
                    xparallel.insert(make_pair(0, 0));
                }else{
                    xparallel.insert(getPair(-c/gcd, b/gcd));
                }
                continue;
            }
            if(b == 0){
                gcd = __gcd(abs(a),abs(c));
                if(c == 0){
                    yparallel.insert(make_pair(0, 0));
                }else{
                    yparallel.insert(getPair(-c/gcd, a/gcd));
                }
                continue;
            }
            gcd = __gcd(abs(a),abs(b));
            gcd2 = __gcd(abs(c),abs(b));
            
            p1 = getPair(-a/gcd, b/gcd);
            p2 = getPair(-c/gcd2, b/gcd2);
            mp[p1].insert(p2);
            ans = max(ans, mp[p1].size());
        }
        ans = max(ans,xparallel.size());
        ans = max(ans,yparallel.size());
        cout << ans << endl;
    }
    return 0;
}
