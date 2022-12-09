import fileinput


built = False
stack_lines = []
stacks = []

def build_stacks(lines):
    # get position of letters
    indices = lines[-1:][0]
    letter_pos = [i for i in range(len(indices)) if indices[i].isdigit()]

    # build stacks bottom up
    result = [[] for i in letter_pos]
    lines = lines[:-1]
    for line in lines[::-1]:
        stack_idx = 0
        for i in letter_pos:
            if line[i] != ' ':
                result[stack_idx].append(line[i])
            stack_idx += 1

    return result

def move_crates(line):
    words = line.split()
    nums = [int(i) for i in words if i.isdigit()]
    src_idx = nums[1] - 1
    dest_idx = nums[2] - 1
    part_idx = len(stacks[src_idx]) - nums[0]
    stacks[dest_idx] += stacks[src_idx][part_idx:]
    stacks[src_idx] = stacks[src_idx][:part_idx]

def stack_tops():
    print(stacks)
    result = ""
    for stack in stacks:
        if len(stack) != 0:
            result += stack[-1:][0]
    return result

for line in fileinput.input():
    clean_line = line[:-1]
    if len(clean_line) == 0:
        stacks = build_stacks(stack_lines)
        built = True
    elif not built:
        stack_lines.append(clean_line)
    else:
        move_crates(clean_line)
print(stack_tops())