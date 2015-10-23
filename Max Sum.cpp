/*
Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.
 

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6
 */
 /*
  动态规划（Dp）思想：另取一个数组,来存储该子序列已知和，利用已知的和求最大子序列和
 */
 
 #include<iostream>
using namespace std;
int arr[1000001],dp[1000001];//数组存储较大，设置为全局变量，存储在全局数据区，局部变量存储在栈中，可自动释放，但是栈空间有限
int main() {
    int start,endd ,maxx;//标注当前子序列的起始坐标和结束坐标
    int first,second;//标注最大字符列的开始坐标和结束坐标
    int line_numbers,counts;//序列数目 和序列中元素数目
    int line=1;//第几个序列
    cin>>line_numbers;
    while(line_numbers--) {
        cin>>counts;
        for(int i=0;i!=counts;i++)
            cin>>arr[i];
         start = 0,endd = 0,maxx = -1001;
         first = 0,second = 0;
        for(int i=0;i!=counts;i++) {
            if(dp[i-1]>0) {
                dp[i] = dp[i-1]+arr[i];
                endd = i;
            }
            else {
                dp[i] = arr[i];
                start = endd = i;
            }
            if(maxx<=dp[i]) {
                maxx = dp[i];
                first = start;
                second = endd;
            }
        }
        cout<<"Case "<<line++<<":"<<endl<<maxx<<" "<<first+1<<" "<<second+1<<endl;
        if(line_numbers!=0)
            cout<<endl;
    }
}


/*归纳法，假设可以找到规模小于n的最大子序列S={x1,x2,...}
    以及作为后缀的最大子序列S’,将Xn加入到S’中，与S进行比较，
    其中最大的就是最大子序列
*/
//最大子序列求和问题
#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& inp_sub,int &start ,int & end);

int main ()
{
    int i;
    int start_position,end_position;
    int sum,N;
    int numbers;
    int line,which_line;
    which_line = 1;
    cin>>line;
    while(line--){
        cin>>N;
        vector<int> number(N);
        for(i=0;i<N;i++){
            cin>>number[i];
        }
        cout<<"Case "<<which_line<<":\n";
        sum = maxSubArray( number,start_position,end_position);
        cout<<sum<<" "<<start_position+1<<" "<<end_position+1<<endl;
        if(line!=0)
            cout<<"\n";
        ++which_line;
    }
}

/*
  下标设置原理：start和end用来标记最大子序列的开始下标和结束下标
  first和second随着最大后缀子序列的增加而变化
  当suffix_max < 0 的时候，意味着开始新的子序列，则丢弃以前的下标，
  对first,second重新标记
*/
int maxSubArray(vector<int>& inp_sub,int &start ,int & end) {
        int global_max=-1000;//规模小于n的最大子序列和，max设置为-1000，保证在序列为都负数的情况下，可以求出最大子序列
        int suffix_max=0;//作为后缀的最大子序列和
        int i;
        int first =0,second=0; 
        for( i= 0;i != inp_sub.size();++i)//此处size()大小为vector中已经初始化的元素的个数
        {
            if(suffix_max == 0)
                first = second = i;
            suffix_max = suffix_max+inp_sub[i];
            second = i;
            if(suffix_max > global_max)
            {
                start = first;
                end = second;
                global_max = suffix_max;

            }
            if(suffix_max<0)
            {
                    suffix_max = 0;
            }
        }
        return global_max;
    }
