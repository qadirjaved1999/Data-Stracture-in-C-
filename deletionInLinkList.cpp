#include<iostream>
using namespace std;

class Node {
   public:
   int data;
   Node* next;


   Node(int value){  //Default Constructors(Object create karna pa atumatically run hota ha)
    this->data = value;
    this->next = NULL;
   }

//Create Distructure
  ~Node(){
      int value = this->data;
      //Memory Free.
      if(this->next != NULL){
          delete next;
          this->next = NULL;
      }
      cout<< "Memeory is Free of that node "<<value<<endl;
  }

};

void insertHead(Node* &head, int d){

    // Create New Node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertTail(Node* &tail, int d){

    // Create New Node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition( Node* &tail, Node* &head, int position, int d){
    //Insertion at Start Position.
    if(position == 1){
        insertHead(head, d);
        return;
    }
   Node* temp = head;
   int current = 1;

   while (current < position - 1)
   {
       temp = temp->next;
       current++;
   }

//    Insertion At Last Position
   if(temp -> next == NULL){
       insertTail(tail, d);
       return;
   }

//    creating a node for d
   Node* nodeToInsert = new Node(d);
   nodeToInsert->next = temp->next;
   temp->next = nodeToInsert;
   
}


// Deletion in Link List
void deletionNode(Node* &head, int position){

      //Deletion first/start Node
      if(position == 1){
         Node* temp = head;
         head = head->next;
         //Memory Free.
         temp->next = NULL;
         delete temp;

      }else{
          //Deleting any Middle and Last node.
          Node* current = head;
          Node* previous = NULL;

          int curentP  = 1;
          while (curentP <= position)
          {
             previous = current;
             current = current->next;
             curentP++;
          }

          previous->next = current->next;
          current->next = NULL;
          delete current;
          
      }
  }




void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
       cout<< temp->data <<" ";
       temp = temp->next;
    }
    cout<<endl;
}


int main()
{ 

    Node* node1 = new Node(10); //Create Object.

    //Head pointed to node1
    Node* head = node1;
    Node* tail = node1;

    insertTail(tail, 12); // calling the function

    insertTail(tail, 15); // calling the function

    insertAtPosition(tail, head, 4, 44);

    print(head); //print

    deletionNode(head, 1);  //Deletetion function call
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;




    return 0;
}