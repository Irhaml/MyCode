
#//////////////////////////////////////////////////////#
#/ This program was written by Muhammad Irham Luthfi. /#
#/ Intended for educational use.                      /#
#/ No rights reserved.                                /#
#//////////////////////////////////////////////////////#

def is_leap(year):
    leap = False
    
    if year%400 == 0 or (year%4 == 0 and year%100 != 0):
        leap = True
    
    return leap

# Use raw_input() for 2.x
year = int(input())
print is_leap(year)
