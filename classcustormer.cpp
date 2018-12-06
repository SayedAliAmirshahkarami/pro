#include <iostream>
#define max_size 5000
using namespace std;


class Persion{
	private:
	string name;
	string type;
	Persion* next;
//	friend class Queue(1000);
	public:
	Persion(string name,string type){
		this->name=name;
		this->type=type;
		
		
		
	}
	Persion(){
	}
	Persion(Persion& persion1){
		this->name=persion1.GetName();
		this->type=persion1.gettype();
		
	}
	
	
	Persion * GetNext()
	{
		return next;
	}
	
	string GetName(){
		return this->name;
		
		
		
	}
	string gettype(){
		return  this->type;
	}
	void SetName(string name){
		this->name=name;
		
		
	}
	void SetType(string type){
		this->type=type;
		
	}
	
	void SetNext(Persion *persion){
		next=persion;
	}

};
//******************************************************************************************************//end QUEUE CLASS









//***************************************************************
class Queue{
private:
  Persion *front,*rear;
  int maxSize , size;
public:
  Queue(int maxSize);
  void push_rear(Persion);
  Persion* pop_front();
  void display();
  bool hasValue(string name); //for search we use this
  bool isFull();
};

//****************************************************************

Queue::Queue(int maxSize){
   front = rear = NULL;
   this->maxSize = maxSize;
   size = 0;
}

//******************************************************************

bool Queue::isFull(){
  if(size == maxSize){
    return true;
  }
  return false;
}
//*********************************************************************

void Queue::push_rear(Persion persion1){
   if(isFull()){
     cout<<"queue is full"<<endl;
     return;
   }
   size++;
   Persion *temp = new Persion(persion1);
   //temp->SetName(persion1.GetName());
   temp->SetNext(NULL);

   if(front){
      rear->SetNext(temp);
   }
   else{
     front = temp;
   }
   rear = temp;
}




















//**********************************************************************************


Persion* Queue::pop_front(){
  if(front == NULL){
    cout<<"queue is empty"<<endl;
   // return 0;
  }
  size--;
  string name1 = front->GetName();
  Persion* temp=front;
  
  front = front->GetNext();
  

  if(front == NULL){
    rear = NULL;
  }
  return temp;
}

//*******************************************************************************

bool Queue::hasValue(string name){
    Persion *persion = front;
    while(persion){
      if(persion->GetName() == name){
        return true;
      }
      persion = persion->GetNext();
    }
    return false;
}

//***********************************************************************************

void Queue::display(){
    if(front == NULL){
      cout<<"queue is empty"<<endl;
      return;
    }
    cout<<"Elements in Queue are:\n";
    Persion *persion = front;
    while(persion){
        cout<<persion->GetName()<<endl;
        persion = persion->GetNext();
    }
    cout<<endl;
}

//*****************************************************************************************




//*************************************************************************************************

int main(){
	
		Queue queue1(100);
	//	Queue queue2;
	cout<<"enter the charactrecotr of the persion "<<endl;
	cout<<"please enter the 1-the name  2-type"<<endl;
	
	string name,type;
	
	
	for(int i=0;i<3;i++){
	
	cin>>name>>type;
	Persion persion1(name,type);
	queue1.push_rear(persion1);
	
}

for(int i=0;i<3;i++){
//	Persion *persion1=
	cout<<"name ---->  "<<queue1.pop_front()->GetName()<<endl;
	
}
	
	
}


