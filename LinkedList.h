#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct grades
{
    short math;
    short eng;
    short arabic;
    
}Grades;

/*  
    ****student info****
    ID for regestration
    Name of student
    Birth date in format xxxx-xx-xx
    Address of living
    Phone number
    Grades of his own
    Level of study year
*/
typedef struct node
{
    int ID;
    char Name[30];
    char BirthDate[20];
    char Address[30];
    unsigned int Phone;
    Grades Scores;
    short Level;
    struct node* next;
    struct node* prev;
}Student;

typedef struct linkedlist
{
    Student* head;
    int num_of_students;
}LinkedList;


void CreateList(LinkedList* ptr_List);
void AddNode(LinkedList** ptr_list, int id, char* name, char* birthDate, char* address, unsigned int phone, short level);
void DeleteNode(LinkedList** ptr_list, char* name);
void EditNodeName(LinkedList** ptr_list, int id,char* name);
void EditNodeAdd(LinkedList** ptr_list, int id,char* Add);
void EditNodeBirthDate(LinkedList** ptr_list, int id,char* BDate);
void EditNodePhone(LinkedList** ptr_list, int id,unsigned int Phone);
void EditNodeLevel(LinkedList** ptr_list, int id,short Level);
void ShowNode(LinkedList** ptr_list,char* name,char* Bdate,char* add,int* id,unsigned int* phone, short* level, short* mathgrade,short* arabicgrade,short* englishgrade,short* ok);
short IsEmpty(LinkedList** ptr_list);
void Print_List(LinkedList** ptr_list);
void Delete_List(LinkedList** ptr_list);
void AddListMScores(LinkedList** ptr_list);
void AddListAScores(LinkedList** ptr_list);
void AddListEScores(LinkedList** ptr_list);
void DisplayListEScores(LinkedList** ptr_list);
void DisplayListMScores(LinkedList** ptr_list);
void DisplayListAScores(LinkedList** ptr_list);
void RankMathScore(LinkedList** ptr_list);
void RankEngScore(LinkedList** ptr_list);
void RankArbScore(LinkedList** ptr_list);
void RankAllScore(LinkedList** ptr_list);
void EditEngScore(LinkedList** ptr_list,char* n,short s);
void EditMthScore(LinkedList** ptr_list,char* n,short s);
void EditArbScore(LinkedList** ptr_list,char* n,short s);
void ListAllScore(LinkedList** ptr_list);

#endif