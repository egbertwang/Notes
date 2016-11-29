#include<iostream>
#include<string>
using namespace std;
struct Student
{
	string name;
	string score;
	Student *next;//定义了指向Candidate类型变量的指针
};
Student * Create(Student * head)
{
	Student *p=NULL;
	Student *node=NULL;
	int n;//
	cout<<"请输入学生的总数：";
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		node=new Student;
		cout<<"请输入第"<<i<<"个同学的姓名:";
		cin>>node->name;
		cout<<"请输入第"<<i<<"个同学的成绩:";
		cin>>node->score;
		if(head==NULL)
			head=node;
		else
			p->next=node;
		p=node;
		if(i==n)
		{
			p->next=NULL;
		}
	}
	return head;
}
void Print(Student * head)
{
	Student *p=NULL;
	p=head;
	cout<<"链表已经建立!"<<endl;
	cout<<"\n==========下面输入刚才的数据=============\n"<<endl;
	int i=1;
	while(p!=NULL)
	{
		cout<<"第"<<i<<"个同学==="<<p->name<<"==成绩===="<<p->score<<endl;
		p=p->next;
		i++;
	}
	cout<<"\n"<<endl;
}
void Insert(Student * head,int k)
{
	Student *p=NULL;
	Student *node=NULL;
	p=head;
	if(k==1)
	{
		node=new Student;
		cout<<"第1位同学的名字：";
		cin>>node->name;
		cout<<"第1位同学的成绩：";
		cin>>node->score;
		node->next=head->next;
		head=node;
	}
	int i=1;
	while(p!=NULL)
	{
		if(i+1==k)
		{
			node=new Student;
			cout<<"第"<<k<<"位同学的名字：";
			cin>>node->name;
			cout<<"第"<<k<<"位同学的成绩：";
			cin>>node->score;
			node->next=p->next;
			p->next=node;
		}
		p=p->next;
		i++;
	}
}

void Destory(Student * head)
{
	Student *d;
	Student *p=NULL;
	p=head;
	while(p!=NULL)
	{
		d=p;
		p=p->next;
		delete d;
	}
}
void Alter(Student * head,int k)
{
	int i=1;
	Student *p=head;
	while(p!=NULL)
	{
		if(i==k)
		{
			cout<<"第"<<k<<"位同学的名字：";
			cin>>p->name;
			cout<<"第"<<k<<"位同学的成绩：";
			cin>>p->score;
		}
		p=p->next;
		i++;
	}
}
Student * Delete(Student * head,int k)
{
	int i=1;
	Student *p=head;
	Student *d=head;
	if(k==1)
	{
		head=head->next;
	}
	else
	{
		while(p!=NULL)
		{
			if(i+1==k)
			{
				p->next=p->next->next;
			}
			p=p->next;
			i++;
		}
	}
	return head;
}
int main()
{
	Student *head=NULL;
//创建链表
	head=Create(head);
//输出链表
	Print(head);
//插入数据
	int k;
	cout<<"请输入你要插入的同学的序号：";
	cin>>k;
	Insert(head,k);
//输出链表
	Print(head);
//修改链表
	cout<<"请输入你要修改的同学的序号:";
	cin>>k;
	Alter(head,k);
//输出链表
	Print(head);
//删除其中的一个项
	cout<<"请输入你要删除的同学的序号:";
	cin>>k;
	head=Delete(head,k);
//输出链表
	Print(head);
//销毁链表
	Destory(head);
	return 0;
}
