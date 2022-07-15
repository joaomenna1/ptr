#include <stdlib.h>
#include "dstring.h"
#include "stdio.h"

int main() {
    dstring str1 = new_string("first");
    dstring str2 = new_string("second");

    string_print(str1);
    string_print(str2);

    str1 = string_copy(str2);
    printf("\nString copied:\n");
    string_print(str1);

    string_free(str1);
    string_free(str2);

    dstring str3 = new_string("hiii");
    dstring str4 = new_string("world");

    dstring str5 = string_concat(str3, str4);
    printf("\nString concat success!:\n");

    printf("Size string : %d \n", string_lenght(str5));

    printf("\nTest macro\n");
    printf("%s\n", $(str5));
}
