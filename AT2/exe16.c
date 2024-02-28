#include <stdio.h>

int main(){
    int a=1, b=2, c=3, d=4;
    b += a + c;
    printf("a=%d b=%d c=%d d=%d\n", a, b, c, d);
    
    a=1; b=2; c=3; d=4;
    b *= d = c + 20;
    printf("a=%d b=%d c=%d d=%d\n", a, b, c, d);
     
    a=1; b=2; c=3; d=4;
    a += b += c += 5;
    printf("a=%d b=%d c=%d d=%d\n", a, b, c, d); 
     
    a=1; b=2; c=3; d=4;
    printf("%d", a == b);
    return 0;
}
