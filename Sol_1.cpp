#include<stdio.h>
#include<conio.h>
#define MAX_SIZE 1000 // Maximum array size


bool hasArrayTwoCandidates(int A[], int arr_size, int sum)
{
    int l, r;
  
    // Looking for possbile candidates in the array
    l = 0;
    r = arr_size-1; 
    while (l < r)
    {
         if(A[l] + A[r] == sum)
              return 1; 
         else if(A[l] + A[r] < sum)
              l++;
         else
              r--;
    }    
    return 0;
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* creating temporay arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[left to right]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}


int main()
{
	int travel_length,n,i;
	int m_list[MAX_SIZE];
	printf("Enter the number of movies to be searched\n");
	scanf("%d",&n);
	printf("Enter length of %d  movies in minutes\n",n);
	for(i=0;i<n;i++)
		{
			scanf("%d",&m_list[i]);
		}
	printf("\nElements in array are: \n");
    for(i=0; i<n; i++)
    {
        printf("%d \t",m_list[i]);
    }
   	mergeSort(m_list, 0, n-1);     //performing mergesort
   /*	printf("\nThe sorted array is\n");
   	for(i=0;i<n;i++)
   	{
        printf("%d \t",m_list[i]);
    }*/
    printf("\nEnter travel_length\n");
    scanf("%d",&travel_length);
if(hasArrayTwoCandidates(m_list,n,travel_length))
			{
        printf("The list has two movies with total exactly of %d minutes",travel_length);
       		 }
    else
    		{
        printf("The list does not contain two mvoies with total of exact %d minutes",travel_length);
 			}
 
    getchar(); 
    return 0;
}
