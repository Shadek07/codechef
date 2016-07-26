
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

int arr[MAX];

bool ch[10000005];

bool isLess(int a){
    return a<10000001;
}

#define MAXBITS 1000000001
#define USIZE (50)

ull bitarray[MAXBITS/USIZE];

#define SETBIT(X)    (bitarray[X/USIZE]|=1<<(X%USIZE))
#define RESETBIT(X)  (bitarray[X/USIZE]&=~(1<<(X%USIZE)))
#define GETBIT(X)    ((bitarray[X/USIZE]&(1<<(X%USIZE)))?1:0)
int n;
void reset_all(){
    int i;
    forl(i,0,n){
        RESETBIT(arr[i]);
    }
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    int i,j,k,a,b;
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        forl(i,0,n){
            cin >> arr[i];
        }
        
        ull ans = 0;
        
        forl(i,0,n-1){
            //ms(bitarray,0);
            reset_all();
            forl(j,i,n-1){
                SETBIT(arr[j]);
                a = j+1;
                b = j+1;
                while(a<n && b<n){
                    if(GETBIT(arr[b])){
                        int len = b-a;
                        ans += (len*(len+1))/2;
                        a = b+1;
                        b = a;
                        continue;
                    }
                    b++;
                    //ans++;
                }
                if(a!=b){
                    int len1 = b-a;
                    ans += (len1*(len1+1))/2;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

