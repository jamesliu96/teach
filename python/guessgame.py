#!/bin/env python
# -*- coding: utf8 -*-

import random

number = random.randint(0, 9)
count = 5

print("** Welcome to the number guess game by James!")
print("** You have three chances to guess a number that is between 0 and 9.")
print("** Good luck!")

while count > 0:
    entry = raw_input("Please guess the number: ")
    if entry != "":
        guess = int(entry)
        if guess > number:
            print("Your guess %d is bigger than the number" % guess)
        else:
            if guess < number:
                print("Your guess %d is smaller than the number" % guess)
            else:
                print("Your guess is correct! The number is %d" % number)
                exit()
        count = count - 1

print("The number is %d" % number)
