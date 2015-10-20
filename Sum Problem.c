/*Sum Problem

Time Limit: 1000/500 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 366626    Accepted Submission(s): 91927

Problem Description
Hey, welcome to HDOJ(Hangzhou Dianzi University Online Judge).

In this problem, your task is to calculate SUM(n) = 1 + 2 + 3 + ... + n.
 
Input
The input will consist of a series of integers n, one integer per line.
 
Output
For each case, output SUM(n) in one line, followed by a blank line. You may assume the result will be in the range of 32-bit signed integer.
 
Sample Input
1
100
 
Sample Output
1

5050
*/
//公式法
#include <stdio.h>
int main ()
{
  int n;
  while(scanf("%d",&n)!=EOF)
      printf("%d\n\n",n%2==0?n/2*(n+1):(n+1)/2*n);// 如果使用n*(n+1)/2，不能通过,n*(n+1)可能会超出int表示的范围，这个语句相对小点
  return 0;
}

//循环方法
#include <stdio.h>
int main ()
{
  int n;
  int sum;
  while(scanf("%d",&n)!=EOF)
  {
    sum = 0;
    for(;n>0;--n)
    sum+=n;
    printf("%d\n\n",sum);
  }
  return 0;
}

//递归方法
#include <stdio.h>
int main ()
{
  int n;
  int sum;
  while(scanf("%d",&n)!=EOF)
  {
    sum = 0;
    sum = sum_n(n);
    printf("%d\n\n",sum);
  }
}
int sum_n (int n)
{
    int result=0;
    if(n>0)
    {
        result = n+sum_n(n-1);
    }
    return result;
}
