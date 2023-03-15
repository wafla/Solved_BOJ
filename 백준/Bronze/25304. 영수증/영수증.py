num = int(input());
a = int(input());
sum = 0;
for i in range(0,a):
    x, y = map(int,input().split());
    sum+=x*y;
if num == sum:
    print("Yes");
else:
    print("No");
