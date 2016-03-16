
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

#define MAX 1000001
#define INF 9999999

char in[MAX];
int n;
char c;

bool isEqual(){
    int m = n/2;
    int i;
    forl(i,0,m){
        if(in[i] != in[m+i])
            return false;
    }
    return true;
}

bool doit(){
    int cnt=0;
    int j = n-1;
    int i=n/2;
    int match=0;
    while(i>=0){
        if(in[i] != in[j]){
            cnt++;
            if(in[i] == c)
                i--;
            else{
                return false;
            }
        }
        else{
            i--;
            j--;
            match++;
        }
        if(cnt >=2)
            return false;
    }
    return cnt==1 && match == n/2;
}

bool doit2(){
    int cnt=0;
    int j = n-1;
    int i=n/2 - 1;
    int match=0;
    while(i>=0){
        if(in[i] != in[j]){
            cnt++;
            if(in[j] == c){
                j--;
            }else{
                return false;
            }
        }
        else{
            i--;
            j--;
            match++;
        }
        if(cnt >=2)
            return false;
    }
    return cnt==1 && match==n/2;
}


int main(void)
{
    //freopen("input.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    
    //freopen("input.txt", "w", stdout);
    int t;
    int i,j,k;
    /*cout << 50 << endl;
    forl(i,0,200){
        int len = rand()%10;
        if(len%2==0)
            len++;
        forl(j,0,len){
            k = rand()%2;
            cout << char('a'+k);
        }
        cout << endl;
    }
    return 0;*/
    
    cin >> t;
    getchar();
    int cnt[26];
    while(t--){
        gets(in);
        n = strlen(in);
        if(n&1){
            ms(cnt,0);
            if(n==1){
                cout << "NO\n";
                continue;
            }
            forl(i,0,n){
                cnt[in[i]-'a' ]++;
            }
            int num=0;
            int has=0;
            forl(i,0,26){
                if(cnt[i]&1){
                    num++;
                    c = char('a'+i);
                }
                if(cnt[i]){
                    has++;
                }
                if(num>1)
                    break;
            }
            if(has == 1){
                cout << "YES\n";
                continue;
            }
            if(num>1 || num == 0){
                cout << "NO\n";
                continue;
            }
            if(doit() || doit2()){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            if(isEqual()){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
