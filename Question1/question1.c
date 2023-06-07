#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum TypeTag {ADD, SUB, MUL,DIV, FIBO} TypeTag;

typedef struct Node
{
    TypeTag type;
} Node;

/* Calculations */

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

int divide(int a, int b){
    return a / b;
}

int fibo(int a, int b){
    if (b){
        perror("At fibonacci: Expected 2nd argument to be NULL, received an integer.\n");
        return -1;
    }
    int pos = (a < 0)? -1 * a : a;
    int fib[pos+1];
    int i;

    // Base cases
    fib[0] = 0;
    fib[1] = 1;

    // Calculate Fibonacci values using dynamic programming
    for (i = 2; i <= pos; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return (pos == a)? fib[pos] : pow(-1,a+1) * fib[pos];
}

int (*makeFunc(TypeTag type))(int,int)
{
    switch(type)
    {
        case SUB:
            return &sub;
        case MUL:
            return &mul;
        case FIBO:
            return &fibo;
        case DIV:
            return &divide;
        case ADD:
        default:
            return &add;
    }
}

int calc(Node* n)
{
    printf("%d\n",n);
    return n;
}

int main()
{
    /* Problem: Type inconsistency:
        Assuming `makeFunc` returns a pointer to a function, based on the usage, 
        Let's call the function to which a pointer is returned : factory.

        Factory has to return a Node pointer. 
        In the first 2 lines, Factory is assumed to receive 2 integers as arguments.
        However, in the following line (where `sub` is declared), it is assumed to 
        receive 2 Node pointers, which conflicts with the assumption that is receives 2 integers.

        To confuse things even more, in the line where `fibo` is declared, it is assumed to receive a 
        node pointer and a void pointer.
        
        Any implementation of `makeFunc` in this case will result in a confiction. `makeFunc` can 
        only return a pointer to a function whose signature is fixed: either receives (int,int), or
        (Node*, Node*).
    */

    /* Problem: Node structure
        The given structure of node only captures its type, however, it is somehow required to make sense
        of the operands passed at creation. It would be possible if the node stucture also stored the
        2 operands.

        This raises the question of: What does `calc` do?
        
        If the calculations happen at a different time than node creation, how is it possible
        to create another node based on the result of a calculation that did not yet happen, like 
        in the line where `sub` is declared? (assuming the problem of conflicting types was solved)

        If the calculations happen at the same time as creation, the following should be considered:
        - Where is the result stored, if Node only captured the `TypeTag`?
        - what is then the purpose of calling `calc`?
    */
    /* My conclusion
        The code in this file works, in the sense that is produces correct outputs, but in order to 
        disregard the typing conflicts and the limited structure of `Node`, lots of good practices 
        were ignored and my instinct as a clean coder was crushed.
        
         - The node pointer is used to store the result of the calculation that happens
        at creation time, so `Node*` turns into `int`.

        - `fibo` was implemented using dynamic programming, as required.

        - `calc` doesn't perform any calculaions, it prints the result.

        In conclusion, one can only provide a good answer to a good question.
    */
    Node *add = (*makeFunc(ADD))(10, 6); 
    Node *mul = (*makeFunc(MUL))(5, 4); 
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *fibo = (*makeFunc(FIBO))(sub, NULL);
    
    calc(add); 
    calc(mul);
    calc(sub);
    calc(fibo);
}

/*Output
add : 16
mul : 20
sub : 4
fibo : 3
*/