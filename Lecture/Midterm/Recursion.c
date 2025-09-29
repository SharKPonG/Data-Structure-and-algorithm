#include <stdio.h>

int a(int n){
    if (n == 1) return 2;
    return a(n - 1) + 3;
}


int main(){
    int n = 5;
    printf("a(%d) = %d\n", n, a(n));
    return 0;
}