#include <stdio.h>
 
int missing(int ar[], int ar_size)
{
     // Doing XOR of all elements and returning the unique delivery ID
     int res = ar[0];
     for (int i=1; i < ar_size; i++)
        res = res ^ ar[i];
 
     return res;
}
 
	// Main Function
int main()
{
	 int d_id;
     int  delivery_id_confirmations[] = {221,314,450,314,221,222,222};
     int n = sizeof( delivery_id_confirmations)/sizeof( delivery_id_confirmations[0]);
	 d_id = missing(delivery_id_confirmations, n);
     printf("The delivery_id of the missing drone is %d",d_id);
     return 0;
}
