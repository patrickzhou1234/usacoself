n = int(input())
breeds = input()

count = 0
for i in range(n):
    for j in range(3, n-i+1):
        sub = breeds[i:i+j]
        if sub.count('G') == 1 and sub.count('H') == j-1:
            count += 1
        elif sub.count('H') == 1 and sub.count('G') == j-1:
            count += 1

print(count)