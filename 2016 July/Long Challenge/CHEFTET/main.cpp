
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

#define MAX 10005
#define INF 9999999

int B[MAX];
int A[MAX];
int Atmp[MAX];
bool found;
int n;
long long int ans=-1;
void doit(int ind){
    int i;
    if(ind>=3){
        for(i=1;i<=ind-2;i++){
            if(Atmp[i] != Atmp[i-1]){
                found=false;
                return;
            }
        }
    }
    
    if(ind==n){
        found=true;
        for(i=1;i<ind;i++){
            if(Atmp[i] != Atmp[i-1]){
                found=false;
                break;
            }
        }
        if(found){
            ans = max(ans,Atmp[0]);
        }
        return;
    }
    
    int pre = Atmp[ind-1];
    Atmp[ind-1] += B[ind];
    doit(ind+1);
    Atmp[ind-1] = pre;
    
    pre = Atmp[ind];
    Atmp[ind] += B[ind];
    doit(ind+1);
    Atmp[ind] = pre;
    
    if(ind+1<n){
        pre = Atmp[ind+1];
        Atmp[ind+1] += B[ind];
        doit(ind+1);
        Atmp[ind+1] = pre; 
    }
    
    
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    int t,i,j,k;
    cin >> t;
    while(t--){
        cin >> n;
        forl(i,0,n){
            cin >> B[i];
        }
        forl(i,0,n){
            cin >> A[i];
        }
        ans=-1;
        
        if(n==1){
            cout << A[0]+B[0] << endl;
            continue;
        }
        if(n==2){
            for(i=0;i<2;i++){
                for(j=0;j<2;j++){
                    forl(k,0,n){
                        Atmp[k] = A[k];
                    }
                    Atmp[i] += B[0];
                    Atmp[j] += B[1];
                    if(Atmp[0] == Atmp[1]){
                        ans = max(ans,Atmp[0]);
                    }
                }
            }
            cout << ans << endl;
            continue;
            
        }
        
        for(i=0;i<2;i++){
            for(j=0;j<3;j++){
                found=true;
                forl(k,0,n){
                    Atmp[k] = A[k];
                }
                Atmp[i] += B[0];
                Atmp[j] += B[1];
                doit(2);
            }
        }
        cout << ans << endl;        
    }
    return 0;
}
