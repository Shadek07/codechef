
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
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 10001
#define INF 9999999

long getBallCountNeeded(long &base, long cur, long gcd){
    if(cur >= base && (cur%gcd == 0)){
        base = cur;
        return 0;
    }
    long ball_count = 0;
    if(cur < base){
        ball_count += base - cur;
    }
    if(base < cur){
        base = cur;
    }
    int mod = base%gcd;
    if(mod != 0){
        ball_count += gcd - mod;
        base += gcd - mod;
    }
    return ball_count;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int arr[MAX];
    int t,n,i,j,k;
    cin >> t;
    long int ans;
    while(t--){
        //cin >> n;
        scanf("%d",&n);
        bool all_one=true;
        int mx=1;
        forl(i,0,n){
            scanf("%d",&arr[i]);
            if(arr[i] != 1){
                all_one = false;
                mx = max(mx,arr[i]);
            }
        }
        if(all_one){
            cout << n << endl;
            continue;
        }
        ans = 100000005;
        long tmp = 0;
        long base;
        bool vis[MAX];
        ms(vis,false);
        forl(i,2,4){
            tmp = 0;
            base = i;
            forl(j,0,n){
                tmp += getBallCountNeeded(base, arr[j], i);
            }
            ans = min(ans,tmp);
            for(j=i+i;j<=10000;j+=i){
                vis[j] = true;
            }
        }
        
        forl(i,2,mx+1){
            tmp = 0;
            if(vis[i])
                continue;
            base = i;
            
            forl(j,0,n){
                tmp += getBallCountNeeded(base, arr[j], i);
            }
            ans = min(ans,tmp);
            for(j=i*i;j<=10000;j+=2*i){
                vis[j] = true;
            }
        }
        //cout << ans << endl;
        printf("%ld\n",ans);
        
    }
    return 0;
}
