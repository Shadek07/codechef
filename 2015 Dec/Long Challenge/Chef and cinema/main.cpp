
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

int ans;
int n,m;
void doit(int R, int c, char current, int cnt, int z, int l, int r, int b){
    if(R == n-1 && c == m-1){
        ans = max(ans,cnt);
        return;
    }
    if(c == m-1){
         doit(R+1,0,' ',cnt,z,l,r,b);
         if(z)
            doit(R+1,0,'z',cnt+1,z-1,l,r,b);
        if(l)
            doit(R+1,0,'l',cnt+1,z,l-1,r,b);
        if(r)
            doit(R+1,0,'r',cnt+1,z,l,r-1,b);
        if(b)
            doit(R+1,0,'b',cnt+1,z,l,r,b-1);
        
    }else{
        if(l && (current != 'r' && current != 'b'))
            doit(R,c+1,'l', cnt+1, z,l-1,r,b);
        if(r)
            doit(R,c+1,'r', cnt+1, z,l,r-1,b);
        if(z)
            doit(R,c+1,'z', cnt+1, z-1,l,r,b);
        if(b && (current != 'r' && current != 'b'))
            doit(R,c+1,'b', cnt+1, z,l,r,b-1);
        doit(R,c+1,' ',cnt,z,l,r,b);
    }
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int z,l,r,b;
    cin >> t;
    while(t--){
        cin >> n >> m >> z >> l >> r >> b;
        if(n > 30 || m > 30){
            cout << 0 << endl;
            continue;
        }
        ans = 0;
        if(l)
        doit(0, 0, 'l', 1, z, l-1,  r, b);
        if(r)
        doit(0, 0, 'r', 1, z, l,  r-1, b);
        if(z)
        doit(0, 0, 'z', 1, z-1, l,  r, b);
        if(b)
        doit(0, 0, 'b', 1, z, l,  r, b-1);
        doit(0, 0, ' ', 0, z, l,  r, b);
        //if(ans>0)
            //ans--;
        cout << ans << endl;
    }
    return 0;
}

