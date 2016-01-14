
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
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100001
#define INF 9999999

vector<int> whites;
vector<int> blacks;

int comp(pii a, pii b){
    //sort according to decreasing order of Ai-Bi (planned tasks - completed tasks)
    if(a.first - a.second > b.first - b.second)
        return 1;
    else
        return 0;
}

int getWhiteIndex(int a, int b, int last){
    if(last <= -1)
        return -1;
    int i;
    for(i=last;i>=0;i--){
        if(a-b >= whites[i])
            return i;
    }
    return i;
}
int getBlackIndex(int a, int b, int last){
    if(last <= -1)
        return -1;
    int i;
    for(i=last;i>=0;i--){
        if(a-b >= blacks[i])
            return i;
    }
    return i;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int A[MAX];
    int B[MAX];
    vpii vp;
    int t;
    int n,K,M;
    cin >> t;
    int i,j,k;
    int a,b;
    while(t--){
        scanf("%d %d %d",&n,&K,&M);
        forl(i,0,n){
            scanf("%d",&A[i]);
        }
        forl(i,0,n){
            scanf("%d",&B[i]);
        }
        whites.clear();
        blacks.clear();
        vp.clear();
        forl(i,0,K){
            scanf("%d",&a);
            whites.pb(a);
        }
        forl(i,0,M){
            scanf("%d",&a);
            blacks.pb(a);
        }
        forl(i,0,n){
            vp.pb(make_pair(A[i],B[i]));
        }
        sort(all(vp),comp);
        sort(all(whites));
        sort(all(blacks));
        long ans = 0;
        bool search_for_button=true;
        a = K-1;
        b = M-1;
        forl(i,0,n){
            if(search_for_button==false){
                ans += vp[i].first - vp[i].second;
                continue;
            }
            a = getWhiteIndex(vp[i].first, vp[i].second, a);
            b = getBlackIndex(vp[i].first, vp[i].second, b);
            if(a > -1 && b > -1){
                if(whites[a] > blacks[b]){
                    ans += vp[i].first - vp[i].second - whites[a];
                    a--;
                }else{
                    ans += vp[i].first - vp[i].second - blacks[b];
                    b--;
                }
            }else if(a > -1){
                ans += vp[i].first - vp[i].second - whites[a];
                a--;
            }else if(b > -1){
                ans += vp[i].first - vp[i].second - blacks[b];
                b--;
            }else{
                ans += vp[i].first - vp[i].second;
                search_for_button=false;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}
