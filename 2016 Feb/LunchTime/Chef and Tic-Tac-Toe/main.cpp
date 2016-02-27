
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include <bits/stdc++.h>
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

char in[21][21];
int n,m;
int dx[] = {1,0,-1,-1,-1,0,1,1};
int dy[]  ={1,1,1,0,-1,-1,-1,0};
bool isWinning(int a, int b, int x, int y){
    int cnt=0;
    int i=a,j=b;
    bool inserted=false;
    while(true){
        if(i >= 0 && i < n && j>=0 && j <n){
            if(in[i][j] == 'X'){
                cnt++;
                if(cnt == m){
                    return true;
                }
                }else if(in[i][j] == '.'){
                    if(inserted==false){
                        cnt++;
                        inserted=true;
                    }else{
                        return false;
                    }
                    if(cnt == m){
                        return true;
                    }
                    
                }else{
                    return false;
                }
        }else{
            return false;
        }
        
        i += x;
        j += y;
    }
    
    /*int p,q;
    if(cnt == m-1){
        p = a-x;
        q = b-y;
        if(p >= 0 && p < n && q >=0 && q < n && in[p][q] == '.'){
            return true;
        }
        p = lx+x;
        q = ly+y;
        if(p >= 0 && p < n && q >=0 && q < n && in[p][q] == '.'){
            return true;
        }
    }*/
    return false;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i,j,k;
    int t;
    cin >> t;
    
    while(t--){
        cin >> n >> m;
        getchar();
        forl(i,0,n){
            gets(in[i]);
        }
        if(m == 1){
            cout << "YES\n";
            continue;
        }
        bool ok=false;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(in[i][j] == 'X'){
                    for(k=0;k<8;k++){
                        if(isWinning(i,j,dx[k],dy[k])){
                            ok=true;
                            j=n;
                            i=n;
                            break;
                        }
                    }
                }
                
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}

