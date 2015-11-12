#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 10000001
int phi[MAX];
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=(N | (1<<pos));}
#define clearBit(S, j) (S &= ~(1 << j))
#define BUF_SIZE 33
char *int2bin(int a, char *buffer, int buf_size) {
    buffer += (buf_size - 1);

    for (int i = 31; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';

        a >>= 1;
    }

    return buffer;
}

void sieve_phi(){
    int i,j;
    int isPrime[MAX/32 + 2];
    int mx = MAX/32+2;
    char buffer[BUF_SIZE];
    buffer[BUF_SIZE - 1] = '\0';
    for(i=0;i<mx;i++)
        isPrime[i] = 0;
    int2bin(isPrime[0], buffer, BUF_SIZE - 1);
    printf("%s\n", buffer);
    
    
    for(i = 1; i<MAX; i++){
        phi[i] = i;
    }
    for( i = 3; i*i < MAX; i += 2 ) 
     {
		 if( Check(isPrime[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j < MAX; j += (i<<1) )
			 {
				 isPrime[j>>5]=Set(isPrime[j>>5],j & 31)   ;
	 		 }
		 }
	 }
	 cout << Check(isPrime[10>>5],10&31) << endl;
    for(i = 1; i<MAX;i++){
        if(Check(isPrime[i>>5],i&31) == 0){
            for(j=i;j<MAX;j += i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    sieve_phi();
    scanf("%d",&t);
    int n;
    int i,j;
    unsigned long long int ans;
    while(t--){
        scanf("%d",&n);
        /*if(n > 10000){
            printf("0\n");
            continue;
        }*/
        ans=0;
        for(i = 1; i*i <= n;i++){
            if(n%i == 0){
                j = n/i;
                ans += phi[n/i]*(n/i);
                if(j != i){
                    ans += phi[n/j]*(n/j);
                }
            }
        }
        printf("%llu\n",ans);
    }
    return 0;
}
