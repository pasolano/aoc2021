import fileinput

score = 0
for line in fileinput.input():
    you = ord(line[0]) - 65
    me = ord(line[2]) - 88
    diff = (me - you) % 3
    if diff == 1:
        score += 6
    elif diff == 0:
        score += 3
    score += me + 1
print(score)