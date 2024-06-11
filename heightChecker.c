int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int heightChecker(int* heights, int heightsSize) 
{
    int no_match = 0;
    int *expected = malloc(heightsSize * sizeof(int));
    memcpy(expected, heights, heightsSize * sizeof(int));
    qsort(expected, heightsSize, sizeof(int), compare);

    for (int i = 0; i < heightsSize; i++) {
        if (heights[i] != expected[i]) {
            no_match++;
        }
    }
    free(expected);
    return no_match;
}
