import fileinput

grid = list(fileinput.input())
grid = [list(s.rstrip()) for s in grid]
for i in range(len(grid)):
    grid[i] = [int(n) for n in grid[i]]

def tree_visible(x, y):
    tree_val = grid[y][x]
    nums = []

    nums.append(max(grid[y][:x])) if x > 0 else nums.append(-1)
    nums.append(max([n[x] for n in (grid[:y])])) if y > 0 else nums.append(-1)
    nums.append(max([n[x] for n in (grid[(y+1):])])) if y + 1 < len(grid) else nums.append(-1)
    nums.append(max(grid[y][(x+1):])) if x + 1 < len(grid[0]) else nums.append(-1)

    return tree_val > min(nums)

def scenic_score(x, y):
    tree_val = grid[y][x]
    score = 1

    row = grid[y][:x]
    flag = False
    for i in reversed(range(0, len(row))):
        if row[i] >= tree_val:
            score *= len(row) - i
            flag = True
            break
    if not flag: 
        score *= len(row)
    
    row = grid[y][(x+1):]
    flag = False
    for i in range(len(row)):
        if row[i] >= tree_val:
            score *= i + 1
            flag = True
            break
    if not flag:
        score *= len(row)
        
    col = [n[x] for n in (grid[:y])]
    flag = False
    for i in reversed(range(0, len(col))):
        if col[i] >= tree_val:
            score *= len(col) - i
            flag = True
            break
    if not flag:
        score *= len(col)
        
    col = [n[x] for n in (grid[(y+1):])]
    flag = False
    for i in range(len(col)):
        if col[i] >= tree_val:
            score *= i + 1
            flag = True
            break
    if not flag:
        score *= len(col)

    return score

result = 0
for x in range(len(grid[0])):
    for y in range(len(grid)):
        if scenic_score(x, y) > result:
            result = scenic_score(x, y)

print(result)