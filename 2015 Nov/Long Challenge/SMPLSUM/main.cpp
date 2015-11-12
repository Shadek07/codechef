    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <iostream>
    #include <algorithm>
    #include <cstring>
    using namespace std;
    #define MAX 10001
    int phi[MAX];
    void sieve_phi(){
        int i,j;
        bool isPrime[MAX];
        memset(isPrime, true, sizeof(isPrime));
        isPrime[1] = false;
        for(i = 1; i<MAX; i++){
            phi[i] = i;
        }
        for(i = 1; i<MAX;i++){
            if(isPrime[i]){
                for(j=i;j<MAX;j += i){
                    if(j != i)
                    isPrime[j] = false;
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
            if(n > 10000){
                printf("0\n");
                continue;
            }
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
     
