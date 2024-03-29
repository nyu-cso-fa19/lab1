#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* In part8.c, you will implement a function, called string_token, that 
 * splits a string into a sequence of tokens according to 
 * a specific delimiter character.
 *
 * On the first call, the string to be parsed is given the "str" argument. The "saveptr"
 * argument is ignored.  The function returns a char pointer in the location pointed 
 * to by "saveptr". The returned char pointer will be used internally by string_token() 
 * in subsequent calls that parse the same string in order to maintain context.
 *
 * On a subsequent call to parse the same string, the caller is expected to pass NULL 
 * as the "str" argument, and pass the previously returned saveptr value 
 * (from the first call) as the "saveptr" argument. 
 *
 * Each call to string_token returns a pointer to a null-terminated string containing the next token.
 * This string does not include the delimiting byte.  More concretely, the next token is determined 
 * by scanning forward (from either "str" or savedptr" depending on whether it's the first or 
 * subsequent string_token call) for the next non-delimiter character. If no such character is found, 
 * the function returns NULL.
 *
 * Here's an example usage of the function string_token:
 *
 * char str[100] = "aaa;;bbb;ccc" 
 * char *savedptr; 
 *
 * while (1) { 
 *    token = string_token(str, ';', &savedptr); 
 *    if (token == NULL) {
 *       break; 
 *    }
 *    printf("%s\n"); 
 *    str = NULL; // set str to be NULL for subsequent string_token call 
 * }
 *
 * The above code snippet should print out 3 lines:
 * aaa 
 * bbb
 * ccc
 *
 *
 * Note: The string_token function is supposed to modify the buffer holding the
 * argument "str" (by replacing delimeters with null characters) It should not 
 * perform any memory allocation (e.g. using malloc).
 *
 *
 * Note: This function is similar but not identical to the standard C library's
 * strtok_r(...) function. 
 */


char *
string_token(char *str, char delim, char **saveptr)
{
	//TODO: Your code here
}

