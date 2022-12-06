#include "LinkedList.h"

void CreateList(LinkedList* ptr_List)
{
    ptr_List->head=NULL;
    ptr_List->num_of_students=0;
}

void AddNode(LinkedList** ptr_list, int id, char* name, char* birthDate, char* address, unsigned int phone, short level)
{
    /* creat node and assign its data */
    Student* MyNode= (Student*)malloc(sizeof(Student));
    MyNode->ID=id;
    MyNode->Level=level;
    MyNode->Phone=phone;
    strcpy(MyNode->Name,name);
    strcpy(MyNode->Address,address);
    strcpy(MyNode->BirthDate,birthDate);
    MyNode->Scores.arabic=-1;
    MyNode->Scores.eng=-1;
    MyNode->Scores.math=-1;
    MyNode->next=NULL;
    MyNode->prev=NULL;
    (*ptr_list)->num_of_students++;
    /*  list ia empty   */
    if((*ptr_list)->head==NULL)
    {
        (*ptr_list)->head=MyNode;
        
    }
    else
    {
        /*  check to add at beginning   */
        // ex: myNode = mona , head = nada  -> get -1 from strcmp
        if(stricmp(MyNode->Name,(*ptr_list)->head->Name)<0)
        {
            MyNode->next=(*ptr_list)->head;
            (*ptr_list)->head->prev=MyNode;
            (*ptr_list)->head=MyNode;
            
        }
        else
        {
            short flag_last_add=1;
            /*  check to add at middle before specific item  */
            Student* temp=(*ptr_list)->head;
            while(temp != NULL)
            {
                /* traverse till you get a name gives you -ve from stricmp*/
                // ex: myNode=mona and list contains: ali,ahmed,hassan,nada.... here temp points to nada at the end of loop
                if(stricmp(MyNode->Name,temp->Name)>0)
                {
                    temp=temp->next;
                
                }
                // here you add myNode before the temp you stopped at in previous step
                else if(stricmp(MyNode->Name,temp->Name)<=0)
                {
                    MyNode->prev=temp->prev;
                    MyNode->next=temp;
                    temp->prev->next=MyNode;
                    temp->prev=MyNode;
                    // this flag to confirm the insertion is done
                    flag_last_add=0;
                    break;
                }
            }
            /*  check to add as last item   */
            // this flag is used when you end your list without finding a node to insert before it
            // ex: My node=zizi while list contains: ali,mona...,nada
            if(flag_last_add==1)
            {
                temp=(*ptr_list)->head;
                while(temp->next != NULL)
                {
                    temp=temp->next;
                }
                MyNode->prev=temp;
                temp->next=MyNode;
            } 
        }
    }
}

short IsEmpty(LinkedList** ptr_list)
{
    if((*ptr_list)->head==NULL)
    {
        return 1;
    }
    return 0;
}

void EditNodeName(LinkedList** ptr_list, int id,char* name)
{
    Student* temp=(*ptr_list)->head;
    //traverse till find req ID
    while (temp!=NULL)
    {
        if(id==temp->ID )
        {
            break;
        }
        temp=temp->next;
    }
    // list traverse ended but id not found
    if(temp==NULL)
    {
        printf("\n cant edit !! ID not exist\n");
        return;
    }
    // here edit done
    else
    {
        strcpy(temp->Name,name);
    }

}
void EditNodeAdd(LinkedList** ptr_list, int id,char* Add)
{
    Student* temp=(*ptr_list)->head;
    //traverse till find req ID
    while (temp!=NULL)
    {
        if(id==temp->ID )
        {
            break;
        }
        temp=temp->next;
    }
    // list traverse ended but id not found
    if(temp==NULL)
    {
        printf("\n cant edit !! ID not exist\n");
        return;
    }
    // here edit done
    else
    {
        strcpy(temp->Address,Add);
    }

}
void EditNodeBirthDate(LinkedList** ptr_list, int id,char* BDate)
{
    Student* temp=(*ptr_list)->head;
    //traverse till find req ID
    while (temp!=NULL)
    {
        if(id==temp->ID )
        {
            break;
        }
        temp=temp->next;
    }
    // list traverse ended but id not found
    if(temp==NULL)
    {
        printf("\n cant edit !! ID not exist\n");
        return;
    }
    // here edit done
    else
    {
        strcpy(temp->BirthDate,BDate);
    }

}
void EditNodePhone(LinkedList** ptr_list, int id,unsigned int Phone)
{
    Student* temp=(*ptr_list)->head;
    //traverse till find req ID
    while (temp!=NULL)
    {
        if(id==temp->ID )
        {
            break;
        }
        temp=temp->next;
    }
    // list traverse ended but id not found
    if(temp==NULL)
    {
        printf("\n cant edit !! ID not exist\n");
        return;
    }
    // here edit done
    else
    {
        temp->Phone=Phone;
    }

}
void EditNodeLevel(LinkedList** ptr_list, int id,short Level)
{
    Student* temp=(*ptr_list)->head;
    //traverse till find req ID
    while (temp!=NULL)
    {
        if(id==temp->ID )
        {
            break;
        }
        temp=temp->next;
    }
    // list traverse ended but id not found
    if(temp==NULL)
    {
        printf("\n cant edit !! ID not exist\n");
        return;
    }
    // here edit done
    else
    {
        temp->Level=Level;
    }

}
void DeleteNode(LinkedList** ptr_list, char* name)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no data to delete\n");
        return;
    }
    //traverse till find req name
    while (temp!=NULL)
    {
        if(stricmp(temp->Name,name)==0 )
        {
            break;
        }
        
        temp=temp->next;
    }
    /*  here item not found till end of list    */
    if(temp==NULL)
    {
        printf("\n cant delete !! not exist\n");
        return;
    }
    (*ptr_list)->num_of_students--;
    /* delete first item  */
    if(temp==(*ptr_list)->head)
    {
        (*ptr_list)->head=temp->next;
        /* make sure not only item exist */
        if(temp->next!=NULL)
            (*ptr_list)->head->prev=NULL;
        free(temp);
    }
    /* delete last item */
    else if(temp->next==NULL)
    {
        temp->prev->next=NULL;
        free(temp);
    }
    /* delete item in middle */
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
    printf("\n Delete Done\n");
    
}

void ShowNode(LinkedList** ptr_list,char* name,char* Bdate,char* add,int* id,unsigned int* phone, short* level, short* mathgrade,short* arabicgrade,short* englishgrade,short* ok)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no data to display\n");
        *ok=0;
        return;
    }
    //traverse till find req name
    while (temp!=NULL)
    {
        if(stricmp(temp->Name,name)==0 )
        {
            break;
        }
        
        temp=temp->next;
    }
    /*  here item not found till end of list    */
    if(temp==NULL)
    {
        printf("\n cant display !! not exist\n");
        // clear OK flag to stop display in main file
        *ok=0;
        return;
    }
    // sent the data of student
    strcpy(Bdate,temp->BirthDate);
    strcpy(add,temp->Address);
    *level=temp->Level;
    *phone=temp->Phone;
    *id=temp->ID;
    *mathgrade=temp->Scores.math;
    *arabicgrade=temp->Scores.arabic;
    *englishgrade=temp->Scores.eng;
    
}

void Print_List(LinkedList** ptr_list)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no data to show\n");
        return;
    }
    printf("\nID      Name                           Level  Phone        Birth Date     Address\n");
    while(temp!= NULL)
    {
        printf("%-7d %-30s %-6hd 0%-11d %-14s %s\n",temp->ID,temp->Name,temp->Level,temp->Phone,temp->BirthDate,temp->Address);
        /*printf("\nID: %d\tName: %s\tLevel: %hd\tPhone: %d\n",temp->ID,temp->Name,temp->Level,temp->Phone);
        printf("Address: %s\nBirth Date: %s\n",temp->Address,temp->BirthDate);*/
        temp=temp->next;
    }
}

void Delete_List(LinkedList** ptr_list)
{ 
    if((*ptr_list)->head==NULL)
    {
        printf("\nEmpty!! no list to delete\n");
        return;
    }
    // traverse till exit the list
    while((*ptr_list)->head!= NULL)
    {
        /* if one node remaining */
        if((*ptr_list)->head->next==NULL)
        {
            free((*ptr_list)->head);
            (*ptr_list)->head=NULL;
            break;
        }
        (*ptr_list)->head=(*ptr_list)->head->next;
        free((*ptr_list)->head->prev);
    }
    (*ptr_list)->num_of_students=0;
    printf("\nDeletion Done\n");
}

void AddListMScores(LinkedList** ptr_list)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no data records to add for\n");
        return;
    }
    // add all students scores one by one
    while (temp!=NULL)
    {
        printf("\n Name: %-30s Score: ",temp->Name);
        fflush(stdin);
        scanf("%hd",&(temp->Scores.math));
        temp=temp->next;
    }
}

void AddListAScores(LinkedList** ptr_list)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no data records to add for\n");
        return;
    }
    // add all students scores one by one
    while (temp!=NULL)
    {
        printf("\n Name: %-30s Score: ",temp->Name);
        fflush(stdin);
        scanf("%hd",&(temp->Scores.arabic));
        temp=temp->next;
    }
}

void AddListEScores(LinkedList** ptr_list)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no data records to add for\n");
        return;
    }
    // add all students scores one by one
    while (temp!=NULL)
    {
        printf("\n Name: %-30s Score: ",temp->Name);
        fflush(stdin);
        scanf("%hd",&(temp->Scores.eng));
        temp=temp->next;
    }

}

void DisplayListEScores(LinkedList** ptr_list)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no data to records to display\n");
        return;
    }
    // traverse through the list
    while (temp!=NULL)
    {
        // if marks added or still not
        if(temp->Scores.eng>=0)
            printf("\n Name: %-30s Score: %hd",temp->Name,temp->Scores.eng);
        else
            printf("\n Name: %-30s Score: not available",temp->Name);    
        
        temp=temp->next;
    }
}

void DisplayListAScores(LinkedList** ptr_list)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no data to records to display\n");
        return;
    }
    // traverse through the list
    while (temp!=NULL)
    {
        // if marks added or still not
        if(temp->Scores.arabic>=0)
            printf("\n Name: %-30s Score: %hd",temp->Name,temp->Scores.arabic);
        else
            printf("\n Name: %-30s Score: not available",temp->Name);    
        
        temp=temp->next;
    }
}

void DisplayListMScores(LinkedList** ptr_list)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no data to records to display\n");
        return;
    }
    // traverse through the list
    while (temp!=NULL)
    {
        // if marks added or still not
        if(temp->Scores.math>=0)
            printf("\n Name: %-30s Score: %hd",temp->Name,temp->Scores.math);
        else
            printf("\n Name: %-30s Score: not available",temp->Name);    
        
        temp=temp->next;
    }
}

void RankMathScore(LinkedList** ptr_list)
{
    // create arrays in heap to hold names and marks
    short* rank_math=(short*)malloc(((*ptr_list)->num_of_students)*sizeof(int));
    char** n=(char**)malloc(((*ptr_list)->num_of_students)*sizeof(char**));
    short temp_rank;
    char temp_name[30];
    int count=0;
    // create each string in the array of strings of names
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
        n[i] = (char*)malloc(30 * sizeof *n[i]);
    Student* temp=(*ptr_list)->head;
    // fill the 2arrays with names and marks
    while(temp!=NULL)
    {
        rank_math[count]=temp->Scores.math;
        strcpy(n[count],temp->Name); 
        count++;
        temp=temp->next;
    }
    // apply bubble sort on the arrays
    for (int step = 0; step < ((*ptr_list)->num_of_students) - 1; ++step) 
    {
        int swapped = 0;
        for (int i = 0; i < ((*ptr_list)->num_of_students) - step - 1; ++i) 
        {
            if (rank_math[i] > rank_math[i + 1]) 
            {  
                temp_rank = rank_math[i];
                rank_math[i] = rank_math[i + 1];
                rank_math[i + 1] = temp_rank; 
                strcpy(temp_name,n[i]);
                strcpy(n[i],n[i+1]);
                strcpy(n[i+1],temp_name); 
                swapped = 1;
            }
        }
        if (swapped == 0) 
        {
          break;
        }
    }
    // print ranked lists
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
    {
        printf("\nName: %-30s  Score: %hd",n[i],rank_math[i]);
    }
    // free used memory in heap
    free(rank_math);
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
        free(n[i]);
    
}

void RankEngScore(LinkedList** ptr_list)
{
    // create arrays in heap to hold names and marks
    short* rank_Eng=(short*)malloc(((*ptr_list)->num_of_students)*sizeof(int));
    char** n=(char**)malloc(((*ptr_list)->num_of_students)*sizeof(char**));
    short temp_rank;
    char temp_name[30];
    int count=0;
    // create each string in the array of strings of names
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
        n[i] = (char*)malloc(30 * sizeof *n[i]);
    Student* temp=(*ptr_list)->head;
    // fill the 2arrays with names and marks
    while(temp!=NULL)
    {
        rank_Eng[count]=temp->Scores.eng;
        strcpy(n[count],temp->Name); 
        count++;
        temp=temp->next;
    }
    // apply bubble sort on the arrays
    for (int step = 0; step < ((*ptr_list)->num_of_students) - 1; ++step) 
    {
        int swapped = 0;
        for (int i = 0; i < ((*ptr_list)->num_of_students) - step - 1; ++i) 
        {
            if (rank_Eng[i] > rank_Eng[i + 1]) 
            {  
                temp_rank = rank_Eng[i];
                rank_Eng[i] = rank_Eng[i + 1];
                rank_Eng[i + 1] = temp_rank; 
                strcpy(temp_name,n[i]);
                strcpy(n[i],n[i+1]);
                strcpy(n[i+1],temp_name); 
                swapped = 1;
            }
        }
        if (swapped == 0) 
        {
          break;
        }
    }
    // print ranked lists
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
    {
        printf("\nName: %-30s  Score: %hd",n[i],rank_Eng[i]);
    }
    // free used memory in heap
    free(rank_Eng);
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
        free(n[i]);
    
}

void RankArbScore(LinkedList** ptr_list)
{
    // create arrays in heap to hold names and marks
    short* rank_Arb=(short*)malloc(((*ptr_list)->num_of_students)*sizeof(int));
    char** n=(char**)malloc(((*ptr_list)->num_of_students)*sizeof(char**));
    short temp_rank;
    char temp_name[30];
    int count=0;
    // create each string in the array of strings of names
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
        n[i] = (char*)malloc(30 * sizeof *n[i]);
    Student* temp=(*ptr_list)->head;
    // fill the 2arrays with names and marks
    while(temp!=NULL)
    {
        rank_Arb[count]=temp->Scores.arabic;
        strcpy(n[count],temp->Name); 
        count++;
        temp=temp->next;
    }
    // apply bubble sort on the arrays
    for (int step = 0; step < ((*ptr_list)->num_of_students) - 1; ++step) 
    {
        int swapped = 0;
        for (int i = 0; i < ((*ptr_list)->num_of_students) - step - 1; ++i) 
        {
            if (rank_Arb[i] > rank_Arb[i + 1]) 
            {  
                temp_rank = rank_Arb[i];
                rank_Arb[i] = rank_Arb[i + 1];
                rank_Arb[i + 1] = temp_rank; 
                strcpy(temp_name,n[i]);
                strcpy(n[i],n[i+1]);
                strcpy(n[i+1],temp_name); 
                swapped = 1;
            }
        }
        if (swapped == 0) 
        {
          break;
        }
    }
    // print ranked lists
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
    {
        printf("\nName: %-30s  Score: %hd",n[i],rank_Arb[i]);
    }
    // free used memory in heap
    free(rank_Arb);
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
        free(n[i]);
    
}

void RankAllScore(LinkedList** ptr_list)
{
    // create arrays in heap to hold names and marks
    short* rank_All=(short*)malloc(((*ptr_list)->num_of_students)*sizeof(int));
    char** n=(char**)malloc(((*ptr_list)->num_of_students)*sizeof(char**));
    short temp_rank;
    char temp_name[30];
    int count=0;
    // create each string in the array of strings of names
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
        n[i] = (char*)malloc(30 * sizeof *n[i]);
    Student* temp=(*ptr_list)->head;
    // fill the 2arrays with names and marks
    while(temp!=NULL)
    {
        // add only available grades
        rank_All[count]=0;
        if(temp->Scores.arabic>=0)
            rank_All[count]+=(temp->Scores.arabic);
        if(temp->Scores.math>=0) 
            rank_All[count]+=(temp->Scores.math);
        if(temp->Scores.eng>=0)  
            rank_All[count]+=(temp->Scores.eng);
        //rank_All[count]=(temp->Scores.arabic)+(temp->Scores.math)+(temp->Scores.eng);
        strcpy(n[count],temp->Name); 
        count++;
        temp=temp->next;
    }
    // apply bubble sort on the arrays
    for (int step = 0; step < ((*ptr_list)->num_of_students) - 1; ++step) 
    {
        int swapped = 0;
        for (int i = 0; i < ((*ptr_list)->num_of_students) - step - 1; ++i) 
        {
            if (rank_All[i] > rank_All[i + 1]) 
            {  
                temp_rank = rank_All[i];
                rank_All[i] = rank_All[i + 1];
                rank_All[i + 1] = temp_rank; 
                strcpy(temp_name,n[i]);
                strcpy(n[i],n[i+1]);
                strcpy(n[i+1],temp_name); 
                swapped = 1;
            }
        }
        if (swapped == 0) 
        {
          break;
        }
    }
    // print ranked lists
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
    {
        printf("\nName: %-30s  ALL Scores: %hd",n[i],rank_All[i]);
    }
    // free used memory in heap
    free(rank_All);
    for (int i = 0; i < ((*ptr_list)->num_of_students); i++)
        free(n[i]);
    
}

void EditEngScore(LinkedList** ptr_list,char* n,short s)
{
    Student* temp=(*ptr_list)->head;
    while (temp!=NULL)
    {
        if(stricmp(n,temp->Name)==0 )
        {
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\n cant edit !! student not exist\n");
        return;
    }
    else
    {
        temp->Scores.eng=s;
    }
}

void EditMthScore(LinkedList** ptr_list,char* n,short s)
{
    Student* temp=(*ptr_list)->head;
    while (temp!=NULL)
    {
        if(stricmp(n,temp->Name)==0 )
        {
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\n cant edit !! student not exist\n");
        return;
    }
    else
    {
        temp->Scores.math=s;
    }
}
void EditArbScore(LinkedList** ptr_list,char* n,short s)
{
    Student* temp=(*ptr_list)->head;
    while (temp!=NULL)
    {
        if(stricmp(n,temp->Name)==0 )
        {
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\n cant edit !! student not exist\n");
        return;
    }
    else
    {
        temp->Scores.arabic=s;
    }
}

void ListAllScore(LinkedList** ptr_list)
{
    Student* temp=(*ptr_list)->head;
    if(temp==NULL)
    {
        printf("\nEmpty!! no list to display\n");
        return;
    }
    printf("\nName                           Math     English     Arabic\n");
    while(temp!= NULL)
    {
        printf("%-30s %-8hd %-11hd %hd\n",temp->Name,temp->Scores.math,temp->Scores.eng,temp->Scores.arabic);
        temp=temp->next;
    }
}