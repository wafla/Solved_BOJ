while True:
    try:
        x,y=map(int,input().split());
        print(int(y/(x+1)));
    except:
        break;