# permutation-list (super slow)
Finds all possible permutations for an array of given size, n, initialized to 1, 2, 3, 4..., n

At around 12 or 13 the program starts to take an unbearably long time to execute. Finding the permuations of a 15-element array, on my 4.0ghz processor, would take 181 days.

I used Heap's permutation algorithm with no multithreading, since I dont know how multithreading works.

# To compile:

It's simple, really. Just type into your shell:

`$ gcc main.c -o main`

and you're set. To run the program, type:

`$ ./main`
