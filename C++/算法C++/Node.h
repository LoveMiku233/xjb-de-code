#ifndef _Node_MIKU_
#define _Node_MIKU_

//数据储存在“节点(Node)"中

class Node
{
private:
    /* data */
    int data,size;
    Node *next,*head,*prev;
public:
    Node(int a,Node *b):data(a),next(b){size=0;};
    Node(int a):data(a){next=NULL;size=0;};
    Node(){data=0;next=NULL;size=0;};
    void printNode();
    void LinkedList(){head=NULL;size=0;};
    int getSize(){return size;};
    bool isEmpty(){return (size==0);};
    void addFirst(int a){
        //Node node1(a);
       // node1.next=head;
       // head=&node1;
        head=new Node(a,head);
        size++;
    };
    void printLinked();
    void add(int,int);
};
void Node::add(int index,int a){
    if(index<0||index>size)
        std::cout<<"GG"<<std::endl;
    if(index==0)
        addFirst(a);
    else{
        prev=head;
        for(int i=0;i<index-1;i++)
            prev=prev->next;
       // Node Node1(a);
       //Node1.next=prev.next;
        //prev.next=node;
        prev->next=new Node(a,prev);
        size++;
    }
}
void Node::printNode(){
    std::cout<<"Data: "<<data;
    //std::cout<<" Next data: "<<(next==NULL)?next->data:0;
}
void Node::printLinked(){
    prev=head;
    for(int i=0;i<size;i++){
        std::cout<<"index: "<<i<<" ";
        std::cout<<"data: "<<prev->data<<std::endl;
        prev=prev->next; 
    }
}
#endif