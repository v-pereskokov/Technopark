#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum { false, true } bool;
typedef unsigned long u_long;

const int MAX_SIZE = 65;
const int MAX_SIZE_TRIV = 19;
const int TRIVIAL = 600000;

u_long *myCalloc(size_t size)
{
    u_long *array = (u_long *) malloc(size * sizeof(u_long));
    if (!array) {
        printf("[error]\n");
        return NULL;
    }
    for (size_t i = 0; i < size; ++i)
        array[i] = 1;
    return array;
}

void myFree(u_long *array)
{
    if (array)
        free(array);
}

void transport(u_long *lhs, const u_long *rhs)
{
    size_t i = 0;
    while (rhs[i] != 0) {
        lhs[i] = rhs[i];
        ++i;
    }
    lhs[i] = 0;
}

u_long *trivialFactor(u_long target)
{
    u_long *result = NULL;
    if (target == 1) {
        result = myCalloc(2);
        result[1] = 0;
        return NULL;
    } else {
        u_long *tmp = myCalloc(MAX_SIZE_TRIV);
        size_t i = 1;
        for (size_t j = 2; j * j <= target; ++j) {
            while (target % j == 0) {
                tmp[i] = j;
                target /= j;
                ++i;
            }
        }
        if (target > 1)
            tmp[i] = target;
        if (tmp[i] != 1)
            ++i;
        tmp[i] = 0;
        result = myCalloc(i + 1);
        transport(result, tmp);
        myFree(tmp);
    }
    return result;
}

u_long *nonTrivialFactor(u_long target)
{
    return NULL;
}

u_long *factor(u_long target)
{
    u_long *result = NULL;
    if (target <= TRIVIAL)
        result = trivialFactor(target);
    else
        result = nonTrivialFactor(target);
    return result;
}

void print(u_long *array)
{
    size_t i = 0;
    while (array[i] != 0)
        printf("%ld ", array[i++]);
    printf("%ld\n", array[i]);
}

int main()
{
    u_long target;
    scanf("%ld", &target);
    u_long *result = factor(target);
    if (result != NULL) {
        print(result);
        printf("%ld %ld\n", target, LONG_MAX);
        myFree(result);
    }
    return 0;
}
