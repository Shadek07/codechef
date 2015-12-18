
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

#define MAX 1025
#define MOD 1000000007
long long int dp[MAX][MAX];
int n;
int dist;
map<int, int> mp;
vector<int> v;

int getMask(char fil[11]){
    int i = 0;
    int a = 0;
    //reverse(fil, fil+10);
    forl(i,0,10){
        if(fil[i] == 'w' || fil[i] == '+'){
            a |= (1<<(10-i-1));
        }
    }
    return a;
}
long long int getMod(int p){
    long long int ans = 1;
    long long int base = 2;
    while(p){
        if(p&1)
            ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        p >>=1;
    }
    return ans;
}
long long int doit(int ind, int current){
    if(ind == n){
        return current == 0;
    }
    long long int &res = dp[ind][current];
    if(res == -1){
        res = 0;
        //int tmp = doit(ind+1, current^v[ind]);
        //res = (res + tmp)%MOD;
        long long int by = getMod(mp[ v[ind] ] - 1); //half of 2^count
        long long int tmp = doit(ind+1, current^v[ind]);
        tmp = (tmp*by)%MOD;
        res = tmp;
        tmp = doit(ind+1, current);
        tmp = (tmp*by)%MOD;
        res = (res+tmp)%MOD;
    }
    return res%MOD;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    //cout << getMod(11) << endl;
    int t;
    char photo[11];
    char fil[11];
    int i,j,k,a,b;
    cin >> t;
    getchar();
    
    while(t--){
        gets(photo);
        dist = getMask(photo);
        cin >> n;
        getchar();
        mp.clear();
        v.clear();
        forl(i,0,n){
            gets(fil);
            int mask = getMask(fil);
            if(mp[mask]){
                mp[mask]++;
            }else{
                mp[mask]=1;
                v.pb(mask);
            }
        }
        ms(dp,-1);
        n = v.size();
        long long int ans = doit(0,dist);
        cout << ans << endl;
    }
    return 0;
}
