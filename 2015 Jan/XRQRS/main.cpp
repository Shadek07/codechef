
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

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

int a[50002];
int arr[50002];

int partition1(int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int l, int r, int k)
{
    
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition1( l, r);
 
        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left subarray
            return kthSmallest( l, pos-1, k);
 
        // Else recur for right subarray
        return kthSmallest( pos+1, r, k-pos+l-1);
 
}

int max_xor(int l,int r,int x)
{
	int mx = 0,i;
	int y;
	forl(i,l,r+1)
	{
		if( (a[i]^x) > mx)
		{
			mx = a[i]^x;
			y = a[i];
		}
	}
	return y;
}
int less_cnt(int l, int r, int x)
{
	int cnt=0;
	int i;
	forl(i,l,r+1)
	if(a[i]<=x)
		cnt++;
	return cnt;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i,j;
    
    int m;
    cin >> m;
    int t;
    int n=0;
    int x,l,r,k;
    while(m--)
	{
		scanf("%d",&t);
		if(t==0)
		{
			scanf("%d",&x);
			a[n++] = x;
		}
		else if(t==1)
		{
			scanf("%d %d %d",&l,&r,&x);
			l--,r--;
			cout << max_xor(l,r,x) << endl;
		}
		else if(t==2)
		{
			scanf("%d",&k);
			n -= k;
		}
		else if(t==3)
		{
			scanf("%d %d %d",&l,&r,&x);
			l--,r--;
			cout << less_cnt(l,r,x) << endl;
		}
		else
		{
			scanf("%d %d %d",&l,&r,&k);
			l--,r--;
			j=0;
			forl(i,l,r+1)
			{
				arr[j++] = a[i];
			}
			cout << kthSmallest(0, r-l, k) << endl;
		}
	}
    return 0;
}

