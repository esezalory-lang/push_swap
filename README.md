*This project has been created as part
of the 42 curriculum by esezalor*

## Description
* "***Push_Swap***" is a program named that takes as an argument a formatted list of integers

* The goal is to sort the stack with the lowest possible number of operations. During
the evaluation process, the number of instructions found by your program will be
compared against a limit: the maximum number of operations tolerated. If your
program either displays a longer list or if the numbers aren’t sorted properly, your
grade will be 0.

* The program must display the shortest sequence of instructions needed to sort stack
a with the smallest number at the top.

* Instructions must be separated by a ’\n’ and nothing else.

* If no parameters are specified, the program must not display anything and should
return to the prompt

* In case of error, it must display "Error" followed by an ’\n’ on the standard error.


## Instructions

The ideal first step after you git clone the repository of the student check for `norminette` on his/her file, if no errors, proceed with the `make`function in order to compile all files into an executable.

As per the ***en.subject*** file found on the 42 intranet, Push Swap should ideally be run on `bash` using the following command:

```
$>ARG="[Insert Numbers here]"; ./push_swap $ARG
```
What this will do is just run your program in its purest form and ideally you should see the moves being printed out in your standard output (it can also print out nothing or "Error" if you decided to test for edge cases).

To then check for the amount of lines provided by the program (ie. amount of moves) or to test against the provided checker you can execute the following respective commands:

```
$>ARG="[Insert Numbers here]"; ./push_swap $ARG | wc -l

// or

$>ARG="[Insert Numbers here]"; ./push_swap $ARG | ./checker_linux $ARG
```
For the `./checker_linux` line make sure that when you download the checker you modify it to give yourself executable rights through the following command:
```
chmod +x ./checker_linux
```

## Resources
Throughout this project I used a variety of resources ranging from Google's Notebook LM to help me breakdown the project itself as well as to better understand `structs` and `lists`, you can find this resource in the following link: [Push_Swap - Notebook LM](https://notebooklm.google.com/notebook/2b36d609-cfb1-41e2-a227-9e7b8ac56416)

I also used the infamous book entitled ***"Algorithms in C"** by Robert Sedgewick* which can be found in this [link](https://theswissbay.ch/pdf/Gentoomen%20Library/Algorithms/Algorithms%20in%20C.pdf), to inform me on the various algorithms out in the world, to learn a bit more on linked lists, to understand bitwise operations, and finally to understand the **RADIX Sort (LSD/Straight Sort)** which I used for this project.