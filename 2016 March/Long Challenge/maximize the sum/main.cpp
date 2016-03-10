
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include <bits/stdc++.h>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define forl(i,a,b) for ( i = a; i < b; i++)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<long long int,long long int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n;
    long long int k;
    int i,j,a;
    int t;
    cin >> t;
    vpii vp1;
    while(t--){
        cin >> n >> k;
        vp1.clear();
        int maxValue = 0;
        int index;
        forl(i,0,n){
            cin >> a;
            vp1.pb(make_pair(a,0));
        }
        forl(i,0,n){
            cin >> a;
            j = vp1[i].first;
            vp1[i] = make_pair(j,a);
            if(abs(a) > maxValue){
                maxValue = abs(a);
                index = i;
            }
        }
        long long int c;
        c = vp1[index].second;
        if( c >= 0){
            vp1[index].first += k;
        }else{
            vp1[index].first -= k;
        }
        long long int ans = 0;
        forl(i,0,n){
            ans += vp1[i].first*vp1[i].second;
        }
        cout << ans << endl;
        
    }
    return 0;
}
