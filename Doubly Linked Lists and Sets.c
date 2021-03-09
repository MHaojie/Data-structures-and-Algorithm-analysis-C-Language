// Author:Haojie Ma
// Student ID:z5196705
// Platform: Windows
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

// all the basic data structures and functions are included in this template
// you can add your own auxiliary functions as you like 

// data structures representing DLList

// data type for nodes
typedef struct DLListNode {
	int  value;  // value (int) of this list item 
	struct DLListNode *prev;
	// pointer previous node in list
	struct DLListNode *next;
	// pointer to next node in list
} DLListNode;

//data type for doubly linked lists
typedef struct DLList{
	int  size;      // count of items in list
	DLListNode *first; // first node in list
	DLListNode *last;  // last node in list
} DLList;

// create a new DLListNode
DLListNode *newDLListNode(int it)
{
	DLListNode *new;
	new = malloc(sizeof(DLListNode));
	assert(new != NULL);
	new->value = it;
	new->prev = new->next = NULL;
	return new;
}

// create a new empty DLList
DLList *newDLList()
{
	DLList *L;

	L = malloc(sizeof (struct DLList));
	assert (L != NULL);
	L->size = 0;
	L->first = NULL;
	L->last = NULL;
	return L;
}

// create a DLList from a text file
// put your time complexity analysis for CreateDLListFromFileDlist() here
// The time complexity is O(n^2)
DLList *CreateDLListFromFileDlist(const char *filename)
{
   int i,f,c;
   char a[20];
   char b[10] = "end";
   char s[10] = "stdin";
   DLList *L1,*L2;
   L1=newDLList();
   L2=newDLList();
   L1->first = malloc(sizeof(DLListNode));
   L2->first = malloc(sizeof(DLListNode));
   DLListNode *m,*h,*p,*q;
   m=L1->first;
   p=L2->first;
    FILE *fpRead = fopen(filename,"r");
    if(fpRead==NULL)  
    {  
        if (strcmp(filename,s) == 0)
        {
            scanf("%s", a);
            int j = 0;
            while(strcmp(a,b) != 0)
            {
                for(i = 0;i<20;i=i+1)
                {
                    if(a[i] == 0)  
                        break;
                    else if(a[0] == 45)
                        continue;
                    else if(a[i]<48||a[i]>57)
                    {
                        printf("Invalid input!\n");
//                       DLList *list_NULL;
//					    list_NULL = newDLList();
				    	          return NULL;
                    }
                    else
                        continue;
                }
                c = atoi(a);
    		        h = newDLListNode(c);
    		        m->next=h;
    		        h->prev=m;
    		        j=j+1;
    		        m = h;
                scanf("%s", a);
            }
            m->next = NULL;
            L1->first = L1->first->next;
    		    L1->last = m;
    		    L1->size = j;           
            return L1;  
        }   
        else
        {
            printf("file doesn't exist!\n");
            return NULL;
        } 
    }
    int k = 0;  
    while(fscanf(fpRead,"%d",&f)!=EOF)
    {
      	q = newDLListNode(f);
        p->next=q;
        q->prev=p;
        k=k+1;
        p = q;
    }
    L2->first = L2->first->next;
    p->next = NULL;
    L2->last = p;
    L2->size = k;
    return L2;    
}
// clone a DLList
// put your time complexity analysis for cloneList() here
// The time complexity is O(n)
DLList *cloneList(DLList *u)
{
	assert(u!=NULL);
    DLList *c_u;
    c_u = newDLList();
    DLListNode *copy1,*copy2,*copy3,*s1;
    copy1 = newDLListNode(0);
    copy2 = copy1;
    s1 = newDLListNode(0);
    s1->next= u->first;
    while(s1->next != NULL)
    {
      copy3 = newDLListNode(0);
      copy3->value = s1->next->value;
      copy2->next = copy3;
      copy3->prev = copy2;
      copy2 = copy3;
      s1 = s1->next;
    }
    copy2->next = NULL;
    c_u->size=u->size;
    c_u->first = copy1->next;
    c_u->last = copy2;
    return c_u;
}

// compute the union of two DLLists u and v
// The time complexity is O(n^2)
DLList *setUnion(DLList *u, DLList *v)
{
    /*int i1,i2,num_of_deletenode=0;
    DLList *temp;
    temp = newDLList();
    temp->size = u->size + v->size;
    temp->first = u->first;
    temp->last = v->last;
    u->last->next = v->first;
    v->first->prev = u->last;

    DLListNode *compare1,*compare2;
    compare1 = newDLListNode(0);
    compare1->next = temp->first;
    compare2 = newDLListNode(0);
    compare2->next = temp->first;
    for(i1=1;i1<temp->size;i1++)
    {
      for(i2=temp->size-1;i2>0;i2=temp->size-i1)
      {
        if(compare1->next->value != compare2->next->prev->value)
        {
          compare2->next = compare2->next->prev;
          continue;
        }
        else
        {
          compare1->next->prev->next=compare1->next->next;
          num_of_deletenode = num_of_deletenode + 1;
          break;
        }
      }
      compare1->next=compare1->next->next;
    }
    temp->size = temp->size - num_of_deletenode;
    return temp;*/
    int i_v,j_v,i_u,sign_1_is_in_v_or_not,L4_size;
    L4_size = 0;
    DLList *L4;
    L4=newDLList();
    L4->first = malloc(sizeof(DLListNode));  
    DLListNode *sign_1,*sign_2,*sign_v,*p_1,*q_1;
    p_1=L4->first;
    sign_1 = newDLListNode(0);
    sign_2 = newDLListNode(0);
    sign_v = newDLListNode(0);
    sign_1->next=u->first;  
    for(i_u = 1; i_u <= u->size; i_u++)
    {
        sign_2->next=v->first;
        sign_1_is_in_v_or_not = 0;
        for(j_v = 1;j_v <= v->size; j_v++)
        {
          if(sign_1->next->value == sign_2->next->value)
          {
              sign_1_is_in_v_or_not=sign_1_is_in_v_or_not+1;
              break;
          }
          else
          {
              sign_2->next = sign_2->next->next;
              continue;
          } 
        }
        if (sign_1_is_in_v_or_not == 0)
        {
          q_1=newDLListNode(sign_1->next->value);
          p_1->next=q_1;
          q_1->prev=p_1;
          L4_size=L4_size+1;
          p_1 = q_1;
        }
        sign_1->next=sign_1->next->next;
    }
    sign_v->next = v->first;
    for(i_v=1;i_v<=v->size;i_v++)
    {
      q_1=newDLListNode(sign_v->next->value);
      p_1->next=q_1;
      q_1->prev=p_1;
      L4_size=L4_size+1;
      p_1 = q_1;
      sign_v->next=sign_v->next->next;
    }
    L4->first = L4->first->next;
    p_1->next = NULL;
    L4->last = p_1;
    L4->size = L4_size;

    /*int i1,i2;
    DLList *temp;
    temp = newDLList();
    temp->size = u->size + L4->size;
    temp->first = u->first;
    temp->last = L4->last;
    u->last->next = L4->first;
    L4->first->prev = u->last;
    return temp;8*/
    return L4;

}

// compute the insection of two DLLists u and v
// put your time complexity analysis for intersection() here
// The time complexity is O(n^2)
DLList *setIntersection(DLList *u, DLList *v)
{
    int iv,ju,L3_size;
    L3_size = 0;
    DLList *L3;
    L3=newDLList();
    L3->first = malloc(sizeof(DLListNode));  
    DLListNode *sign1,*sign2,*p1,*q1;
    p1=L3->first;
    sign1 = newDLListNode(0);
    sign2 = newDLListNode(0);
    sign1->next=v->first;  
    for(iv = 1; iv <= v->size; iv++)
    {
        sign2->next=u->first;
        for(ju = 1;ju <= u->size; ju++)
        {
          if(sign1->next->value == sign2->next->value)
          {
              q1=newDLListNode(sign1->next->value);
              p1->next=q1;
              q1->prev=p1;
              L3_size=L3_size+1;
              p1 = q1;
              break;
          }
          else
          {
              sign2->next = sign2->next->next;
              continue;
          } 
       }
       sign1->next=sign1->next->next;
    }
    L3->first = L3->first->next;
    p1->next = NULL;
    L3->last = p1;
    L3->size = L3_size;
    return L3;
}

// free up all space associated with list
// put your time complexity analysis for freeDLList() here
// The time complexity is O(n)
void freeDLList(DLList *L)
{
    DLListNode *free_node;
    while(L->first->next != NULL)
    {
      free_node = L->first;
      L->first = L->first->next;
      free(free_node);
      free_node = NULL;
    }
    free_node = L->first;
    L->first = NULL;
    free(free_node);
    free_node = NULL;
}


// display items of a DLList
// put your time complexity analysis for printDDList() here
// The time complexity is O(n)
void printDLList(DLList *u)
{
	assert(u != NULL);
    DLListNode *s;
    s = newDLListNode(0);
    s->next= u->first;
    while(s->next != NULL)
    {
      printf("%d\n",s->next->value);
      s = s->next;
    }
}

int main()
{
 DLList *list1, *list2, *list3, *list4;

 list1=CreateDLListFromFileDlist("File1.txt");
 printDLList(list1);
 

 list2=CreateDLListFromFileDlist("File2.txt  ");
 printDLList(list2);

 list3=setUnion(list1, list2);
 printDLList(list3);

 list4=setIntersection(list1, list2);
 printDLList(list4);

 freeDLList(list1);
 freeDLList(list2);
 freeDLList(list3);
 freeDLList(list4);

 printf("please type all the integers of list1\n");
 list1=CreateDLListFromFileDlist("stdin");

 printf("please type all the integers of list2\n");
 list2=CreateDLListFromFileDlist("stdin");

 list3=cloneList(list1);
 printDLList(list3);
 list4=cloneList(list2);
 printDLList(list4);

 freeDLList(list1);
 freeDLList(list2);
 freeDLList(list3);
 freeDLList(list4);

 return 0; 
}