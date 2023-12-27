#! /usr/bin/python

import fileinput

lines = iter(fileinput.input())
next(lines)
a = next(lines).rstrip()

for line in lines:
    if(line.startswith("Dados")):
        line = next(lines)
        if(line.rstrip() != a):
            print(a)
            print("------------")
            print(line.rstrip())
            exit(1)
            
print("Sucesso!")