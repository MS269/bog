import sys

n = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().split()))
operators = list(map(int, sys.stdin.readline().split()))
max_num = -1000000000
min_num = 1000000000


def insert_operators(num, add, sub, mul, div, cnt):
    global max_num, min_num

    if cnt == n:
        max_num = max(max_num, num)
        min_num = min(min_num, num)
        return

    if add:
        insert_operators(num + numbers[cnt], add - 1, sub, mul, div, cnt + 1)
    if sub:
        insert_operators(num - numbers[cnt], add, sub - 1, mul, div, cnt + 1)
    if mul:
        insert_operators(num * numbers[cnt], add, sub, mul - 1, div, cnt + 1)
    if div:
        insert_operators(
            int(num / numbers[cnt]), add, sub, mul, div - 1, cnt + 1)


insert_operators(numbers[0], operators[0], operators[1],
                 operators[2], operators[3], 1)

print(max_num)
print(min_num)
