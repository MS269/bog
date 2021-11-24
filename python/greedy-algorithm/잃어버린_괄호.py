data = input()

# 빼기가 나온 후로는 모두 빼기 연산
result = 0
num = ""
minus = False
for i in data:
    if i == "+":
        if minus:
            result -= int(num)
        else:
            result += int(num)
        num = ""
    elif i == "-":
        if minus:
            result -= int(num)
        else:
            result += int(num)
        minus = True
        num = ""
    else:
        num += i
if minus:
    result -= int(num)
else:
    result += int(num)

print(result)
