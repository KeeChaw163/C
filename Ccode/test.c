#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
 
#define MAXLEN 10
#define Status int
#define datatype int 
#define OK 1
#define Y 1
#define N 0
 
typedef struct{
        datatype s[MAXLEN];
        int front;
        int count;
}SeqQueue;
 
//初始化
Status InitSeqQueue(SeqQueue &sq) 
{ 
        sq.front=-1;    //队首指针指向第一个元素的前一个位置
        sq.count=0;     //count置为0
        return OK;
}
//队满
Status IsFull(SeqQueue &sq)
{
        if(sq.count==MAXLEN) return Y;  //若队满，返回1
        else return N;                  //否则返回0
}
//队空
Status IsEmpty(SeqQueue &sq)
{
        if(sq.count==0) return Y;               //若队空，返回0
        else return N;
}
//入队
Status InQueue(SeqQueue &sq,datatype x)
{
        if(IsFull(sq)) return 0;        //队满
        srand(time(NULL));
        int a=rand()%10;
 
        sq.s[sq.count]=x;
        sq.count++;
        return OK;
}
//出队
Status OutQueue(SeqQueue &sq,datatype &x)
{
        if(IsEmpty(sq)) return 0;       //队空
 
        sq.front++;
        x=sq.s[sq.front];
        sq.count--;                     //队列元素减少1个
        return 1;
}
//显示队列元素
Status ShowQueue(SeqQueue sq)
{
        if(IsEmpty(sq)) return 0;       //若队空，返回0
        while(sq.count!=0)
        {
                cout<<sq.s[sq.front+1]<<" ";
                sq.front++;
                sq.count--;
        }
        cout<<endl;
 
}
 
//读取队首元素
Status ReadQueue(SeqQueue sq,datatype &x)
{
        if(IsEmpty(sq)) return 0;       //若队空，返回0
        x=sq.s[sq.front+1];
        return 1;
}
 
int main()
{
        SeqQueue SQ;
        InitSeqQueue(SQ);
 
        cout<<"入栈"<<endl;
        InQueue(SQ,1);
        InQueue(SQ,2);
        InQueue(SQ,3);
        InQueue(SQ,4);
        InQueue(SQ,5);
 
        cout<<"显示队列元素:"<<endl;
        ShowQueue(SQ);
 
        cout<<"出队:"<<endl;
        datatype temp;
        OutQueue(SQ,temp);
        cout<<"显示队列元素:"<<endl;
        ShowQueue(SQ);
 
        cout<<"显示队首元素:"<<endl;
        ReadQueue(SQ,temp);
        cout<<temp<<endl;
 
        return OK;
}
 