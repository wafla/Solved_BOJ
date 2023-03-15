while True:
    x = int(input());
    if x==0:
        break;
    else:
        sum = 0;
        for i in range(1, x+1):
            sum+=i;
        print(sum);