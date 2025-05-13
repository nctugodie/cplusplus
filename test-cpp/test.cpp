#include <stdio.h>

int main()
{
    char a[] = "hello";

    int array[] = {5, 6, 7, 8, 9, 10};
    int* p = array;
    *(p++) += 123;
    *(++p) += 123;

    printf("sizeof(a) = %lu\n", sizeof(a));

    for (int i = 0; i < sizeof(array)/sizeof(int); ++i) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}
