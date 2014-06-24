#!/bin/env python
# -*- coding: utf8 -*-

def Hanoi(n=1, A="A", B="B", C="C"):
    if n == 1:
        print "Move disk %d from %c to %c" % (n, A, C)
    else:
        Hanoi(n - 1, A, C, B)
        print "Move disk %d from %c to %c" % (n, A, C)
        Hanoi(n - 1, B, A, C)
