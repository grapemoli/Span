# Span
The Span algorithm: given a user-defined n, create a dataset of size n. Then, give the span of each index. The span is the total number of total previous adjacent values that are lower than the current value. The span algorithm is a common algorithm for stocks!

## User Inputs
There are two implementations:
1. Without the Stack
2. With the Stack

After typing 'make run' into the command line, the user can choose between the stack or non-stack implemtation. 'yes' will get the stack implementation. 'no' will result in the non-stack implemetation. The reply is case-sensitive.

Directly after, users will be asked to input an integer value greater or equal to zero. This integer is the length of the data, but also acts as the seed for the randomly generated integers.

The last step: the user is asked to input the high end of the range of data set values. This should be an integer greater than 0.

## User Outputs
The user will be listed all the pseudo-random dataset values, and each value's respective span.

## Notes
Please note that for both implementations, the 'worst' span is 1. 
