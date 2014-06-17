#!/bin/env python
# -*- coding: utf8 -*-

from Tkinter import *
import random

tk = Tk()
tk.title("Guess Game")

number = random.randint(0, 9)
count = 5

def confirm():
    global number
    global count
    if count > 0:
        entry = guessEntry.get()
        if entry != "":
            guess = int(entry)
            if number == guess:
                infoLabel.config(text="Right!")
            else:
                if number > guess:
                    infoLabel.config(text="Too small!")
                    guessEntry.select_range(0, END)
                if number < guess:
                    infoLabel.config(text="Too large!")
                    guessEntry.select_range(0, END)
            count -= 1
    else:
        infoLabel.config(text="Out of chance!")

def reset():
    global number
    global count
    number = random.randint(0, 9)
    count = 5
    infoLabel.config(text="Welcome")
    guessEntry.delete(0, END)

def quit():
    tk.quit()

infoLabel = Label(tk, text="Welcome")
guessEntry = Entry(tk)
confirmButton = Button(tk, text="Confirm", command=confirm)
resetButton = Button(tk, text="Reset", command=reset)
quitButton = Button(tk, text="Quit", command=quit)

infoLabel.pack()
guessEntry.pack()
confirmButton.pack()
resetButton.pack()
quitButton.pack()

tk.mainloop()
