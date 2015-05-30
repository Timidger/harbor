#!/usr/bin/python2

import sys

lookupTable = {"NST_PUTC" : "0x00",
               "INST_GET"  : "0x01",
               "INST_IMD"  : "0x02",
               "INST_JMP"  : "0x03",
               "INST_ADD"  : "0x04",
               "INST_PUTI" : "0x05",
               "INST_PUTS" : "0x06",
               "INST_BR"   : "0x0"
              }

def lookup(code):
    if code in lookupTable:
        return lookupTable[code]
    # If register, return the register number
    if code[0] == "r":
        return code[1:]
    # Else last element, which is just the address of the next instruction
    return hex(int(code))

def read_source(input_file):
    output = []
    with open(input_file, "r") as infile:
        for line in infile.readlines():
            line = line.partition("#")[0]
            if line:
                output.append(line.split())
    return output

def write_hex_code(output_file, hex_code):
    with open(output_file, "wb") as outfile:
        for line in hex_code:
            for argument in line:
                outfile.write(lookup(argument) + " ")


if __name__ == "__main__":
    import os
    test_path = "test.source"
    fake_data = open(test_path, "w")
    fake_data.write("NST_PUTC r5 r7 r8 2 # This is a comment\n")
    fake_data.write("INST_GET r7 r5 r8 3\n")
    fake_data.write("#NST_PUTC r5 r7 r8 2\n")
    fake_data.close()

    code = read_source(test_path)
    assert code == [["NST_PUTC", "r5", "r7", "r8", "2"],
                    ["INST_GET", "r7", "r5", "r8", "3"]]
    test_output_file = "test.byte"
    write_hex_code(test_output_file, code)

    with open(test_output_file, "r") as test_output:
        test_output = "".join(list(test_output)).strip()
        assert test_output == " ".join(["0x00", "5", "7", "8", "0x2",
                                        "0x01", "7", "5", "8", "0x3"])

    os.remove(test_path)
    os.remove(test_output_file)
