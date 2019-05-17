# ft_select


# About
ft_select is the third project of the Unix branch at 42. The goal for this project is to learn more about screen oriented programs using termcap/terminfo libraries in the C programming language. It's originally just an argument viewer in the terminal but I decided to take it one step further and gave it browsing capabilities on the file system.

The main goal, however, is to build my own functional shell. Something like zsh and bash, this is what the next project at my school is about and ft_select is just a small part of it.

# How to use it
Requirements
To be able to build and run this program, you'll need:

A Unix system
GNU make (v3.81)
GCC (v4.2.1)
Those are the versions used during development.

If you're on Linux, make sure you install

The termcap library:

  sudo apt-get install libncurses5-dev
Building
Download/Clone this repo

 git clone https://github.com/r4meau/ft_select
cd into the root directory and run make

 cd ft_select
 make
Running
A basic usage would involve at least one argument:

./ft_select hello
