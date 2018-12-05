#iclude <iostream>
using namespace std;
class Persion{
	private:
	string name;
	string type;
	Persion* next;
	public:
	Persion(string name,string type){
		this->name=name;
		this-type=type;
		
		
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

