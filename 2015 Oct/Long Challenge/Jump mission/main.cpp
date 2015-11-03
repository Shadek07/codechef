
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

#define MAX 300005
long long int P[MAX];
long long int A[MAX];
long long int H[MAX];
long long int sqr(long long int a){
    return a*a;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n;
    long long int ans,tmp;
    int i,j,k;
    while(cin >> n){
        forl(i,0,n){
            scanf("%ld",&P[i]);
        }
        forl(i,0,n){
            scanf("%ld",&A[i]);
        }
        forl(i,0,n){
            scanf("%ld",&H[i]);
        }
        ans = A[0];
        for(i=0;i<n;i++){
            tmp = (1<<30) - 1;
            int ind;
            for(j=i+1;j<n;j++){
                if(A[j] + sqr(j-i) < tmp){
                    tmp = A[j] + sqr(j-i);
                    ind = j;
                }
            }
            i = ind-1;
            ans = ans + tmp;
            if(ind == n-1)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
