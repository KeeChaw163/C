#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct node)
#define MAX 147
 
struct node
{
    char cc;
    struct node *next;
};
 
int judge(struct node *head,int len)
{
	struct node *top, *p1, *p2;
    top = NULL;
    p1 = head->next;
    for(int i = 0; i < len / 2; i++)
    {
        p2 = (struct node *)malloc(LEN);
        p2->cc = p1->cc;
        p2->next = top;
        top = p2;
        p1 = p1->next;
    }
    if(len%2 == 1)
		p1 = p1->next;
    p2 = top;
	for(int i = 0; i < len / 2; i++)
	{
		if(p2->cc != p1->cc)
			break;
		top = p2->next;
        p1 = p1->next;
        p2 = top;
	}
    if(!top) 
		return 1;
    else 
		return 0;
}
 
int main()
{
    int n = 0;
    char str[MAX];
    struct node *head, *p;
    head = p = (struct node *)malloc(LEN);
    head->next = p->next = NULL;
	printf("请输入一个字符串：\n");
	gets(str);
	int len = strlen(str);
    while(n < len && str[0] != '\n')
    {
        p = (struct node *)malloc(LEN);
        p->cc = str[n];
        p->next = head->next;
        head->next = p;
        n++;
    }
	int flag = judge(head,len);
    if(flag)
        printf("%s和回文一样对称!\n",str);
    else
        printf("%s不对称！\n",str);
	return 0;
}