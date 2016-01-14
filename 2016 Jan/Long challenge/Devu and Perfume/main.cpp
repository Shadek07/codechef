
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

#define MAX 1001
#define INF 9999999

bool vis[MAX][MAX];
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={1,1,0,-1,-1,-1,0,1};
struct state{
    int i;
    int j;
    int dis;
};
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    char in[MAX][MAX];
    int n,m;
    int a,b;
    int i,j;
    int t;
    cin >> t;
    int mx;
    int left,right,top,bottom;
    int ans;
    while(t--){
        cin >> n >> m;
        getchar();
        forl(i,0,n){
            gets(in[i]);
        }
        a = b = -1;
        left = m;
        right = 0;
        top = n;
        bottom = 0;
        forl(i,0,n){
            forl(j,0,m){
                if(in[i][j] == '*'){
                    left = min(left,j);
                    right = max(right,j);
                    top = min(top,i);
                    bottom = max(bottom,i);
                }
            }
        }
        mx = max(right-left, bottom-top);
        if(left == m){
            cout << 0 << endl;
        }
        else{
            cout << 1 + (mx+1)/2 << endl;
        }
        /*mx = 0;
        state st,cur,temp;
        ms(vis,0);
        if(a != -1){
            queue<state> pq;
            st.i = a;
            st.j = b;
            st.dis = 1;
            pq.push(st);
            vis[a][b]=true;
            while(!pq.empty()){
                cur = pq.front();
                pq.pop();
                if(in[cur.i][cur.j] == '*'){
                    mx = max(mx,cur.dis);
                }
                forl(i,0,8){
                    a = cur.i + dx[i];
                    b = cur.j + dy[i];
                    if(a>=0 && a <n && b>=0 && b < m && !vis[a][b]){
                        vis[a][b]=true;
                        st.i = a;
                        st.j = b;
                        st.dis = cur.dis+1;
                        pq.push(st);
                    }
                }
            }
            
        }*/
        
    }
    return 0;
}
