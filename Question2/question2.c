#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RECURSIVE 'r'
#define ITERATIVE 'i'
#define DYNAMIC_PROGRAMMING 'd'


/*start the timer*/
clock_t tick();

/*get time difference in milliseconds*/
double tock(clock_t start);

int FIter(int n);
int FRec (int n);
int FDP  (int n);

int f(int n, char method)
{
    switch (method)
    {
        case RECURSIVE:
            return FRec(n);
        case ITERATIVE:
            return FIter(n);
        case DYNAMIC_PROGRAMMING:
        default:
            return FDP(n);
    }
}

int main(int argc, char** argv)
{
    int n, start, res;
    double end;
    n = atoi(argv[1]);

    printf("Approach \t\t\t| Result \t| Time spent (ms)\n-------------------------------------------------\n");
        
    start = tick();
    res = f(n, ITERATIVE);
    end = tock(start);
    printf("Iterative \t\t\t| %d \t\t| %.3f\n",res,end);
    
    start = tick();
    res = f(n, DYNAMIC_PROGRAMMING);
    end = tock(start);
    printf("Dynamic\\  \t\t\t| %d \t\t| %.3f\n",res,end);
    printf("Programming \t\t| \t\t\t\t|\n");

    start = tick();
    res = f(n, RECURSIVE);
    end = tock(start);
    printf("Recursive \t\t\t| %d \t\t| %.3f\n",res,end);
    
    return 0;
}

int FIter(int n)
{
    if (n<3)
        return n;
    
    int prev[] = {0,1,2,0};

    for (int i = 3; i <= n; i++)
    {
        prev[3] = prev[0] + prev[1];
        prev[0] = prev[1]; 
        prev[1] = prev[2]; 
        prev[2] = prev[3];
    }
    return prev[3];
}
int FRec (int n)
{
    if (n < 3)
        return n;
    return FRec(n - 3) + FRec(n - 2);
}
int FDP  (int n)
{
    int f[n+1];
    int i;

    // Base cases
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;

    // Calculate Fibonacci values using dynamic programming
    for (i = 3; i <= n; i++) {
        f[i] = f[i-3] + f[i-2];
    }
    return f[n];
}

clock_t tick()
{
    return clock() * 1000;
}

double tock(clock_t start)
{
    clock_t end;
    end = clock() * 1000;
    double diff = (double)(end - start);
    return diff / CLOCKS_PER_SEC;
}