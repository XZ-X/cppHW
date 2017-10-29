#ifndef list_h
#define list_h

template<typename T>
struct node{
	T& data;
	node<T>* previous, *next;
	node(T& d) :data(d){};
	node()=default;
};


template<typename T>
class list{
private:
	node<T>* __head;
	node<T>* __tail;
	int __length;
	void initial(){
		T tmd;
		__head = new node<T>(tmd);
		__tail = new node<T>(tmd);
		__head->next = __tail;
		__tail->previous = __head;
		__head->previous = __tail->next = nullptr;
		__length = 0;
	}
public:
	//constructor
	list(){
		initial();
	}
	//destructor
	~list(){
		node<T>* tmp1=__head;
		node<T>* tmp2=tmp1->next;
		while (tmp2 != __tail){
			delete tmp1;
			tmp1 = tmp2->next;
			tmp2 = tmp1->next;
		}
		delete tmp1;
		delete tmp2;
	}

	//const methods

	int size()const{ 
		return __length;
	}

	bool empty()const{
		return !__length;
	}

	T& get(int i)const{
		auto tmp = __head;
		int j = -1;
		do{
			tmp = tmp->next;
		} while (++j != i);
		return tmp->data;
	}

	T& getFirst()const{
		return __head->next->data;
	}

	T& getLast()const{
		return __tail->previous->data;
	}


	//delete method

	T dequeue(){
		if (empty()){
			return __head->next->data;
		}
		__head->next = __head->next->next;
		auto tmp = __head->next->previous->data;
		delete __head->next->previous;
		__head->next->previous = __head;
		__length--;
		return tmp;
	}

	T remove(int i){
		int j = 0;
		auto tmp = __head;
		do{
			tmp = tmp->next;
		} while (++j != i);
		tmp->previous->next = tmp->next;
		tmp->next->previous = tmp->previous;
		auto ret=tmp->data;
		delete tmp;
		__length--;
		return ret;
	}

	T pop(){
		if (empty()){
			return nullptr;
		}
		auto ret = __tail->previous->data;
		__tail->previous = __tail->previous->previous;
		delete __tail->previous->next;
		__tail->previous->next = __tail;
		__length--;
		return ret;
	}

	//addMethod
	void insert(int i,T& t){
		int j = 0;
		auto tmp = __head;
		do{
			tmp = tmp->next;
		} while (++j != i);
		auto toIns = new Node<T>(t);
		//toIns->data = t;
		toIns->next = tmp;
		toIns->previous = tmp->previos;
		toIns->previous->next = toIns;
		toIns->next->previous = toIns;
		__length++;
	}

	void push(T& t){
		auto tmp = new node<T>(t);
		//tmp->data = t;
		__tail->previous->next = tmp;
		tmp->previous = __tail->previous;
		tmp->next = __tail;
		__tail->previous = tmp;
		__length++;
	}
	
	void insertFirst(T& t){
		insert(0, t);
	}

};


#endif