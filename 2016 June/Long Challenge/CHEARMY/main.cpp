

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

int digitCount(int n){
    int cnt=0;
    while(n){
        cnt++;
        n /= 10;
    }
    return cnt;
}
int getDigit(int n, int t){
    int i=0;
    while(n){
        int d = n%10;
        if(i==t)
            return d;
        i++;
        n /= 10;
    }
}
bool isMagical(int n){
    int digits = digitCount(n);
    int mx = 1<<digits;
    int i,j;
    int sum=0;
    forl(i,1,mx){
        int prod=1;
        for(j=0;j<digits;j++){
            if(i&(1<<j)){
                prod = prod*(getDigit(n,j));
            }
        }
        sum += prod;
    }
    if(sum%2==0)
        return true;
    else
        return false;
}
ull getCnt(int cnt){
    ull p = 1;
    while(cnt){
        p *= 5;
        cnt--;
    }
    return p;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    //int i;
    
    unsigned long long int k;
    ull i,j,a,b,c;
    /*forl(i,1,501){
        if(isMagical(i))
            cout << i << " is magical" << endl;
    }*/
    int t;
    cin >> t;
    while(t--){
        cin >> k;
        if(k<=5){
            cout << 2*(k-1) << endl;
            continue;
        }
        a = 5; //for first 5 magical numbers - 0,2,4,6,8
        b = 0;
        c = 4; //4 digits(2,4,6,8) for leftmost position 
        int len = 1;
        while(true){
            len++;
            c *= 5;//5 digits(0,2,4,6,8) for other positions
            a += c;
            if(a>=k){
                break;
            } 
        }
        b = k - (a-c); //b'th integer with length 'len'
        bool first=true;
        while(len){
            
            int st = 0;
            if(first){
                st = 2; //Leftmost digit can't start with 0
            }
            for(;st<=8;st+=2){
                ull cover = getCnt(len-1);
                if(b <=cover){
                    cout << st;
                    break;
                }else{
                    b -= cover;
                }
            }
            first = false;
            len--;
        }
        cout << endl;
    }
    return 0;
}
