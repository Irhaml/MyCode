
#//////////////////////////////////////////////////////#
#/ This program was written by Muhammad Irham Luthfi. /#
#/ Intended for educational use.                      /#
#/ No rights reserved.                                /#
#//////////////////////////////////////////////////////#


n = int(input())

if(n&1):
    print("Weird")
elif(2 <= n <= 5):
    print("Not Weird")
elif(6 <= n <= 20):
    print("Weird")
elif(20 < n):
    print("Not Weird")
