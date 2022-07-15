#include <stdlib.h>
#include "dstring.h"
#include "stdio.h"

struct dstring {
    int size;
    char *string;
};

dstring new_string(char *string) {
    if (string == NULL) {
        return NULL;
    }

    //Constructor
    dstring newString = malloc(sizeof(dstring));

    newString->size = cstring_lenght(string);

    newString->string = malloc(sizeof(char) * newString->size);

    for (int i = 0; i < newString->size; i++) {
        
        newString->string[i] = string[i];

    }

    return newString;
}

dstring string_copy(dstring str) {
    dstring copy = new_string(str->string);

    return copy;
}

dstring string_concat(dstring str1, dstring str2) {
    int size = str1->size + str2->size;

    dstring newString = string_copy(str1);

    newString->string = realloc(newString->string, sizeof(char) * size);
    newString->size =size;

    for (int i = str1->size; i < size; i++) {
        newString->string[i] = str2->string[i - (str1->size)];
    }

    return newString;
}

char *string_buffer(dstring string) {
    char *buffer = malloc(sizeof(char) * string->size);
    for (int i = 0; i < string->size; i++) {
        buffer[i] = string->string[i];
    }

    return buffer;
}

void string_print(dstring string) {
    for (int i = 0; i < string->size; i++) {
        printf("%c", string->string[i]);
    }

    printf("\n");
}

void string_free(dstring string) {
    free(string);

}

int string_lenght(dstring string) {
    return string->size;
}

int cstring_lenght(char *string) {
    int size;
    for (size = 0; string[size] != '\0'; size++);
    return size;

}