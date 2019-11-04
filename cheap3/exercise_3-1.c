/**************************************************
* File Name: exercise_3-1.c
* Author: panghu
* Mail: panghuvpn@gamil.com
* Created Time: 2019-09-07/18:07:56
**************************************************/

#include <stdio.h>

int binsearch(int x, int v[], int n);
int main()
{
        
    int x = 5;
    int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
    int n = 9;
    printf("search index is: %d\n", binsearch(x, v, n));
    return 0; 
}



int binsearch(int x, int v[], int n)
{
    int low,high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid -1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;


}
