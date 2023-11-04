#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int main()
{
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  printf("Enter array elements: ");
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("\nOriginal array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  qsort(arr, n, sizeof(int), compare);
  printf("\nSorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
