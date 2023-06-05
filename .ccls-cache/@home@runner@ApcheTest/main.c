#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum TypeTag {ADD, SUB, MUL, FIBO} TypeTag;

typedef struct Node
{
    TypeTag type;
} Node;

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return b - a;
}

int mul(int a, int b){
    return a * b;
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
sub : -4
fibo : 2
*/