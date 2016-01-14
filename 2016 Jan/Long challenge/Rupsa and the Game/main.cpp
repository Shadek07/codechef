
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
#include<climits>
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

#define MAX 100002
#define INF 9999999
#define MOD 1000000007

map<pii, int> mp;
int sz;
vector<int> v;
vector<int> values;
ull getMultMod(ull a, ull b){
    return ((a%MOD)*(b%MOD))%MOD;
}
void calc(int n){
    vector<int> v;
    while(n){
        v.pb(n%10);
        n /= 10;
    }
    int i;
    int val=0;
    for(i = v.size()-1;i>=1;i--){
        int a = v[i];
        int b = v[i-1];
        val += a*b;
        if(a>b)
            swap(a,b);
        mp[make_pair(a,b)]++;
    }
    values.pb(val);
}
void doit(int num, int cnt){
    if(cnt == sz){
       calc(num);
       return; 
    }
    doit(v[cnt]*pow(10.0,cnt)+num, cnt+1);  
    doit(num*10 + v[cnt], cnt+1);  
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    ull prefixSum[MAX+1];
    ull twosPower[MAX];
    int arr[MAX];
    long i = 0;
    long j;
    int k;
    twosPower[0] = 1;
    forl(i,1,MAX){
        twosPower[i] = getMultMod(twosPower[i-1],2LLU);
    }
    //cout << twosPower[80] << endl;
    int t;
    int n,a,b;
    cin >> t;
    unsigned long long ans;
    ull tmp;
    while(t--){
        scanf("%d",&n);
        n++;
        v.clear();
        mp.clear();
        values.clear();
        forl(i,0,n){
            scanf("%d",&arr[i]);
            v.pb(arr[i]);
        }
        sz = n;
        doit(v[0],1);
        ull tot = 0;
        for(i=0;i<n-1;i++){
            int sum=0;
            for(j=i+1;j<n;j++){
                 a = v[i];
                 b = v[j];
                 if(a>b)
                 {
                     swap(a,b);
                 }
                 cout << "(" << a << " x " << b << ")"<< " : " << mp[make_pair(a,b)]<< " times" << endl;
                 sum += (a*b*mp[make_pair(a,b)]);
            }
            cout << "------------------------"  << endl;
            tot += sum;
             
        }
        //cout << tot << endl;
        //forl(i,0,values.size())
        //{
            //cout << " " << values[i];
        //}
        //cout << endl;
        if(n==2){
            tmp = getMultMod(arr[0], arr[1]);
            tmp = getMultMod(tmp,2);
            cout << tmp << endl;
            continue;
        }
        ans = 0;
        forl(i,1,n){
            tmp = getMultMod(arr[0], arr[i]);
            tmp = getMultMod(tmp, twosPower[n-i]);
            ans = (ans+tmp)%MOD;
        }
        long long base = 0;
        int p=n-2;
        forl(i,2,n){
            tmp = getMultMod(arr[i],twosPower[p]);
            base = (base+tmp)%MOD;
            p--;
        }
        forl(i,1,n){
            tmp = getMultMod(arr[i], base);
            ans = (ans+tmp)%MOD;
            ull sub = getMultMod(arr[i+1],twosPower[n-2]);
            base -= sub;
            if(base<0)
                base += MOD;
            base = getMultMod(2,base);
        }
        
        cout << ans << endl;
        
    }
    return 0;
}
