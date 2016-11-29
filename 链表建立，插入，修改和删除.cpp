#include<iostream>
#include<string>
using namespace std;
struct Student
{
	string name;
	string score;
	Student *next;//������ָ��Candidate���ͱ�����ָ��
};
Student * Create(Student * head)
{
	Student *p=NULL;
	Student *node=NULL;
	int n;//
	cout<<"������ѧ����������";
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		node=new Student;
		cout<<"�������"<<i<<"��ͬѧ������:";
		cin>>node->name;
		cout<<"�������"<<i<<"��ͬѧ�ĳɼ�:";
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
	cout<<"�����Ѿ�����!"<<endl;
	cout<<"\n==========��������ղŵ�����=============\n"<<endl;
	int i=1;
	while(p!=NULL)
	{
		cout<<"��"<<i<<"��ͬѧ==="<<p->name<<"==�ɼ�===="<<p->score<<endl;
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
		cout<<"��1λͬѧ�����֣�";
		cin>>node->name;
		cout<<"��1λͬѧ�ĳɼ���";
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
			cout<<"��"<<k<<"λͬѧ�����֣�";
			cin>>node->name;
			cout<<"��"<<k<<"λͬѧ�ĳɼ���";
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
			cout<<"��"<<k<<"λͬѧ�����֣�";
			cin>>p->name;
			cout<<"��"<<k<<"λͬѧ�ĳɼ���";
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
//��������
	head=Create(head);
//�������
	Print(head);
//��������
	int k;
	cout<<"��������Ҫ�����ͬѧ����ţ�";
	cin>>k;
	Insert(head,k);
//�������
	Print(head);
//�޸�����
	cout<<"��������Ҫ�޸ĵ�ͬѧ�����:";
	cin>>k;
	Alter(head,k);
//�������
	Print(head);
//ɾ�����е�һ����
	cout<<"��������Ҫɾ����ͬѧ�����:";
	cin>>k;
	head=Delete(head,k);
//�������
	Print(head);
//��������
	Destory(head);
	return 0;
}
