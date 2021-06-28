def get_new(a):
    return (a % 10) * 10 + (a // 10 + a % 10) % 10


n = int(input())
cnt = 1
new = get_new(n)
while n != new:
    new = get_new(new)
    cnt += 1
print(cnt)
