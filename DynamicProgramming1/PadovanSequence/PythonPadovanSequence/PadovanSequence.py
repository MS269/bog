import sys

MAX = 100

padovan_sequence = [0, 1, 1, 1]


def get_padovan_sequence():
    for i in range(4, MAX + 1):
        padovan_sequence.append(
            padovan_sequence[i - 2] + padovan_sequence[i - 3])


get_padovan_sequence()

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    print(padovan_sequence[n])
