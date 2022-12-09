import fileinput

def check_buffer(buff):
    for i in range(len(buff)):
        a = buff[i]
        for b in buff[(i+1):]:
            if a == b:
                return False
    return True
        
for line in fileinput.input():
    count = 1
    buffer = ""
    for c in line:
        if count >= 15:
            buffer = buffer[1:] + c
            if check_buffer(buffer):
                print(count)
                break
        else:
            buffer += c
        count += 1