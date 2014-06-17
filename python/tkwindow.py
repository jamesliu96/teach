#!/bin/env python
# -*- coding: utf8 -*-

from Tkinter import *

tk = Tk()
tk.title("Hello, world!")
hello = Label(tk, text="Hello, world!")
hello.pack()
e = Entry(tk)
e.pack()
def c():
    print(e.get())
def i():
    e.insert(0, e.get())
def q():
    tk.quit()
show = Button(tk, text="SHOW", command=c)
show.pack()
copy = Button(tk, text="COPY", command=i)
copy.pack()
quit = Button(tk, text="QUIT", command=q)
quit.pack()
tk.mainloop()
