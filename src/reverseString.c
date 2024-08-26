
void swap(char *a, char *b)
{
    char temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

void reverseString(char* s, int sSize)
{
    for (size_t i = 0; i < sSize / 2; i++)
        swap(&s[i], &s[(sSize - 1) - i]);
}
