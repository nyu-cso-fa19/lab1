#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <getopt.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#include "panic_cond.h"
#include "part8.h"

void
generate_a_test_string(char *buf, int buf_sz, int fields, char delim, bool hard)
{
	char *buf_start = buf;
	int startn = random() % 1000;
	for (int i = 0; i < fields; i++) {
		buf += sprintf(buf, "%d", startn);
		startn++;
		if (i != (fields -1)) {
			buf += sprintf(buf, "%c", delim);
		}
		if (hard) {
			while (1) {
			       	buf += sprintf(buf, "%c", delim);
				if (random() % 3 == 0) {
					break;
				}
			}
		}
	}
       	assert(buf < buf_start + buf_sz);
	return;
}

void
test_a_string(char *original, char delim)
{
	char *token1, *token2, *saveptr1, *saveptr2;
	char delimstring[10];
	sprintf(delimstring, "%c", delim);
	
	char string1[1000];
	assert(strlen(original) < 1000);
	strcpy(string1, original);
	char string2[1000];
	assert(strlen(original) < 1000);
	strcpy(string2, original);

	char *str1 = string1;
	char *str2 = string2;

	while (1) {	
		token1 = string_token(str1, delim, &saveptr1);
		token2 = strtok_r(str2, delimstring, &saveptr2);
	
		if (!token1) {
			panic_cond(!token2, "test string \"%s\", delim (%c), next token should be %s instead of NULL\n", 
				original, delim, token2);
		} else if (!token2) {
			panic_cond(!token1, "test string \"%s\", delim (%c), next token should be NULL instead of %s\n", 
				original, delim, token1);
		} else {
		       	panic_cond(strcmp(token1, token2)==0, "test string \"%s\", delim (%c), next token should be %s instead of %s\n", 
				original, delim, token2, token1);
		}

		str1 = NULL;
		str2 = NULL;

		if (!token1 && !token2) {
			break;
		}
	}

}

int
main(int argc, char **argv)
{
	char delims[5] = {';', ',', ' ', '$', '/'};
	for (int i = 0; i < 10; i++) {
		char teststring[10000];
		char delim = delims[random()%5];
		generate_a_test_string(teststring, 10000, 1+random()%10, delim, false);
		printf("part8: testing with an easy string \"%s\" delim (%c)\n", teststring, delim);
		test_a_string(teststring, delim);
	}
	printf("part8: easy_string_split OK\n");
	for (int i = 0; i < 10; i++) {
		char teststring[10000];
		char delim = delims[random()%5];
		generate_a_test_string(teststring, 10000, 1+random()%10, delim, true);
		printf("part8: testing with a harder string \"%s\" delim (%c)\n", teststring, delim);
		test_a_string(teststring, delim);
	}
	printf("part8: harder_string_split OK\n");

}
