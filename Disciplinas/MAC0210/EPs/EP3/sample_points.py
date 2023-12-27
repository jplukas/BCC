#! /usr/bin/python

import argparse
import sympy
import numpy as np
import csv

argParser = argparse.ArgumentParser()
argParser.add_argument('inputfile')
argParser.add_argument('maxpoints', type=int)
args = argParser.parse_args()

x = sympy.var('x')

with open(args.inputfile, 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        func, xmin, xmax = row

        expr = sympy.sympify(func)
        # print(str(expr))
        min = float(sympy.sympify(xmin).evalf())
        max = float(sympy.sympify(xmax).evalf())
        for i in range(2, args.maxpoints + 1):
            # print(f"i = {i}")
            f = sympy.lambdify(x, expr, "numpy")
            x_points = np.linspace(min, max, num=i)
            f_x = f(x_points)
            # print(f_x)
            points = np.array((x_points, f_x)).T
            np.savetxt(f"{str(expr)}_{i}.in.csv", points, delimiter=",")
