
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
typedef vector<long long> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    vi v;
    int t;
    int i,a;
    cin >> t;
    ull k;
    while(t--){
        v.clear();
        forl(i,0,3){
            cin >> a;
            v.pb(a);
        }
        cin >> k;
        sort(all(v));
        ull ans = 0;
        ull mn = v[0];
        if(k<=mn){
            ans = 3*(k-1)+1;
            cout << ans << endl;
            continue;
        }else{
            ans = 3*mn;
            int cnt=0;
            forl(i,0,3){
                v[i] -=mn;
                if(v[i]==0)
                    cnt++;
            }
            k -= mn;
            reverse(all(v));
            forl(i,0,cnt){
                v.pop_back();
            }
            sort(all(v));
            int sz = 3-cnt;
            mn = v[0];
            if(k<=mn){
                ans += sz*(k-1)+1;
                cout << ans << endl;
                continue;
            }else{
                ans += sz*mn;
                k -= mn;
                forl(i,0,sz){
                    v[i] -= mn;
                }
                sort(all(v));
                ans += k;
                cout << ans << endl;
            }
            
        }
    }
    return 0;
}

