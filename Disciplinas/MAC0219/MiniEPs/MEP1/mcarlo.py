#!/usr/bin/python3
from random import random

n = 10 ** 7
acertos = 0
for i in range(n):
    x = random()
    y = random()
    if x * x + y * y <= 1.0:
        acertos = acertos + 1
print(4 * acertos / n)