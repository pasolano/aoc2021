import fileinput

class Directory:
    contents = {}
    parent = None

if __name__ == "__main__":
    file_structure = {'/': Directory()}
    for line in fileinput.input():
        line = line.rstrip()
        tokens = line.split()

        # line is command
        if tokens[0] == '$':
            pass

        # line is directory
        elif tokens[0] == "dir":
            pass

        # line is file
        else:
            pass
