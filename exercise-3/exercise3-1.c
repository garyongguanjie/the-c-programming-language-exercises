#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main(){
    int v[] = {2,5,7,12,16,19};

    int i1 = binsearch(19,v,6);
    printf("i1: %d\n",i1);
    int i2 = binsearch2(19,v,6);
    printf("i2: %d\n",i2);
    int i3 = binsearch2(7,v,6);
    printf("i3: %d\n",i3);
    int i4 = binsearch2(2,v,6);
    printf("i4: %d\n",i4);
    int i5 = binsearch2(13,v,6);
    printf("i5: %d\n",i5);
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid -1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

// Write a version with only one test inside the loop and measure the difference in run-time
// bisect asks the question where do we insert the value?
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (v[mid]<x)
            low = mid+1;
        else
            high = mid;
    }
    return v[low]==x?low:-1; /* no match */
}