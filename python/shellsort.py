#!/bin/env python
# -*- coding: utf8 -*-

def shellSort(A):
    def getCols(n):
        cols = [1]
        val = 1
        while val < n:
            val = int(val * 2.2)
            cols.insert(0, val)
        return cols
    for h in getCols(len(A)):
        for i in range(h, len(A)):
            cur = A[i]
            j = i
            while j >= h and A[j - h] > cur:
                A[j] = A[j - h]
                j -= h
            A[j] = cur
    return A
