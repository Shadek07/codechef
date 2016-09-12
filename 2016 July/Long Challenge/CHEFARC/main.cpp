
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

#define MAX 105
#define INF 9999999

int dist1[105][105];
int dist2[105][105];
short vis[105][105];
int n,m,k1,k2;
queue<pii> pq;

bool between(int a,int b){
    return ((a>=0 && a<n)&&(b>=0 && b<m));
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    //std::ios_base::sync_with_stdio(false);
    int t;
    int i,j,k;
    int a,b;
    pii p1;
    cin >> t;
    while(t--){
        cin >> n >> m >> k1 >> k2;
        
        forl(i,0,n){
            forl(j,0,m){
                cin >> vis[i][j];
            }
        }
        
        forl(i,0,n){
            forl(j,0,m){
                dist1[i][j] = 999999;
                dist2[i][j] = 999999;
            }
        }
        dist1[0][0] = 0;
        dist2[0][m-1] = 0;
        pq.push(make_pair(0,0));
        while(!pq.empty()){
            p1 = pq.front();
            a = p1.first;
            b = p1.second;
            pq.pop();
            for(i=a-k1;i<=a+k1;i++){
                for(j=b-k1;j<=b+k1;j++){
                    if(between(i,j) && ( (abs(a-i)+abs(b-j)) <= k1) && vis[i][j] == 0){
                        if(dist1[a][b]+1 < dist1[i][j]){
                            pq.push(make_pair(i,j));
                            dist1[i][j] = dist1[a][b]+1;
                        }
                    }
                }
            }
        }
            
        pq.push(make_pair(0,m-1));
        while(!pq.empty()){
            p1 = pq.front();
            a = p1.first;
            b = p1.second;
            pq.pop();
            for(i=a-k2;i<=a+k2;i++){
                for(j=b-k2;j<=b+k2;j++){
                    if(between(i,j) && ( (abs(a-i)+abs(b-j)) <= k2) && vis[i][j] == 0){
                        if(dist2[a][b]+1 < dist2[i][j]){
                            pq.push(make_pair(i,j));
                            dist2[i][j] = dist2[a][b]+1;
                        }
                    }
                }
            }
        }
        
        int ans = -1;
        forl(i,0,n){
            forl(j,0,m){
                if(dist1[i][j] != 999999 && dist2[i][j] != 999999){
                    if(ans==-1){
                        ans = max(dist1[i][j],dist2[i][j]);
                    }else{
                        ans = min(ans,max(dist1[i][j],dist2[i][j]));
                    }
                }
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}
