#include <stdlib.h>
#include <dstring.h>
#include "stdio.h"

int main() {
    printf("\n Welcome to the jungle - [lab 1] Programing Real Time\n");
    printf("\nCreated 2 strings...\n");
    dstring str1 = new_string("first");
    dstring str2 = new_string("second");

    string_print(str1);
    string_print(str2);

    printf("\n---------------------\n");
    printf("----------------------\n");
    printf("\ncopy string...\n");
    printf("\n---------------------\n");

    str1 = string_copy(str2);
    printf("\nString copied:\n");
    string_print(str1);

    string_free(str1);
    string_free(str2);

    printf("\n---------------------\n");
    printf("----------------------\n");
    printf("\nfree init variable in memory.....\n");
    printf("\n---------------------\n");
    printf("\nStart news variables....\n");
    printf("\n---------------------\n");
    printf("---------------------\n");

    dstring str3 = new_string("hiii");
    dstring str4 = new_string("world");

    printf("\nConstructing new strings [hiii] and [world]\n");
    string_print(str3);
    string_print(str4);

    printf("\nconcating....\n");

    dstring str5 = string_concat(str3, str4);
    string_print(str5);

    printf("\nString concat success!:\n");

    printf("\nChecking size string concated...\n");

    printf("Size string : %d  check!\n", string_lenght(str5));

    printf("\nTesting using macro\n");
    printf("%s\n", $(str5));
}
