import fileinput

def get_score(letter):
    if letter.islower():
        return ord(letter) - 96
    else:
        return ord(letter) - 38

total = 0
idx = 0
lines = list(fileinput.input())
lines = [l.strip() for l in lines]
while (idx < len(lines)):
    counts = {}
    for i in range(0+idx,3+idx):
        items = set(lines[i])
        for item in items:
            try:
                counts[item] += 1
            except:
                counts[item] = 1
    for k,v in counts.items():
        if v == 3:
            total += get_score(k)
            break
    idx += 3
    
print(total)