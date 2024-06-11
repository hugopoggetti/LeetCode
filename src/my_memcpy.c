#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_memcpy(void *restrict dest, const void *restrict src, size_t n) 
{
    char *dest_char = NULL;
    const char *src_char = NULL;

    if (dest == NULL || src == NULL)
        return NULL;
    dest_char = (char *)dest;
    src_char = (const char *)src;
    for (size_t i = 0; i < n; i++)
        dest_char[i] = src_char[i];
    return dest;
}

int main(void)
{
    int *dest = malloc(sizeof(int) * 4);
    int src[] = {1,2,3,4};

    my_memcpy(dest, src, 4 * sizeof(int));

    for (int i = 0; i < 4; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");
}