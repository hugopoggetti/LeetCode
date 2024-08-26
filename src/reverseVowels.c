#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

char* reverseVowels(char* s)
{
    int j = strlen(s) - 1;
    int i = 0;
    while (i < j) {
        while(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U'&& i < j) i++;
        while(s[j]!='a'&&s[j]!='e'&&s[j]!='i'&&s[j]!='o'&&s[j]!='u'&&s[j]!='A'&&s[j]!='E'&&s[j]!='I'&&s[j]!='O'&&s[j]!='U'&& j > i) j--;
            swap(&s[i++], &s[j--]); 
    }
    return s;
}

int main(void)
{
    char *s = "hello";
    printf("s = %s\n", reverseVowels(s));
    return 0;
}