import math

T = int(input())

while T > 0:
	a, b = map(int, input().split())
	print(math.gcd(a, b))
	T -= 1