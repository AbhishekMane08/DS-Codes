//////////////////////////////////////////////////////////////////////////////
//																			//
//	Author 			: Abhishek Shailesh Mane								//
//	Date			: February 24,2017.										//
//	Project Name	: Employee Data Management Application					//
//	Language		: C language.											//
//	Lines Of Codes	: 390													//
//	Menu driven		: Yes													//
//																			//
//////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>

static int i=0;
static int Id=0; 
static int Total= 0;

struct Employee
{
	
	struct Employee *Prev;
	int EmpId ;
	char EName[30];
	char Gender[30];
	int MobileNumber;
    char ProjectName[30];
	struct Employee *Next;

};

typedef struct Employee NODE;
typedef struct Employee *PNODE;
typedef struct Employee **PPNODE;

void Insert2(PPNODE Head,PPNODE Tail,PNODE Newn)
{
  Newn  -> Prev= NULL;
  Newn  -> Next= NULL;
  if((*Head == NULL) && (*Tail== NULL))
	{
		*Head=Newn;
		*Tail=Newn;
	}
	else
	{
		Newn->Next = *Head;
		(*Head)->Prev=Newn;
		*Head = Newn;
	}
}

void Insert(PPNODE Head,PPNODE Tail)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	Id=Id+1;
	newn->EmpId=Id;
			
	printf("Enter Employee Name ");
	scanf(" %[^'\n']s",newn->EName);
			
	printf("Enter Employee Gender ");
	scanf(" %[^'\n']s",newn->Gender);

	printf("Enter Employee Project ");
	scanf(" %[^'\n']s",newn->ProjectName);
			
	printf("Enter Employee Mobile Number ");
	scanf("%d",&(newn -> MobileNumber));	
		
	newn->Next = NULL;
	newn->Prev = NULL;
	
	if((*Head == NULL) && (*Tail== NULL))
	{
		*Head=newn;
		*Tail=newn;
	}
	else
	{
		(*Tail)->Next=newn;
		newn->Prev=*Tail;
		*Tail=(*Tail)->Next; 
	}
	i++;
	Total++;
}

int Count()
{
  return i;
}

void Display(PNODE Head)
{
	printf("Employee Details\n\n");
	PNODE temp=Head;
	
	while(temp != NULL)
	{

		printf(" ID      - %d\n",temp->EmpId);
		printf(" Name    - %s\n",temp->EName);
		printf(" Gender  - %s\n",temp->Gender);
		printf(" Number  - %d\n",temp->MobileNumber);
		printf(" Project - %s\n\n",temp->ProjectName);

		temp = temp->Next;
	}
	
}


void DisplayLeft(PNODE Head)
{
	printf("Employee who left the company are\n\n");
	PNODE temp=Head;
	
	while(temp != NULL)
	{

		printf(" ID      - %d\n",temp->EmpId);
		printf(" Name    - %s\n",temp->EName);
		printf(" Gender  - %s\n",temp->Gender);
		printf(" Number  - %d\n",temp->MobileNumber);
		printf(" Project - %s\n\n",temp->ProjectName);

		temp = temp->Next;
	}
	
}

void DisplayX(PNODE Head, PNODE Tail)
{
  int ID=0;
  printf("Enter the Employee-Id Of the employee ");
  scanf("%d",&ID);
  
  
  PNODE temp=Head;
  
  if((Head == NULL) && (Tail == NULL))
  {
    printf("Invalid Entry");
    return;
  }

  while(temp!=NULL)
  {
  
    if(temp->EmpId== ID)
    {
      	printf("\nID      - %d\n",temp->EmpId);
        printf("Name    - %s\n",temp->EName);
        printf("Gender  - %s\n",temp->Gender);
        printf("Number  - %d\n",temp->MobileNumber);
        printf("Project - %s\n\n",temp->ProjectName);
		break;
		break;
    }
    if(temp->Next == NULL) 
    {
      printf("No employess of this ID exist\n");
    }
    temp=temp->Next;
  }
}




void Update(PPNODE Head,PPNODE Tail)
{
  if(*Head == NULL && *Tail == NULL)
  {
    printf("No employee data to Update\n");
    return;
  }

  int ID=0,choice=1;
  printf("Enter the Employee-Id Of the employee ");
  scanf("%d",&ID);

  if(ID <1 || ID > Total)
  {
    printf("Invaid ID\n");
    return;
  }

  PNODE temp=*Head;

  while(temp->Next != NULL )
  {
    if(temp->EmpId == ID)
    {
      break;
    }
    temp=temp->Next;
  }

  if(temp->Next == NULL && temp->EmpId != ID)
  {
    printf("Invalid Entry \n");
    return;
  }
  
  while(choice != 0)
  {
    printf("1. Update Employee Name \n");
    printf("2. Update Employee Gender \n");
    printf("3. Update Employee Project \n");
    printf("4. Update Employee Phone Number \n");
    printf("0. Exit \n");

    printf("\nEnter your choice \n");
		scanf("%d",&choice);

    switch(choice)
    {
        case 1:
      	printf("Enter Employee Name ");
        scanf(" %[^'\n']s",temp->EName);
        break;	

        case 2:     
        printf("Enter Employee Gender ");
        scanf(" %[^'\n']s",temp->Gender);
        break;	

        case 3:
        printf("Enter Employee Project ");
        scanf(" %[^'\n']s",temp->ProjectName);
        break;	

        case 4:    
        printf("Enter Employee Mobile Number ");
        scanf("%d",&(temp -> MobileNumber));
        break;	

        case 0:
        break;
    }

  }
  
}


void Delete(PPNODE Head, PPNODE Tail,PPNODE Head2,PPNODE Tail2)
{

  if(*Head == NULL && *Tail == NULL)
  {
    printf("No employee data to delete\n");
    return;
  }

  int ID=0;
  printf("Enter the Employee-Id Of the employee ");
  scanf("%d",&ID);
  
  if(ID <1 || ID > Total)
  {
    printf("Invaid ID\n");
    return;
  }

  PNODE temp=*Head;

  while(temp->Next != NULL )
  {
    if(temp->EmpId == ID)
    {
      break;
    }
    temp=temp->Next;
  }
  
  
  if((temp->Prev== NULL) &&( temp->Next == NULL) && (temp->EmpId==ID))//only 1 node 
  {
      *Head = NULL;
      *Tail = NULL;
      Insert2(Head2,Tail2,temp);
      printf("\nDone\n");
      i--;
  }

  else if((temp->Prev == NULL) && (temp ->Next != NULL) && (temp->EmpId==ID))//1sst node
  {
    *Head=(*Head)->Next;
    (*Head)->Prev= NULL;
    Insert2(Head2,Tail2,temp);
    printf("\nDone\n");
    i--;
  }

  else if(temp->Prev != NULL && temp ->Next == NULL && temp->EmpId==ID)//
  {
    *Tail=temp->Prev;
    (*Tail)->Next=NULL;
    Insert2(Head2,Tail2,temp);
    printf("\nDone\n");
    i--;
  }

  else if(temp->Prev != NULL && temp ->Next != NULL && temp->EmpId==ID)
  {
    temp->Prev->Next=temp->Next;
    temp->Next->Prev=temp->Prev;
    Insert2(Head2,Tail2,temp);
    printf("\nDone\n");
    i--;
  }
  else
  {
    printf("\nMultiple Remove Request\n");
  }
}

int main()
{
	PNODE First=NULL;
	PNODE Last = NULL;
	
	PNODE LeftHead = NULL;
	PNODE LeftTail = NULL;
	
	int choice =1;
	int iRet = 0;
		
	while(choice != 0)
	{
		printf("\n------Employee------\n");
		printf("1. Add New Employee\n");
		printf("2. Remove Existing Employee\n");
		printf("3. Count number of Employees \n");
		printf("4. Display All Employees\n");
		printf("5. Search an Employee's Detail\n");
		printf("6. Update Employee Details \n");
		printf("7. Display ex-Employees\n");
		printf("0. Exit\n");
		
		printf("\nEnter your choice \n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			Insert(&First, &Last);
			break;
			
			case 2:
			Delete(&First, &Last, &LeftHead, &LeftTail);
			break;
      
			case 3:
			iRet = Count();
			printf("\nNumber of employess in company are %d\n",iRet);
			break;
			
			case 4:
			Display(First);
			break;

			case 5:
			DisplayX(First,Last);
			break;

			case 6:
			Update(&First,&Last);
			break;
			
			case 7:
			DisplayLeft(LeftHead);
			break;  

			case 0:
			break;
		
			default:
			printf("Wrong Input : Enter Again\n");
		}
	}
	return 0;
}
