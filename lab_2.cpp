//including library
#include<iostream>

using namespace std;

class node{
	public:
	/* CONTAINS TWO THINGS;
	 * => the data it stores                           (line 12)
	 * => the pointer next to node                     (line 13)
	 */
	int data;
	node* ptr;
	
	//defult constructor
	node() 
	{
		data = 0;
		ptr = NULL;
	}
	//constuctor with an input
	node(int a) {
		data=a;
		ptr=NULL;
		}
	};

//
class linkedlist 
{
	 public:
    //a linklist points to the head of the chain of datas
    node* head=NULL;
    //a linklist has several fns like:
    //inserting a node at the end of the linklist
    
    void insert(int data){
        // creating a unit in the heap with the data stored and saving its address
        
        node* temp=new node(data);
        //now go to the second last part in the linklist
        
        if(head==NULL)                                                    // using if condition
        {
			//that is the linklist is empty
            head=temp;
        }
        
        else
        {
			//if linklist atleast has one unit
			
            node* current;
            for(current=head;current->ptr!=NULL;)                         // for loop
            {
                current=current->ptr;
            }
            current->ptr=temp;
        }
    }
    
    //displaying the linklist
    
    void display()
    {
        //after displaying the data change the address to next node
        
        node* current=head;
        for(;current!=NULL;){                                             //for loop
            cout<<current->data<<"->";
            current=current->ptr;
        }
        
        //the linklist ends with a NULL
        cout<<"NULL"<<endl;
    }
    
    //inserting a node at a specified location in the linklist
    void insertat(int pos, int data)
    {
		// create a node in the heap with the data stored & address recorded
        node* temp=new node(data);
        
        //now go to the required place in the linklist
        node* current=head;
        
        //a boolean to verify whether we reached the desired pos or not
        bool exist=1;
        for (int i=1;i<pos-1;i++)                                          //for loop
        {
            if(current->ptr!=NULL)                                         // if else condition
            {
				//if some node exists after the current node
                current=current->ptr;
            }
            else
            {
				//otherwise our linklist is too short (i is always < pos-1)
                cout<<"Such position doesnt exist in the linklist"<<endl;
                exist=0;
                break;
            }
        }
        
        if(exist==1)
        {
			//this only gets executed if we reach the required positions
            //now that current holds the required positions address, we make temps ptr point to currents next node
            temp->ptr=current->ptr;
            //next point current node to temp
            current->ptr=temp;
        }
    }
    //adding a function to delete the last node
    
    void deleteit()
    {
        //first go to the second last node of the linklist
         if(head==NULL)                                                     //if condition
         {
			 //if linklist is empty
            cout<<"Linklist is already empty!"<<endl;
        }
        else
        {
			//node linklist atleast has two units
            node* current;
            node* temp;
            for(current=head;current->ptr->ptr!=NULL;)
            {
                current=current->ptr;
            }
            //now that we have reached the second last node, we store the last node address in temp and point the second last ptr to null
            temp=current->ptr;
            current->ptr=NULL;
            delete temp;
        }
    }
    //a function is used to delete at a desired position
    void deleteat(int pos)
    {
        //first go to that required position
        node* current=head;
        
        //a boolean to verify whether we reached the required position or not
        bool exist=1;
        for (int i=1;i<pos-1;i++)                                             // for loop
        {
            if(current->ptr!=NULL)                                            //if condition
            {
				//if some nod exists after the current node
                current=current->ptr;
            }
            else
            {
				//otherwise our linklist is too short (i is always < pos-1)
                cout<<"Such position doesnt exist in the linklist"<<endl;
                exist=0;
                break;
            }
        }
        if(exist==1)
        {
			//this only gets executed if we reach the desired pos
            //now that current holds the desired positions address, we store the next units address in temp and point the current unit to null
            node* temp=current->ptr;
            current->ptr=current->ptr->ptr;
            delete temp;
        }
    }
    //a function to count the no of nodes in linklist
    int countit()
    {
        //we create a variable ptr that points to head and then moves to the next node as each loop is executed
        node* current=head;
        int i=0;
        //our data that stores the no of times the loop is executed
        for(;current!=NULL;i++){
            current=current->ptr;
        }
        return i;
    }
};
//main function
int main()
{
    //creating a linklist
    linkedlist l1;
    l1.insert(1);
    l1.display();
    l1.insert(5);
    l1.display();
    l1.insert(3);
    l1.insert(66575);
    l1.insert(334);
    l1.display();
    cout<<l1.countit()<<endl;
    l1.insertat(20 , 777);
    l1.display();
    l1.deleteit();
    l1.display();
    l1.deleteat(2);
    l1.display();
    cout<<l1.countit()<<endl;
    //terminating  the function
    return 0;
}
