*This project has been created as part of the 42 curriculum by siliu.*

# Description
This subject need to sort a list of numbers in stack a, by using certain operations like swap, rotate, push and so on . In the mean time , we have another stack b could be used to contain the nubmbers shortly.
This project used RADIX SORT as algorithme, and small sort for numbers which are below equal to 5.
Chain list is used to contain the numbers;

# Instruction
The project includes mainly parsing, assign index, do operations, choose sort algorithme 4 parts.

1.Parsing(main.c, check_error.c)
The parsing part used ft_split functionto seperate the nbrs in one argument.

Error checking is needed before building stacks , to avoid invalid numbers, out of int range nbrs ,duolicate nbrs and so on.

build stack and add elements.

2.assign index(assign_index.c)
To serve radix sort algo, I assign every number an index start from 0 , which will allow us to sort easily.
In this part, I first put all the numbers in the tab , then used bubble sort to sort all the numbers and then assign them index.

3.do operations(swap.c push.c rotate.c reverse_rotate.c)
From the subject, only limited operations are allowed, so I wrote every group operation in one file

4.choose sort algo
There are radix sort and small sort.
Radix sort, I used bits to sort all the numbers , from the lowest bit position to the highest. All the bit position is 1 , they stay in stack a and to ra, which is to stay in the end.

The bit whose position is 0, they will be pushed to stack b.

After finished checking all the first bit of all the nbs, those who are in stack b will be pushed to stack a again.

And now first bit is sorted, we will start checking the second one until the biggest bit of the biggest number. (Here we are always dealing with new index).

# Resources
AI is used to fix hidden errors and provide non-repeating nbrs to test.