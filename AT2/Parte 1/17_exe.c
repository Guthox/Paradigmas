#include <stdio.h>

int main(){
    int a = 6, b = 5;
    a = b++;
    printf("a=%d b=%d\n", a, b);
    if ( a = b)
    printf("a=%d b=%d\n", a, b);
    b += a + 1;
    printf("a=%d b=%d\n", a, b);
    printf ("%d", a - b);

    return 0;
}
