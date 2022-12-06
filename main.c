#include "LinkedList.h"

void AddStudent(LinkedList* ptr_list);
void EditStudent(LinkedList* ptr_list);
void DeleteStudent(LinkedList* ptr_list);
void ListStudent(LinkedList* ptr_list);
void DestroyALL(LinkedList* ptr_list);
void DisplayStudent(LinkedList* ptr_list);
void AddScores(LinkedList* ptr_list);
void DisplayScores(LinkedList* ptr_list);
void RankScores(LinkedList* ptr_list);
void EditStudentScore(LinkedList* ptr_list);
void DisplayAllScores(LinkedList* ptr_list);

int main()
{
    short exitprog=1;
    LinkedList mySchool;
    CreateList(&mySchool);
    printf("*** Welcome to NTI School ***\n**************************\n\n");
    short operation;
    while(exitprog)
    {
        printf("\nPlease select the operation you want to perform from the list!!\n");
        printf("1.  Add new student\n2.  Delete student\n3.  Edit student\n4.  View student data\n5.  List all students\n6.  Add students scores\n7.  Rank students\n8.  Prints Scores\n9.  Delete All data\n10. Edit Student Score\n11. Display All Scores\n12. exit\n");
        printf("Selection Process ID: ");
        fflush(stdin);
        scanf("%hd",&operation);
        switch (operation)
        {
        case 1:
            AddStudent(&mySchool);
            break;
        case 2:
            DeleteStudent(&mySchool);
            break;
        case 3:
            EditStudent(&mySchool);
            break;
        case 4:
            DisplayStudent(&mySchool);
            break;
        case 5:
            ListStudent(&mySchool);
            break;
        case 6:
            AddScores(&mySchool);
            break;
        case 7:
            RankScores(&mySchool);
            break;
        case 8:
            DisplayScores(&mySchool);
            break;  
        case 9:
            DestroyALL(&mySchool);
            break;  
        case 10:
            EditStudentScore(&mySchool);
            break; 
        case 11:
            DisplayAllScores(&mySchool);
            break;           
        case 12:
            exitprog=0;
            printf("\nexit successfully\n");
            break;
        default:
            printf("!!!! WARNING !!! Invalid Operation !!!!\n");
            break;
        }


    }

    return 0;
}

void AddStudent(LinkedList* ptr_list)
{
    printf("\nPlease enter student data\n");
    int ID;
    printf("Regestration ID: ");
    fflush(stdin);
    scanf("%d",&ID);
    char Name[30];
    printf("Name: ");
    fflush(stdin);
    gets(Name);
    char BirthDate[20];
    printf("BirthDate in format xxxx-xx-xx: ");
    fflush(stdin);
    gets(BirthDate);
    char Address[30];
    printf("Address: ");
    fflush(stdin);
    gets(Address);
    unsigned int Phone;
    printf("Phone Num: ");
    fflush(stdin);
    scanf("%u",&Phone);
    short Level;
    printf("Level: ");
    fflush(stdin);
    scanf("%hd",&Level);
    printf("\n");
    AddNode(&ptr_list,ID,Name,BirthDate,Address,Phone,Level);

}

void EditStudent(LinkedList* ptr_list)
{
    int ID;
    short option,stay=1;
    char Name[30], BirthDate[20], Adress[30];
    unsigned int Phone;
    short Level;
    /* check if list contains data */
    if(IsEmpty(&ptr_list))
    {
        printf("\nno data to edit\n");
        return;
    }
    // ID is the key used for the process
    printf("\nEnter Regesteration ID of student: ");
    fflush(stdin);
    scanf("%d",&ID);
    printf("\nSelect option to edit\n");
    printf("1.Name   2.Address   3.BirthDate   4.Phone   5.Level   6.exit");
    // you stay in the loop till you decide to exit
    while(stay)
    {   
        printf("\nneed to change: ");
        fflush(stdin);
        scanf("%hd",&option);
        switch (option)
        {
        case 1:
            printf("\nNew Name: ");
            fflush(stdin);
            gets(Name);
            EditNodeName(&ptr_list,ID,Name);
            break;
        case 2:
            printf("\nNew Address: ");
            fflush(stdin);
            gets(Adress);
            EditNodeAdd(&ptr_list,ID,Adress);
            break;    
        case 3:
            printf("\nNew BirthDate: ");
            fflush(stdin);
            gets(BirthDate);
            EditNodeBirthDate(&ptr_list,ID,BirthDate);
            break;
        case 4:
            printf("\nNew Phone: ");
            fflush(stdin);
            scanf("%u",&Phone);
            EditNodePhone(&ptr_list,ID,Phone);
            break;
        case 5:
            printf("\nNew Level: ");
            fflush(stdin);
            scanf("%hd",&Level);
            EditNodeLevel(&ptr_list,ID,Level);
            break;
        case 6:
            stay=0;
            printf("\nexit successfully\n");
            break;
        default:
            printf("\nwrong option!!\n");
            break;
        }
    }


}

void DeleteStudent(LinkedList* ptr_list)
{
    char name[30];
    printf("\nEnter student name to delete: ");
    fflush(stdin);
    gets(name);
    DeleteNode(&ptr_list, name);

}

void DisplayStudent(LinkedList* ptr_list)
{
    int id=0;
    char name[30], Bdate[20], add[30];
    unsigned int phone=0;
    short oktotest=1,level, mathgrade, arabicgrade, englishgrade;
    printf("\nEnter Name: ");
    fflush(stdin);
    gets(name);
    ShowNode(&ptr_list, name, Bdate, add, &id, &phone, &level,&mathgrade, &arabicgrade, &englishgrade,&oktotest);
    // ok is the flag used to test availability of displaying 
    if(oktotest)
    {
        printf("\nID: %d\tLevel: %hd\tPhone: 0%d\n",id,level,phone);
        printf("Address: %s\nBirth Date: %s\n",add,Bdate);
        printf("student grades:\n");
        if(mathgrade>=0)
            printf("Math: %hd\n",mathgrade);
        else
            printf("Math grade not available yet\n");
        if(arabicgrade>=0)
            printf("Arabic: %hd\n",arabicgrade);
        else
            printf("Arabic grade not available yet\n");
        if(englishgrade>=0)
            printf("Eng: %hd\n",englishgrade);
        else
            printf("Eng grade not available yet\n");        
    }
}

void ListStudent(LinkedList* ptr_list)
{
    Print_List(&ptr_list);
}
void DestroyALL(LinkedList* ptr_list)
{
    Delete_List(&ptr_list);
}

void AddScores(LinkedList* ptr_list)
{
    short g;
    printf("\nSelect the subject you want to fill grades for:\n1. math\n2. arabic\n3. english\n");
            scanf("%hd",&g);
            switch (g)
            {
            case 1:
                AddListMScores(&ptr_list);
                break;
            case 2:
                AddListAScores(&ptr_list);
                break;
            case 3:
                AddListEScores(&ptr_list);
                break;    
            default:
                printf("!!!! WARNING !!! Invalid Subject !!!!\n");
                break;
            }
}

void DisplayScores(LinkedList* ptr_list)
{
    short g;
    printf("\nSelect the subject you want to display grades for:\n1. math\n2. arabic\n3. english\n");
            scanf("%hd",&g);
            switch (g)
            {
            case 1:
                DisplayListMScores(&ptr_list);
                break;
            case 2:
                DisplayListAScores(&ptr_list);
                break;
            case 3:
                DisplayListEScores(&ptr_list);
                break;    
            default:
                printf("!!!! WARNING !!! Invalid Subject !!!!\n");
                break;
            }
}

void RankScores(LinkedList* ptr_list)
{
    short r;
    printf("\nSelect the subject you want to rank students for:\n1. math\n2. arabic\n3. english\n4. All\n");
            scanf("%hd",&r);
            switch (r)
            {
            case 1:
                RankMathScore(&ptr_list);
                break;
            case 2:
                RankArbScore(&ptr_list);
                break;
            case 3:
                RankEngScore(&ptr_list);
                break;  
            case 4:    
                RankAllScore(&ptr_list);  
                break;
            default:
                printf("!!!! WARNING !!! Invalid Subject !!!!\n");
                break;
            }
}

void EditStudentScore(LinkedList* ptr_list)
{
    short r,s;
    char n[30];
    printf("\nSelect the subject you want to Edit students for:\n1. math\n2. arabic\n3. english\n");
    scanf("%hd",&r);
    printf("\nEnter Student Name: ");
    fflush(stdin);
    gets(n);
    printf("\nNew Score is: ");
    scanf("%hd",&s);
    switch (r)
    {
    case 1:
        EditMthScore(&ptr_list,n,s);
        break;
    case 2:
        EditArbScore(&ptr_list,n,s);
        break;
    case 3:
        EditEngScore(&ptr_list,n,s);
        break;    
    default:
        printf("!!!! WARNING !!! Invalid Subject !!!!\n");
        break;
    }
}

void DisplayAllScores(LinkedList* ptr_list)
{
    ListAllScore(&ptr_list);
}