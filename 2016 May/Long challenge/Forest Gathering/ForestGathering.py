import sys

n,W,L  = map(int,sys.stdin.readline().split())

H = list()

R = list()

for i in range(n):
	a,b = map(int,sys.stdin.readline().split())
	H.append(a)
	R.append(b)

low = 0
high = 1e18
mid=0
ans=0

while low <= high:
	mid = (int)(low+high)/2
	x = 0
	for i in range(n):
		h = H[i] + R[i]*mid
		if h>=L:
			x = x + h
		if x>=W:
			break
	if x >= W:
		high = mid-1
		ans = mid
	else:
		low = mid+1
print ans