
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
ull H[MAX], R[MAX];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    long long int a = 1e18;
    //cout << a << endl;
    int i,j,k;
    ull n,W,L;
    while(cin >> n >> W >> L){
        forl(i,0,n){
            cin >> H[i] >> R[i];
        }
        
        long long int low,mid,high;
        low=0;
        high=1e18+7;
        ull ans=0;
        long long int Rsum = 0;
        forl(i,0,n){
            Rsum += H[i];
        }
        while(low<=high){
            mid = MID(low,high);
            ull x = 0;
            forl(i,0,n){
                //ull h = H[i] + R[i]*mid;
                long long int u = W-x-H[i];
                long long int u2 = L-H[i];
                //long long int mn = min(R[i],mid);
                //long long int mx = max(R[i],mid);
                if(L >= H[i] && R[i] >= (L-H[i]+mid-1)/mid){
                    if(W-H[i] >= x && R[i] >= (W-x-H[i]+mid-1)/mid){
                        x = W;
                        break;
                    }else{
                        x += H[i] + R[i]*mid;
                    }
                    //x += h;
                }
                if(x>=W)
                    break;
            }
            
            if(x>=W){
                high=mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

