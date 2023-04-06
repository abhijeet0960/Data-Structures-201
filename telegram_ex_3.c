#include <stdio.h>

/*Problem 01 : page numbers

Given 2 arrays of same size, A and B, each array having 'n' postive integers. Each number in array represent page number of a book.

        A[i] is first page number of chapter i
        B[i] is last page number of chapter i

New chapter may start on same page where previous one ended.
(First page of chapter should be <= last page of the chapter)

output 1 if given arrays does follow these rules
       otherwise 0.
*/
int pagenum(int a[], int b[], int n)
{

        int i = 0;
        int flag = 0;
        while (i < (n - 1) && a[0] <= b[0] && a[n - 1] <= b[n - 1] && b[i] == a[i + 1])
        {
                i = i + 1;
        }
        if (i == (n - 1))
        {
                flag = 1;
        }
        return flag;
        /*
        // program by HP sir...
        gives wrong output.
        // Output. Hold value for chapters [0,m)
        // so initially it will be 1
        int k = 1;

        // m indicates how many chapters were verfied till now
        int m = 0;
        // p indicates previous chapters last page.
        // As m is 0 there is no previous chapter
        // therefore valid value as per the rules is a[0]
        int p = a[0];

        while (k * (n - m) != 0)
        {
                if (a[m] <= b[m] || (p != a[m] && (p + 1) != a[m]))
                        k = 0;
                p = b[m];
                m = m + 1;
        }
        return k;
        */
}

/*Problem 02 : common segments in arrays

Given 2 arrays A and B of sizes n and m respectively.Both the arrays have integers in non - decreasing order.all i, j : (0 <= i <= j < n) A[i] <= A[j] all i, j : (0 <= i <= j < m) B[i] <= B[j]
      Output size of longest sgement which is common in both arrays.
      eg        A = a1 a1 a2 a3 a4 a4 a5 a6 a6 a6 a7 a8 | -- -- -- -- - |
                B  = a1 a2 a4 a5 a6 a6 a7 a9 | -- -- -- -- |
output : 4 becuase longest common segment is(a4 a5 a6 a6).
*/

int commseg(int a[], int b[], int n, int m)
{

        int i = 0, j = 0, cnt = 0, max_len = 0;
        while (i < n && j < m)
        {
                if (a[i] == b[j])
                {
                        cnt++;
                        i++;
                        j++;
                }
                else if (a[i] < b[j])
                {
                        i++;
                        cnt = 0;
                }
                else
                {
                        j++;
                        cnt = 0;
                }
                if (cnt > max_len)
                {
                        max_len = cnt;
                }
                while (a[i] == a[i - 1]) // its working but my doubt is what if input is like
                {                        // x = [a,a,a,a...n]
                                         // y = [a,a,a,a...m]

                        i++;
                }
                while (b[j] == b[j - 1])
                {
                        j++;
                }
        }
        return max_len;

        // code by HP Sir...

        // gives wrong output...
        
        // cnt is length of longest common segment
        // in a[0,l1) and b[0,l2)
        // 0 <= l1 <= n     0 <= l2 <= m
        // int cnt = 0;
        // int l1 = 0, l2 = 0;

        // m elements a[l1-m, l1) and b[l2-m, l2) are same
        // int max = 0;

        // while ((n - l1) * (m - l2) != 0)
        // {
        //         if (a[l1] == b[l2])
        //         {
        //                 max = max + 1;
        //         }
        //         else
        //         {
        //                 max = 0;
        //         }

        //         if (max > cnt)
        //         {
        //                 cnt = max;
        //         }

        //         if (a[l1] <= b[l2])
        //         {
        //                 l1 = l1 + 1;
        //         }

        //         if (a[l1] >= b[l2])
        //         {
        //                 l2 = l2 + 1;
        //         }
        // }

        // return cnt;
}

/*Problem 03: max occurrence

Given an array A of size n. It contains integers
in non decreasing order.
all i,j: 0 <= i <= j < n, A[i] <= A[j]

output : number which occurs most number of times.

 eg input : [a1, a1, a1, a3, a3, a3, a3, a2]
    output: a3

*/

int countfreq(int a[], int n)
{
        int max = 0, count = 0, i = 0, s = a[0], max1;
        while (i < n)
        {
                if (s == a[i])
                        count = count + 1;
                if (max < count)
                {
                        max = count;
                        max1 = a[i];
                }
                if (s != a[i])
                {
                        count = 0;
                }
                s = a[i];
                i = i + 1;
        }
        return max1;
}

int main()
{
        int tc;
        scanf("%d", &tc);
        while (tc != 0)
        {
                int n, m, i = 0;
                printf("Enter Size of A - ");
                scanf("%d", &n);
                int a[n];
                printf("Enter Size of B - ");
                scanf("%d", &m);
                int b[m];
                while (i != n)
                {
                        printf("\nEnter %d Element into First Array - ", i);
                        scanf("%d", &a[i]);
                        i = i + 1;
                }
                i = 0;
                while (i != m)
                {
                        printf("\nEnter %d Element into Second Array - ", i);
                        scanf("%d", &b[i]);
                        i = i + 1;
                }
                // int result = pagenum(a, b, n);
                int result = commseg(a, b, n, m);
                // int result = countfreq(a, n);
                printf("\n%d\n", result);
                tc = tc - 1;
        }
}
