/*A + B Problem

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 513130    Accepted Submission(s): 162753

Problem Description
Calculate A + B.
 
Input
Each line will contain two integers A and B. Process to end of file.
 
Output
For each case, output A + B in one line.
 
Sample Input
1 1

Sample Output
2*/
#include <stdio.h> 
int main()
{
int a,b;
while(scanf("%d%d",&a,&b)!=EOF) //EOF文件结束符
printf("%d\n",a+b);
}
