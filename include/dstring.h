#ifndef DSTRING_H
#define DSTRING_H

#define $(s) string_buffer(s)

struct dstring;
typedef struct dstring *dstring;

/* Returns a new string from str */
dstring new_string(char *str);
/* Retorn one copy str */
dstring string_copy(dstring str);
/* Returns a new string resulting from the concatenation of str1 and str2 */
dstring string_concat(dstring str1, dstring str2);
/* destructive method */
void string_free(dstring str);
/* Returns the number of characters in str*/
int string_lenght(dstring str);
/* Returns a string in char* format
Can be used by macro $(str) */
char *string_buffer(dstring str);
/* Print a string in the terminal*/
void string_print(dstring str);
/* Returns the length of a string in char* format */
int cstring_lenght(char *str);

#endif