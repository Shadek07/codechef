
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
int getValue(string s, int index){
    int sz = s.size();
    int i;
    int value=0;
    forl(i,index,sz){
        value = value*10 + (s[i]-'0');
    }
    return value;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    getchar();
    int c,i,j,k;
    char in[100];
    string country,s;
    string inp;
    while(t--){
        gets(in);
        inp = in;
        istringstream is(inp);
        is >> c >> country;
        int score=0;
        while(c--){
            gets(in);
            inp = in;
            if(inp[0] == 'T'){
                score += 300;
            }else if(inp[0] == 'B'){
                is.str(inp);
                score += getValue(inp, 10);
            }else if(inp[8] == 'H'){
                score += 50;
            }else{
                is.str(inp);
                //is >> s >> i;
                score += 300 + max(0,20-getValue(inp, 12));
            }
        }
        if(country[0] == 'I'){
            cout << score/200 << endl;
        }else{
            cout << score/400 << endl;
        }
        
    }
    return 0;
}
