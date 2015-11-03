#include"stdio.h"
#include"vector"
using namespace std;
#define N 100000
vector<int> GR[N];
int G[N];
int price[N];
bool vis[N];
int findCycle(int init) {
		if (vis[init]) return init;
		vis[init] = true;
		return findCycle(G[init]);
}
long long findBest(int root, int p) {
		vis[root] = true;
		long long ret = price[root];
		for(int c: GR[root]) {
				if (c==p) continue;
				long long alt = findBest(c, root);
				if(alt>0) ret += alt;
		}
		return ret;
}
int main() {
		int T;
		scanf("%d", &T);
		while(T--) {
				int n;
				scanf("%d", &n);
				for(int i=0; i<n; i++)GR[i].clear();
				for(int i=0; i<n; i++) {
						int next;
						scanf("%d", &next);
						next--;
						GR[next].push_back(i);
						G[i] = next;
						vis[i] = 0;
				}
				for(int i=0; i<n; i++)
						scanf("%d", &price[i]);
				long long ans = 0;
				for(int v=0; v<n; v++) {
						if(vis[v])continue;
						int f = findCycle(v);
						int pRoot=f, root=G[pRoot];
						long long val=0;
						do {
								val += findBest(root, pRoot);
								pRoot = root;
								root = G[pRoot];
						} while(pRoot != f);
						if (val>0)
								ans += val;
				}
				printf("%lld\n", ans);
		}
}
