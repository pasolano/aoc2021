import fileinput

line = fileinput.input()[0]
line = line.split(',')
nums = [int(i) for i in line]


for i in range(256):
    leng = len(nums)
    for j in range(leng):
        if nums[j] == 0:
            nums[j] = 6
            nums.append(8)
        else:
            nums[j] -= 1

print(nums)
