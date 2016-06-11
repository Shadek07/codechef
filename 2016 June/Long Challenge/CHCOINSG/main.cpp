
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

int primes[MAX];
int cnt=0;
bool isPrime(int n){
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    int i;
    for(i=3;i*i<=n;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}

int doit(int n, int player){
    if(n==1)
        return player;
    
    bool ok=false;
    int i,j;
    for(i=0;i<cnt;i++){
        int pr = primes[i];
        for(j=pr;j<=n;j*=pr){
            int tmp = doit(n-j,1^player);
            if(tmp == player){
                ok=true;
                j=n+1;
                i=cnt;
                break;
            }
        }
    }
    if(ok){
        return player;
    }else{
        return 1^player;
    }
    
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i;
    /*cnt=0;
    for(i=2;i<500;i++){
        if(isPrime(i)){
            primes[cnt++] = i;
        }
    }*/
    int n;
    int t;
    cin >> t;
    
    while(t--){
        cin >> n;
        /*int ans = doit(n,0);
        if(ans==0){
            cout << "Chef\n";
        }else{
            cout << "Misha\n";
        }*/
        if(n%6==0){
            cout << "Misha\n";
        }else{
            cout << "Chef\n";
        }
    }
    return 0;
}
