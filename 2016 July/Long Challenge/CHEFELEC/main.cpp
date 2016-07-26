
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
int xi[MAX];
int n;
char in[MAX];
int find_index(int cur,int dir){
    int i;
    for(i=cur;i>=0&&i<n;i+=dir){
        if(in[i] == '1')
            return i;
    }
}

int getDistance(int a, int b){
    ull mn = 1e9;
    int i;
    for(i=a;i<b;i++){
        mn = min(mn, xi[i]-xi[a]+xi[b]-xi[i+1]);
    }
    return mn;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    //std::ios_base::sync_with_stdio(false);
    int i,j,k;
    
    int t;
    
    cin >> t;
    ull ans;
    while(t--){
        cin >> n;
        getchar();
        gets(in);
        //cout << in<< endl;
        forl(i,0,n){
            cin >> xi[i];
        }
        ans = 0;
        int a,b;
        
        a = find_index(0,1); //first index of 1
        b = find_index(n-1,-1); //last index of 1
        ans = 0;
        ans += xi[a]-xi[0];  //0000001...., left side 0's to be connected with leftmost 1
        ans += xi[n-1]-xi[b]; //....100000, right side 0;s to be connected with rightmost 1
        i = a;
        int left,right;
        while(i<=b){
            while(i<=b && in[i]=='1'){
                i++;
            }
            left = i-1; //leftmost index of 1
            while(i<=b && in[i]=='0'){
                i++;
            }
            right = i;
            if(left < b && left < right){
                
                //..100001.., first 1 is left index, last 1 is right index
                //the zero's in the middle will be connected to either left 1 or right 1
                //according to smallest distance
                int ind = getDistance(left,right);
                ans += ind;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
