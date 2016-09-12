
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

#define MAX 1005

vector<int> adj[MAX];
bool edge[MAX][MAX];
int col[MAX];
bool canArrange=true;

void biColorable(int node, int c){
    if(canArrange == false)
        return;
    col[node] = c;
    int sz = adj[node].size();
    int i;
    int alternate = 2;
    if(c == 2)
        alternate = 1;
    forl(i,0,sz){
        int d = adj[node][i];
        if(col[ d ] == 0){
            biColorable(d, alternate);
        }else if(col[ d ] == c){
            canArrange = false;
            return;
        }
    }
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t,n,m,a,b;
    int i,j,k;
    cin >> t;
    while(t--){
        cin >> n >> m;
        forl(i,0,MAX){
            adj[i].clear();
        }
        ms(edge,false);
        forl(i,0,m){
            cin>> a >> b;
            a--;
            b--;
            if(a==b)
                continue;
            if(edge[a][b])
                continue;

            edge[a][b] = edge[b][a] = true;
        }

        //build complement graph
        forl(i,0,n){
            forl(j,0,n){
                if(i==j)
                    continue;
                if(edge[i][j]==false){
                    adj[i].pb(j);
                }
            }
        }
        ms(col,0);
        canArrange=true;
        forl(i,0,n){
            if(canArrange == true && col[i] == 0){
                biColorable(i,1);
            }
        }
        if(canArrange == true){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }


    }
    return 0;
}
