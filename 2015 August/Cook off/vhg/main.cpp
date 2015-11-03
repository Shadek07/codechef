
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

#define MAX 55

bool dp[MAX][MAX];
bool ch[MAX][MAX];
char in[MAX];
bool doit(int a, int b)
{
    if(a > b)
        return true;
    if(a==b)
        return false;
    if(ch[a][b])
        return dp[a][b];
    int i,j;
    bool &res = dp[a][b];
    res = false; 
    ch[a][b] = true;
    forl(i,a,b)
    {
        if(in[i] != 'a')
            continue;
            bool tmp = false;
            j = i+1;
            if(in[j] == 'b')
            {
                tmp = doit(a,i-1) && doit(j+1,b);
                if(tmp)
                {
                    res = true;
                    return res;
                }
            }
    }
    
    return res;
        
}


class GoodString {
    public:
    string isGood(string s) {
        while(s.size() > 0)
        {
            int n = s.size();
            int i;
            bool found = false;
            forl(i,0,n-1)
            {
                if(s[i] == 'a' && s[i+1] == 'b')
                {
                    found = true;
                    string s1 = "";
                    string s2 = "";
                    if(i > 0)
                    s1 = s.substr(0,i);
                    if(i+2 < n)
                    s2 = s.substr(i+2);
                    s = s1 + s2;
                    break;
                }
            }
            if(found == false && s.size() > 0)
                return "Bad";
        }
        return "Good";
    }
};

int main()
{
    GoodString st;
    cout << st.isGood("aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb") << endl;
    return 0;
}
