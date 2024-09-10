/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);

 * double param_2 = medianFinderFindMedian(obj);

 * medianFinderFree(obj);
*/


typedef struct {
    int *arr;
    size_t size;
    double result;
} MedianFinder;


MedianFinder* medianFinderCreate()
{
    MedianFinder *new = malloc(sizeof(MedianFinder));
    new->arr = NULL;
    new->result = 0;
    new->size = 0;
    return new;
}

void medianFinderAddNum(MedianFinder* obj, int num)
{
    obj->size++;
    obj->arr = realloc(obj->arr, sizeof(int) * obj->size);
    obj->arr[obj->size - 1] = num;
    obj->result += num;
}

double medianFinderFindMedian(MedianFinder* obj)
{
    if ((obj->size % 2) == 0) {
        return obj->result / obj->size;
    } else {
        float index = (obj->size / 2) + 0.5;
        return (double)obj->arr[(int)index];
    }
    return 0;
}

void medianFinderFree(MedianFinder* obj)
{
    free(obj->arr);
    free(obj);
}

int main(void)
{
    return 0;
}
