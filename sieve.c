#include <stdio.h>

#define MAX 10000

void printPrimes(int notprimes[])
{
   int i;

   for (i = 2; i < MAX; i++)
   {
      if (!notprimes[i])
         printf("%2d ", i);
   }

   printf("\n");
   getchar();
   return;
}

int main(void)
{  
   int notprimes[MAX+1] = {0};
   int i, j;

   for (i = 2; i < MAX; i++)
   {
      for (j = 2; j <= i; j++)
      {
         if (!notprimes[j])
         {
            if (i*j >= MAX)
               break;

            printf("i=%d,j=%d\n", i, j);
            notprimes[j*i] = 1;
            printPrimes(notprimes);
         }

         if (i % j == 0)
            break;
      }
   }

   return 0;
}
