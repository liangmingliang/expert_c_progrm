#include <stdio.h>
#include <stdlib.h>

void func(int num)
{
    if ( num > 0 ) {
        func(--num);
    } else {
        printf(" num has reached zero\n");
    }
}

int main(int argc, char * argv[])
{
    func(1);

    return 0;
}

