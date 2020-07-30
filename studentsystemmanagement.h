#include <stdio.h>
#include <stdlib.h>
int i=0,j=0;
int r1,r2,r3,r;
char nn[20];
struct Node
{
	char name[20];
	int roll;
	int m1,m2,m3;
	float per;
	struct node *addr;
}*temp,*start,*curr,*max;
void create(int roll,int m1,int m2,int m3,double per,char n[20])
{
	temp=malloc(sizeof(struct Node));
	for(i=0;n[i]!='\0';i++)
	{
		temp->name[i]=n[i];
	}
	for(;i<15;i++)
	{
		temp->name[i]=' ';
	}
	temp->name[i]='\0';
	temp->roll=roll;
	temp->m1=m1;
	temp->m2=m2;
	temp->m3=m3;
	temp->per=per;
	temp->addr=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		curr=start;
		while(roll ==curr->roll)
		{
			printf("You have entered invalid roll number!! Please enter your roll number:");
			scanf("%d",&roll);
		}
		while(curr->addr!=NULL)
		{
			curr=curr->addr;
			while(roll == curr->roll)
			{
				printf("You have entered invalid roll number!! Please enter your roll number:");
				scanf("%d",&roll);
			}
		}
		temp->roll=roll;
		curr->addr=temp;
		sort();
	}	
}
void display()
{
	if(start==NULL)
	{
		printf("The addmission record is not updated!!");
	}
	else
	{
		curr=start;
		printf("\nRoll \tName \t\tSubject 1 \tSubject 2 \tSubject 3 \tPercentage\n");
		while(curr!=NULL)
		{
			printf("%d \t%s         %d \t\t%d \t\t%d \t\t%.2f\n",curr->roll,curr->name,curr->m1,curr->m2,curr->m3,curr->per);
			curr=curr->addr;			
		}
	}
}

void sort()
{
	int p,k;
	curr=start;
	while(curr!=NULL)
	{
		if(curr->per < temp->per)
		{
			if(curr==start)
			{
				if(temp->addr==NULL)
				{
			    	temp->addr=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}
					curr->addr=NULL;
				}
				else
				{
					max=temp->addr;
					temp->addr=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}
					curr->addr=max;
				}
				start=temp;
			}
			else
			{
				max->addr=temp;
				k=temp->addr;
				temp->addr=curr;
				while(curr->addr!=temp)
				{
					curr=curr->addr;
				}
				curr->addr=k;
			}
			p=1;
			break;
		}
		max=curr;
		curr=curr->addr;
    }
	if(p!=1)
	{
		max->addr=temp;
		temp->addr=NULL;
	}
}
void search(int n)
{
	int p=0;
	curr=start;
	while(curr!=NULL)
	{
		if(curr->roll == n)
		{
			printf("\nRoll \tName \t\tSubject 1 \tSubject 2 \tSubject 3 \tPercentage\n");
			printf("%d \t%s         %d \t\t%d \t\t%d \t\t%.2f\n",curr->roll,curr->name,curr->m1,curr->m2,curr->m3,curr->per);
			p=1;
		}
		curr=curr->addr;
	}
	if(p!=1)
	{
		printf("No record of this Roll number!!");
	}
}
void update(int n)
{
	int p=0,ch;
	curr=start;
	while(curr!=NULL)
	{
		if(curr->roll == n)
		{
			if(curr==start)
			{
				max=curr;
				max=max->addr;
				start=start->addr;
			}
			else
			{
				max->addr=curr->addr;
			}
			while(max->addr!=NULL)
			{
				max=max->addr;
			}
			max->addr=curr;
			curr->addr=NULL;
			printf("1> Name \n2> Marks of Subject 1 \n3> Marks of Subject 2 \n4> Marks of Subject 3 \nWhat to you want to update ?:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("Enter the updated name:");
					scanf("%s",nn);
					for(i=0;nn[i]!='\0';i++)
					{
						curr->name[i]=nn[i];
					}
					curr->name[i]='\0';
					break;
				case 2:
					printf("Enter the updated marks of Subject 1:");
					scanf("%d",&r1);
					curr->m1=r1;
					curr->per=(curr->m1 + curr->m2 +curr->m3)/3.0;
					break;
				case 3:
					printf("Enter the updated marks of Subject 2:");
					scanf("%d",&r2);
					curr->m2=r2;
					curr->per=(curr->m1 + curr->m2 +curr->m3)/3.0;
					break;
				case 4:
					printf("Enter the updated marks of Subject 3:");
					scanf("%d",&r3);
					curr->m3=r3;
					curr->per=(curr->m1 + curr->m2 +curr->m3)/3.0;
					break;
			}
			temp=curr;
			sort();
			p=1;
			break;
		}
		max=curr;
		curr=curr->addr;
	}
	if(p!=1)
	{
		printf("No record of this Roll number!!");
	}
}
void cancel(int n)
{
	int p=0;
	char ch;
	curr=start;
	while(curr!=NULL)
	{
		if(curr->roll == n)
		{
			printf("Do you want to cancel admission of roll no. %d Name: %s  ?[y/n]:",curr->roll,curr->name);
			scanf("%s",&ch);
			if(ch=='y'||ch=='Y')
			{
				if(curr==start)
				{
					start=curr->addr;
					curr->addr=NULL;
					free(curr);
				}
				else
				{
					max->addr=curr->addr;
					free(curr);
				}
			}
			p=1;
		}
		max=curr;
		curr=curr->addr;
	}
	if(p!=1)
	{
		printf("No record of this Roll number!!");
	}
}
void sortt()
{
	int c;
	printf("Sort by:\n1> Roll \n2> Subject 1 \n3> Subject 2 \n4> Subject 3\nEnter your choice:");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			rsort();
			break;
		case 2:
			ssort();
			break;
		case 3:
			s1sort();
			break;
		case 4:
			s2sort();
			break;
	}
}
void rsort()
{
	int m;
	struct Node *ptr;
	curr=start;
	ptr=start;
	max=NULL;
	temp=curr->addr;
	while(curr!=NULL)
	{
		temp=curr->addr;
		while(temp!=NULL)
		{
			ptr=start;
			max=temp->addr;
			if(temp->roll < curr->roll)
			{
				if(curr==start)
				{	
					m=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}
					curr->addr=temp->addr;
					curr=m;
					temp->addr=curr;
					start=temp;
					curr=start;
				}
				else
				{
					m=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}      
					curr->addr=temp->addr;
					curr=m;
					while(ptr->roll < temp->roll)
					{
						j=ptr;
						ptr=ptr->addr;
					}
					temp->addr=ptr;
					ptr=j;
					ptr->addr=temp;
					ptr=temp;
				}
			}
			temp=max;
		}
		curr=curr->addr;
	}
}
void ssort()
{
	int m;
	struct Node *ptr;
	curr=start;
	ptr=start;
	max=NULL;
	temp=curr->addr;
	while(curr!=NULL)
	{
		temp=curr->addr;
		while(temp!=NULL)
		{
			ptr=start;
			max=temp->addr;
			if(temp->m1 > curr->m1)
			{
				if(curr==start)
				{	
					m=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}
					curr->addr=temp->addr;
					curr=m;
					temp->addr=curr;
					start=temp;
					curr=start;
				}
				else
				{
					m=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}      
					curr->addr=temp->addr;
					curr=m;
					while(ptr->m1 >temp->m1)
					{
						j=ptr;
						ptr=ptr->addr;
					}
					temp->addr=ptr;
					ptr=j;
					ptr->addr=temp;
					ptr=temp;
				}
			}
			temp=max;
		}
		curr=curr->addr;
	}
}
void s1sort()
{
	int m;
	struct Node *ptr;
	curr=start;
	ptr=start;
	max=NULL;
	temp=curr->addr;
	while(curr!=NULL)
	{
		temp=curr->addr;
		while(temp!=NULL)
		{
			ptr=start;
			max=temp->addr;
			if(temp->m2 > curr->m2)
			{
				if(curr==start)
				{	
					m=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}
					curr->addr=temp->addr;
					curr=m;
					temp->addr=curr;
					start=temp;
					curr=start;
				}
				else
				{
					m=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}      
					curr->addr=temp->addr;
					curr=m;
					while(ptr->m2 >temp->m2)
					{
						j=ptr;
						ptr=ptr->addr;
					}
					temp->addr=ptr;
					ptr=j;
					ptr->addr=temp;
					ptr=temp;
				}
			}
			temp=max;
		}
		curr=curr->addr;
	}
}
void s2sort()
{
	int m;
	struct Node *ptr;
	curr=start;
	ptr=start;
	max=NULL;
	temp=curr->addr;
	while(curr!=NULL)
	{
		temp=curr->addr;
		while(temp!=NULL)
		{
			ptr=start;
			max=temp->addr;
			if(temp->m3 > curr->m3)
			{
				if(curr==start)
				{	
					m=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}
					curr->addr=temp->addr;
					curr=m;
					temp->addr=curr;
					start=temp;
					curr=start;
				}
				else
				{
					m=curr;
					while(curr->addr!=temp)
					{
						curr=curr->addr;
					}      
					curr->addr=temp->addr;
					curr=m;
					while(ptr->m3 >temp->m3)
					{
						j=ptr;
						ptr=ptr->addr;
					}
					temp->addr=ptr;
					ptr=j;
					ptr->addr=temp;
					ptr=temp;
				}
			}
			temp=max;
		}
		curr=curr->addr;
	}
}
