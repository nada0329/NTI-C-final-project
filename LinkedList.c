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
