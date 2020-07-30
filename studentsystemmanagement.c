#include "studentsystemmanagement.h"
int main() 
{
	
	start=NULL;
	int roll,c,p1,p2,p3;
	float per;
	int n;
	char ch='y',na[20];
	do
	{
		printf("------------------- Student Management System ----------------");
		printf("\n1> Admission of new student \n2> Display List \n3> Search \n4> Update List \n5> Cancel admission \n6> Sort the List\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the roll number:");
				scanf("%d",&roll);
				printf("Enter you name:");
				scanf("%s",na);
				printf("Enter the marks of your 3 subjects:");
				scanf("%d%d%d",&p1,&p2,&p3);
				per=(p1+p2+p3)/3.0;
				
				create(roll,p1,p2,p3,per,na);
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter the roll number of the student:");
				scanf("%d",&n);
				search(n);
				break;
			case 4:
				printf("Enter the roll of the student to update the record:");
				scanf("%d",&n);
				update(n);
				break;
			case 5:
				printf("Enter the roll of the student to cancel his/her admission:");
				scanf("%d",&n);
				cancel(n);
				break;
			case 6:
				sortt();
		}
		printf("\n\nDo you want to continue?[y/n]:");
		scanf("%s",&ch);
		system("CLS");
	}while(ch=='y'||ch=='Y');
	return 0;
}
