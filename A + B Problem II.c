/*
Problem Description
I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.
 
Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.
 
Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases.
 
Sample Input
2
1 2
112233445566778899 998877665544332211
 
Sample Output
Case 1:
1 + 2 = 3

Case 2:
112233445566778899 + 998877665544332211 = 1111111111111111110

*/

//利用数组实现
#include <stdio.h>
#include <string.h>
void add(char *num1 ,char *num2,char *num3);
int main ()
{
    //将大数存储为字符串数组
    char num1[1000];
    char num2[1000];
    char num3[1001]={'\0'};
    int rows;
    int which_row=1;
    scanf("%d",&rows);
    while(rows){
        scanf("%s %s",num1,num2);
        printf("Case %d:\n",which_row);
        add(num1,num2,num3);
        printf("%s + %s = %s",num1,num2,num3);
        ++which_row;
        if(rows!=1)
            printf("\n\n");
        else
            printf("\n");
        --rows;
    }
}
void add(char *num1 ,char *num2,char *num3)
{
    int i = strlen(num1)-1;//下标
    int j = strlen(num2)-1;
    int k =0;
    int flag = 0;//
    //将两个字符串从低位开始相加,从低位到高位放在另一个字符串数组中
    while(i>=0&&j>=0)
    {
        num3[k] = num1[i]+num2[j]-'0'+flag;
        flag = 0;
        if(num3[k] > '9')//进位情况
        {
            flag = 1;
            num3[k]-=10;
        }
        --i,--j,++k;
    }

    //将较大的数剩下的高位连接在这个字符串中
    while(i>=0)
    {
        num3[k]=num1[i]+flag;
        flag = 0;
         if(num3[k] > '9')//进位情况
        {
            flag = 1;
            num3[k]-=10;
        }
        --i,++k;
    }
    while(j>=0)
    {
        num3[k]=num2[j]+flag;
        flag = 0;
         if(num3[k] > '9')//进位情况
        {
            flag = 1;
            num3[k]-=10;
        }
        --j,++k;
    }
    //检测最高位的进位
    if(flag == 1)
    {
        num3[k] = flag+'0';
        ++k;
    }
    //之所以逆置，这样进位比较容易一点
    //反转
    char temp;
    for(i=0,j=k-1;i<j;++i,--j)
    {
         temp = num3[i];
        num3[i] = num3[j];
        num3[j] = temp;
    }
}



//利用string类实现

#include <iostream>
#include <string>
using namespace std;
string add(string s1 ,string s2);
int main ()
{
    //将大数存储为String类
    string s1,s2,s3;
    int rows;
    int which_row=1;
    cin>>rows;
    while(rows){
        cin>>s1>>s2;
        cout<<"Case "<<which_row<<":\n";
        s3 = add(s1,s2);
        cout<<s1<<" + "<<s2<<" = "<<s3;
        ++which_row;
        if(rows!=1)
            cout<<"\n\n";
        else
            cout<<"\n";
        --rows;
    }
}
string add(string s1 ,string s2)
{
    string s3;
    int i = s1.length()-1;//下标
    int j = s2.length()-1;
    int k =0;
    int flag = 0;//
    //将两个字符串从低位开始相加,从低位到高位放在另一个字符串数组中
    while(i>=0&&j>=0)
    {
        s3 += s1[i]+s2[j]-'0'+flag;
        flag = 0;
        if(s3[k] > '9')//进位情况
        {
            flag = 1;
            s3[k]-=10;
        }
        --i,--j,++k;
    }

    //将较大的数剩下的高位连接在这个字符串中
    while(i>=0)
    {
        s3 +=s1[i]+flag;
        flag = 0;
         if(s3[k] > '9')//进位情况
        {
            flag = 1;
            s3[k]-=10;
        }
        --i,++k;
    }
    while(j>=0)
    {
        s3 += s2[j]+flag;
        flag = 0;
         if(s3[k] > '9')//进位情况
        {
            flag = 1;
            s3[k]-=10;
        }
        --j,++k;
    }
    //检测最高位的进位
    if(flag == 1)
    {
        s3[k] += (flag+'0');
        ++k;
    }
    //之所以逆置，这样进位比较容易一点
    //反转
    char temp;
    for(i=0,j=k-1;i<j;++i,--j)
    {
         temp = s3[i];
        s3[i] = s3[j];
        s3[j] = temp;
    }
    return s3;
}
