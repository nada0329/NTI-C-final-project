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