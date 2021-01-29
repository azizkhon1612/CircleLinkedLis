#include <iostream>

using namespace std;
class List
{
private:


    struct node
    {
        int data;
        node *next;

    };
    typedef struct node* nodePtr;//typedef making things easier to type
    nodePtr tail, curr,temp,prev;//declaring pointer variables
public:
    int len=0;
    List();
    void AddNode(int addData);//append
    void Indexposition(int addData,int index);//append in specific position
    void DeleteNode(int delData);//deleting note by data
    void delbyindex(int delpos);//deleting note by index
    void PrintList();//printing the list
    int length(int len);//length of node
    void display_n(int n);
    void josephus(int n);



};
List::List()
{
    tail=NULL; // beginning of List
    curr=NULL; // "current" marker/pointer to refer to a particular position in list
    temp=NULL;
    prev=NULL;

}
//add node with value

void List::AddNode(int addData)
{
    nodePtr n=new node;//new node declaration
    n->next=NULL;
    n->data=addData;
    if(tail!=NULL)//if list is not empty
    {
        n->next=tail->next;//new node next address pointing to the beginning
        tail->next=n;//beginning pointing to new node
        tail=n;//last node is equal to new node
    }
    else
    {

        tail=n;//last node pointing to new node
        tail->next=n;//last node pointing to the beginning
    }


}

//insert to a specific position to specific value
void List::Indexposition(int addData,int index)
{
    nodePtr n=new node;//creating new node
    n->data=addData;//new node data is equal to value
    n->next=NULL;
    int i=1;
    int l=length(0);//getting length of a list
    if(tail!=NULL)//if list is not empty go inside
    {
        if(index==0)//if index is 0 then insert at the beginning
        {
            n->next=tail->next;//new node next pointer is pointing to the beginning of a list
            tail->next=n;//tail next address pointing to new node
        }
        else if(index>=l)//insert at the end
        {
            n->next=tail->next;//new node next link to tail next value
            tail->next=n;//tail next value pointing to new node
            tail=n;//tail is equal to new node
        }
        else//insert specific position
        {
            curr=tail->next;//traversing
            while(i<index-1)
            {
                curr=curr->next;
                i++;

            }
            n->next=curr->next;//new node next value pointing to current founded value
            curr->next=n;//current next value pointing to a new node

        }
    }

    else
    {
        tail=n;
        tail->next=n;
    }
}


//delete by value
void List::DeleteNode(int delData)
{
    nodePtr delPtr=NULL;//declaring empty pointer
    temp=tail->next;
    curr=tail->next;
    do //traversing the list
    {
        temp=curr;
        curr=curr->next;


    }
    while(curr!=tail->next&&curr->data!=delData); //terminate if address equal to tail address and equal to value
    if(curr->data==delData) //if its equal to value
    {

        delPtr=curr;//pointer points to marker
        curr=curr->next;//marker points to next marker
        temp->next=curr;//temp variable pointing to marker

        delete delPtr;//deleting previous variable pointed by Delptr
    }
    else
    {
        cout<<"Not found"<<endl;
        delete delPtr;
    }
}

//delete by specific position
void List::delbyindex(int delpos)
{
    int l=length(0);//getting length of a function

    if(tail!=NULL) //if list is not empty
    {
        if(delpos==0) //if pos 0 insert at the beginning
        {
            temp=tail->next;
            if(temp->next==temp) //if next pointer points to beginning
            {
                tail=NULL;
                delete temp;
            }
            else
            {
                tail->next=temp->next;//last pointer next value is equal to temp next variable
                delete temp;
            }

        }
        else if(delpos>=l)
        {
            curr=tail->next;
            while(curr->next!=tail->next)
            {
                prev=curr;
                curr=curr->next;
            }
            prev->next=tail->next;
            tail=prev;
            delete curr;
        }
        else
        {
            int i=1;
            curr=tail->next;
            while(i<delpos-1)
            {
                curr=curr->next;
                i++;
            }
            temp=curr->next;
            curr->next=temp->next;
            delete(temp);
        }
    }

    else //else print list is empty
    {
        cout<<"List is empty"<<endl;
    }



}

//printing whole list
void List::PrintList()
{
    curr=tail->next;
    do
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    while(curr!=tail->next);
    cout<<endl;

}


//length of a list
int List::length(int len)
{
    if(tail!=NULL)//if list is not empty traverse the list
    {
        curr=tail->next;

        do
        {
            curr=curr->next;
            len++;
        }
        while(curr!=tail->next);
        return len;
    }
    else//else return zero
    {
        return 0;
    }

}


//print n elements of a list
void List::display_n(int n)
{
    int i=0;
    curr=tail->next;
    while(i<n)
    {
        cout<<curr->data<<" ";
        curr=curr->next;

        i++;
    }
    cout<<endl;
}



//Josephus problem
void List::josephus(int n)
{



    curr=tail->next;
    temp=tail->next;
//if there is more than one node
    while (curr->next!=curr)
    {
        int count=0;
        //finding n node
        while(count!=n)
        {
            temp=curr;
            curr=curr->next;
            count++;
        }
        //deleting n node
        temp->next=curr->next;//temp next address points to curr next address
        curr=temp->next;//curr address is equal to temp next address
    }
    cout<<"Last person is "<<curr->data<<endl;
}




int main()
{
    List l1;//list variable declaration
//variables
    char a;
    int n;
    int pos;
    int len;

    while(a!='x')
    {
        cin>>a;

        switch(a)
        {
        case 'a':
            cin>>n;
            l1.AddNode(n);
            break;
        case 'i':
            cin>>n>>pos;
            l1.Indexposition(n,pos-1);

            break;

        case 'r':
            cin>>n;
            l1.DeleteNode(n);
            break;
        case 'p':
            l1.PrintList();
            break;
        case 'l':
            len=l1.length(0);
            cout<<len<<endl;
            break;
        case 'd':
            cin>>pos;
            l1.delbyindex(pos-1);
            break;
        case 'z':
            cin>>n;
            l1.display_n(n);
            break;
        case 'j':
            cin>>n;
            l1.josephus(n);
            break;
        }
    }



    return 0;
}
