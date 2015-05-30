import sys

lookupTable = [("")]
def lookup(argument):
    for pair in 

output = []
with open(sys.argv[1], "r") as infile:
    for line in infile.splitlines():
        outputRow = []
        for argument in line.split():
            if argument == "#":
                break
            outputRow.append(argument)
        output.append(outputRow)

with open(sys.argv[2], "wb") as outfile:
    for line in output:
        for argument in line:
            outfile.write(lookup(argument))
