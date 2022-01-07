import sys
import re
input = sys.stdin.readline

n = int(input())
count = 0
number = 666
p = re.compile('.*666.*')

while (count < n):
    tmp = str(number)
    if (p.search(tmp)):
        count += 1
    number += 1
print(number - 1)