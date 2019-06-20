#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int test_ex1()
{
    char source[] = "ABCDEF, liangmingliang, wanghui";
    char chars[] = "XXXXXXXXXXXXw"; 
    printf("source: %s\n", source);
    printf("chars: %s\n", chars);

    char *match = NULL;
    match = find_char(source, chars);
    printf("find_char: %s\n", match);

    return 0;
}

int test_ex2()
{
    /* 
    char* str = "ACDEFG"; // this is const string and  the content pointed by 'str' cannot be changed
    char* substr = "CDE"; // this is const string and  the content pointed by 'substr' cannot be changed
    */

    char str[] = "ACDEFG";
    char substr[] = "CDE";

    printf("str: %s\n", str );
    printf("substr: %s\n", substr);

    if ( RET_ERR == del_substr(str, substr) ){
        printf("failed to delete substr from str\n");
        return -1;
    }

    printf(" delete a substr from str succeed !\n");
    printf("after delete a sub-str: %s\n", str );


    return 0;
}

int test_ex3()
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
	printf("the origin string is: %s\n", str);
	if ( 0 != reverse_string(str) ) {
	    printf("reverse the string failed\n");
		return -1;
	}
	printf("after reverse, the string is: %s\n", str);

    return 0;
}

int main(int argc, char * argv[])
{
    /* test exercise 1*/
	printf("\n\nstart to test exercise 1:\n");
    if ( 0 != test_ex1()) {
        printf("error, test exercise 1 failed\n");
        return -1;
    }

	printf("\n\nstart to test exercise 2:\n");

    if ( 0 != test_ex2()) {
        printf("error, test exercise 2 failed\n");
        return -1;
    }

	printf("\n\nstart to test exercise 3:\n");
    if ( 0 != test_ex3() ) {
		printf("error, test exercise 3 failed\n");
		return -1;
	}

    return 0;
}

