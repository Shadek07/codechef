
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
#define INF 9999999
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int sum[55];
    int prod[55];
    int arr[55];
    int i,j,k,t,n;
    cin >> t;
    while(t--){
        cin >> n;
        forl(i,0,n){
            cin >> arr[i];
        }
        sum[0]=0;
        prod[0]=1;
        forl(i,0,n){
            sum[i+1] = sum[i]+arr[i];
            prod[i+1] = prod[i]*arr[i];
        }
        int cnt=0;
        forl(i,1,n+1){
            forl(j,i,n+1){
                int s = sum[j]-sum[i-1];
                int p = prod[j]/prod[i-1];
                if(s == p)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
