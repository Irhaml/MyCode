from math import gcd

t = int(input())
for i in range(t):
    a=input()
    b=input()
    kpk=len(a)*len(b)//gcd(len(a),len(b))
    a = a*(kpk//len(a))
    b = b*(kpk//len(b))
    if a==b:
        print(a)
    else:
        print(-1)
