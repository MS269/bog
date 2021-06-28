n, x = map(int, input().split())
a = [i for i in input().split() if int(i) < x]
print(' '.join(a))
