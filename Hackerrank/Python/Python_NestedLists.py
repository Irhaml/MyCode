
#//////////////////////////////////////////////////////#
#/ This program was written by Muhammad Irham Luthfi. /#
#/ Intended for educational use.                      /#
#/ No rights reserved.                                /#
#//////////////////////////////////////////////////////#

n = int(input())

all_score = []
records = []

for i in range(n):
    # Use raw_input() for Phyton 2.x
    name = input()
    score = float(input())

    # Put into list
    all_score.append(score)
    records.append([name, score])

# Remove duplicate score
all_score = list(dict.fromkeys(all_score))

# Sort score increasing
all_score.sort()

# Take second lower score
SLower = all_score[1]

# Make list of name who score is second lower score
student = [i[0] for i in records if i[1]==SLower]

# Sort alphabetically
student.sort()

for i in student:
    print(i)
    

