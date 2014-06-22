#!/bin/env python
# -*- coding: utf8 -*-

# def isPrime_1 - START #
import math
def isPrime_1(n):
    if n <= 1:
        return
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True
# def isPrime_1 - END #

# def isPrime_2 - START #
def isPrime_2(n):
    if n <= 1:
        return
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True
# def isPrime_2 - END #

# def isPrime_3 - START #
def isPrime_3(n):
    if n <= 1:
        return
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    return True
# def isPrime_3 - END #

# test - START #
for i in range(1, 20):
    print "isPrime_1(%d): %s\nisPrime_2(%d): %s\nisPrime_3(%d): %s\n" % (i, isPrime_1(i), i, isPrime_2(i), i, isPrime_3(i))
# test - END #
