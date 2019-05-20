# ft_select


## About

[ft_select](https://github.com/SillyDreamer/ft_select/blob/master/ft_select.en.pdf) is the third project of the Unix branch at 42. The goal for this project is to learn more about screen oriented programs using termcap/terminfo libraries in the C programming language. It's originally just an argument viewer in the terminal but I decided to take it one step further and gave it browsing capabilities on the file system.

The main goal, however, is to build my own functional shell. Something like `zsh` and `bash`, this is what the next project at my school is about and ft_select is just a small part of it.

## How to use it

### Requirements

To be able to build and run this program, you'll need:

* A Unix system
* GNU make
* GCC

Those are the versions used during development.

If you're on Linux, make sure you install

* The termcap library:

		sudo apt-get install libncurses5-dev

### Building

1. Download/Clone this repo

		git clone https://github.com/SillyDreamer/ft_select.git

2. `cd` into the root directory and run `make`

		cd ft_select
		make

### Running

Example:

 	./ft_select hello
	./ft_select *
	
Buttons:

	backspaces -> go back to the folder
	tab -> go to the folder
	del -> delete
	space -> select
	enter -> return selected files

