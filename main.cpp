#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];//数组，最多存储MaxSize-1个元素
    int front,rear;//队列头 队列尾
}SqQueue;

/*
 * 【代码实战步骤】依次是：初始化循环队列、判断循环队列是否为空、入队、出队
 * */
//初始化循环队列
void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;//初始化循环队列，就是让队头和队尾都指向零号
}
//判断循环队列是否为空
bool QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front){
        return true;
    }else{
        return false;
    }
}
//入队
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MaxSize==Q.front){//判断循环队列是否满了,满了就不能入队了
        return false;
    }
    Q.data[Q.rear]=x;//放入元素
    Q.rear=(Q.rear+1)%MaxSize;//rear要加1，如果大于数组最大下标，要回到开头
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &m){
    if(Q.rear==Q.front){//判断队列是否为空,队列为空，无法出队
        return false;
    }
    m=Q.data[Q.front];//出队
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
int main() {
    SqQueue Q;
    InitQueue(Q);
    bool ret;
    ret=QueueEmpty(Q);
    if(ret){
        printf("queue is empty\n");
    }else{
        printf("queue is not empty\n");
    }
    EnQueue(Q,3);//入队元素3
    EnQueue(Q,4);//入队元素4
    EnQueue(Q,5);//入队元素5
    ret=EnQueue(Q,6);
    ret=EnQueue(Q,7);//队列中最多存储MaxSize-1个元素，因此7入队失败
    if(ret){
        printf("enQueue success\n");
    }else{
        printf("enQueue failed\n");
    }
    ElemType element;//用于存储出队元素
    ret=DeQueue(Q,element);
    if(ret){
        printf("deQueue element %d\n",element);
        printf("deQueue success\n");
    }else{
        printf("deQueue failed\n");
    }
    ret=EnQueue(Q,8);
    if(ret){
        printf("enQueue success\n");
    }else{
        printf("enQueue failed\n");
    }
    return 0;
}
