
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

#define MAX 1005
#define INF 9999999

long long int dp[MAX][MAX];
bool inside(int a,int n){
   if(a>=1 && a<=n)
      return true;
   return false;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n,m,s;
    int t;
    int arr[MAX];
    cin >> t;
    int i,j,k;
    while(t--){
        cin >> n >> m >> s;
        forl(i,1,m+1){
            cin >> arr[i];
        }
        ms(dp,0);
        dp[s][0] = 1;
        forl(j,1,m+1){
            for(i=1;i<=n;i++){
                int a = i-arr[j];
                int b = i+arr[j];
                if(inside(a,n)){
                    dp[a][j] = (dp[a][j]+dp[i][j-1])%1000000007;
                }
                if(inside(b,n)){
                    dp[b][j] = (dp[b][j]+dp[i][j-1])%1000000007;
                }
            }
        }
        cout << dp[1][m];
        forl(i,2,n+1){
            cout << " " << dp[i][m];
        }
        cout << endl;
    }
    return 0;
}
