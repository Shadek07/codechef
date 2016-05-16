
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

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int a,b,c;
    cout << "1\n3 1 1 2" << endl;
    cout << "3 3 3 4" << endl;
    fflush(stdout);
    cin >> a;
    if(a==0){
        cout << "2\n 5\n";
        fflush(stdout);
    }else if(a==1){      
        cout << "2\n 2\n";
        fflush(stdout);        
    }else if(a==2){       
        cout << "2\n 1\n";
        fflush(stdout);        
    }else if(a==-2){       
        cout << "2\n 3\n";
        fflush(stdout);        
    }else if(a==-1){       
        cout << "2\n 4\n";
        fflush(stdout);        
    }
    return 0;
}
