
#//////////////////////////////////////////////////////#
#/ This program was written by Muhammad Irham Luthfi. /#
#/ Intended for educational use.                      /#
#/ No rights reserved.                                /#
#//////////////////////////////////////////////////////#

n = int(input())

# Split the number
# Use raw_input() for python 2.x
score_str = input().split(" ")
# Remove Duplicate
score_str = list(dict.fromkeys(score_str))

# From list of string to list of int
# Convert string to int
score_int = [int(i) for i in score_str]
# Sort decreasing
score_int.sort(reverse = True)

print(score_int[1])
