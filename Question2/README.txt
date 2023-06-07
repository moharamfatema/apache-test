Apache AGE Internship 2023 Coding Test – Questions 1 and 2 (Backend) 

The development envirenment is on replit, with gcc.
You can run the code on replit 
(at https://replit.com/@moharamfatema/ApcheTest) to avoid the headache of environment setups.

Question 2:

To compile the source code, in a terminal, run the following:

$ gcc Question2/question2.c -o question2.o -lm

And to run the program with input 3, run:

$ ./question2.o 3

or replace 3 with any integer.

The function was implemented in 3 different ways:

1. Dynamic programming
2. Iterative
3. recursive

The main difference between the first and second approach is space complexity:

Dynamic programming requires O(n) space, where n is the number to calculate F(n) for.
Iterative approach only uses O(1) space. It allocates an array of 4 integers.

The output is a table that compares the results and computing time of all 3 approaches.

Here's 2 sample runs, on the inputs 50 and 40:

$ gcc question2.c -o question2.o -lm
$ ./question2.o 50
Approach            | Result    | Time spent (ms)
-------------------------------------------------
Iterative           | 995507        | 0.001
Dynamic\            | 995507        | 0.001
Programming         |               |
Recursive           | 995507        | 2.614

$ ./question2.o 40
Approach            | Result    | Time spent (ms)
-------------------------------------------------
Iterative           | 59815         | 0.005
Dynamic\            | 59815         | 0.001
Programming         |               |
Recursive           | 59815         | 0.120

It's worth noting that the dynamic programming approach takes slightly less time than iterative in the 
second run, but recursive approach is significantly slower and consumes more resources.