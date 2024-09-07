#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) {
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int find_next_start(char str[], int len, int i) {
	while (i < len && !isalpha(str[i])) i++;
	return (i < len) ? i : -1;
}

int find_next_end(char str[], int len, int i) {
    while (i < len && isalpha(str[i])) i++;
    return i;
}

void reverse_words(char s[]) {
    int len = strlen(s);
    int start = 0;
    while (start < len) {
        start = find_next_start(s, len, start);
        if (start == -1) break;
        int end = find_next_end(s, len, start) - 1;
        reverse_substring(s, start, end);
        start = end + 1;
    }
}
