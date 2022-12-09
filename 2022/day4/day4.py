import fileinput

def range_contained(r1, r2):
    if r1[0] == r2[0] or r1[1] == r2[1]:
        return True
    elif r1[0] < r2[0]:
        return r1[1] > r2[1]
    else:
        return r1[1] < r2[1]

def range_overlap(r1, r2):
    if range_contained(r1,r2):
        return True
    range2 = range(r2[0], r2[1]+1)
    for i in r1:
        if i in range2:
            return True
    return False
    

total = 0
for line in fileinput.input():
    line = line.strip()
    pairs = line.split(',')
    data = [tuple([int(i) for i in pairs[0].split('-')]), tuple([int(i) for i in pairs[1].split('-')])]
    if (range_overlap(data[0], data[1])):
        total += 1

print(total)