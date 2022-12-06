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

