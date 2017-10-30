#ifndef list_h
#define list_h

template <typename T>
class list;
template <typename T>
struct iterator;

template <typename T>
struct node_base{
	virtual T& getData() = 0;
	//virtual node_base<T>* next(){
	//	return __next;
	//}
	//virtual node_base<T>* setNext(node_base<T>* p){
	//	__next = p;
	//}
	//virtual node_base<T>* previous(){
	//	return __previous;
	//}
	//virtual node_base<T>* setPrevious(node_base<T>* p){
	//	__previous = p;
	//}
	node_base<T>* next, *previous;
};

template <typename T>
struct cNode :node_base<T>{
	T& getData()override{
		return data;
	}
	cNode() = default;
	cNode(const T d) :data(d){}
private:
	T data;
};

template <typename T>
struct rNode :node_base<T>{
	T& getData()override{
		return data;
	}


	rNode(const T& d) :data(d){}
private:
	T& data;
};
template <typename T>
std::istream& operator>>(std::istream& cin, iterator<T>& it);
template <typename T>
 std::ostream& operator<<(std::ostream& cout, iterator<T>& it);

template<typename T>
struct iterator{
public:
	bool operator==(const iterator& it)const{
		return it.__data == __data;
	}
	bool operator!=(const iterator& it)const{
		return !operator==(it);
	}
	iterator<T>& operator++(int i){
		__data = __data->next;
		return *this;
	}
	iterator<T>& operator--(int i){
		__data = __data->previous;
		return *this;

	}
	iterator<T> operator+(int i){
		auto tmp = __data;
		if (i >= 0){
			int j = 0;
			while (j++ != i){
				tmp = tmp->next;
			}
		}
		else{
			return operator-(-i);
		}
		return *new iterator<T>(tmp);

	}
	iterator<T>& operator-(int i){
		auto tmp = __data;
		if (i >= 0){
			int j = 0;
			while (j++!= i)
				tmp = tmp->previous;
		}
		else{
			return operator+(-i);
		}
		return *new iterator<T>(tmp);


	}
	T& mem(){
		return __data->getData();
	}
	friend class list<T>;
	friend std::istream& operator>>(std::istream& cin, iterator<T>& it){
		return cin >> it.__data->getData();
	}
	friend std::ostream& operator<<(std::ostream& cout, iterator<T>& it){
		return cout<< it.__data->getData();
	}

private:
	iterator() = default;
	iterator(node_base<T>* p) :__data(p){}
	node_base<T>* __data;
};


template <typename T>
class list{
private:
	node_base<T>* __head;
	node_base<T>* __tail;
	int __length = 0;
	void init(){
		__head = new cNode<T>;
		__tail = new cNode<T>;
		__head->next = __tail;
		__tail->previous = __head;
		__length = 0;
	}
public:
	//constructor
	list(){
		init();
	}
	list(const list<T>& t){
		init();
		for (int i = 0; i < t.size(); i++){
			pushV(t.get(i));
		}
	}
	//destructor
	~list(){
		node_base<T>* tmp1 = __head;
		node_base<T>* tmp2 = tmp1->next;
		while (tmp2 != __tail&&tmp1 != __tail){
			delete tmp1;
			tmp1 = tmp2->next;
			tmp2 = tmp1->next;
		}
		if (tmp1 == __tail){
			delete tmp1;
		}
		else{
			delete tmp1;
			delete tmp2;
		}
	}
	list<T>& operator=(const list<T>& t){
		node_base<T>* tmp1 = __head;
		node_base<T>* tmp2 = tmp1->next;
		while (tmp2 != __tail&&tmp1 != __tail){
			delete tmp1;
			tmp1 = tmp2->next;
			tmp2 = tmp1->next;
		}
		if (tmp1 == __tail){
			delete tmp1;
		}
		else{
			delete tmp1;
			delete tmp2;
		}
		init();
		for (int i = 0; i < t.size(); i++){
			pushV(t.get(i));
		}
		return *this;

	}
	//const
	int size()const{
		return __length;
	}

	bool empty()const{
		return !__length;
	}

	T& get(int i)const{
		auto tmp = __head;
		int j = 0;
		do{
			tmp = tmp->next;
		} while (++j <= i);
		return tmp->getData();
	}

	T& getFirst()const{
		return __head->next->getData();
	}

	T& getLast()const{
		return __tail->previous->getData();
	}

	T& operator[](int i)const {
		return get(i);
	}
	//delete
	T dequeue(){
		if (empty()){
			return __head->next->getData();
		}
		__head->next = __head->next->next;
		auto tmp = __head->next->previous->getData();
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
		} while (++j <= i);
		tmp->previous->next = tmp->next;
		tmp->next->previous = tmp->previous;
		auto ret = tmp->getData();
		delete tmp;
		__length--;
		return ret;
	}

	T remove(iterator<T>& i){
		int j = 0;
		auto tmp = i.__data;
		i.__data = i.__data->next;
		tmp->previous->next = tmp->next;
		tmp->next->previous = tmp->previous;
		auto ret = tmp->getData();
		delete tmp;
		__length--;
		return ret;
	}

	T pop(){
		if (empty()){
			return __tail->previous->getData();
		}
		auto ret = __tail->previous->getData();
		__tail->previous = __tail->previous->previous;
		delete __tail->previous->next;
		__tail->previous->next = __tail;
		__length--;
		return ret;
	}

	//addMethod
	void insertV(int i, const T& t){
		int j = 0;
		auto tmp = __head;
		do{
			tmp = tmp->next;
		} while (++j <= i);
		auto toIns = new cNode<T>(t);
		//toIns->data = t;
		toIns->next = tmp;
		toIns->previous = tmp->previous;
		toIns->previous->next = toIns;
		toIns->next->previous = toIns;
		__length++;
	}

	void insertR(int i, T& t){
		int j = 0;
		auto tmp = __head;
		do{
			tmp = tmp->next;
		} while (++j <= i);
		auto toIns = new rNode<T>(t);
		//toIns->data = t;
		toIns->next = tmp;
		toIns->previous = tmp->previos;
		toIns->previous->next = toIns;
		toIns->next->previous = toIns;
		__length++;
	}

	void pushV(const T& t){
		auto tmp = new cNode<T>(t);
		//tmp->data = t;
		__tail->previous->next = tmp;
		tmp->previous = __tail->previous;
		tmp->next = __tail;
		__tail->previous = tmp;
		__length++;
	}

	void pushR(T& t){
		auto tmp = new rNode<T>(t);
		__tail->previous->next = tmp;
		tmp->previous = __tail->previous;
		tmp->next = __tail;
		__tail->previous = tmp;
		__length++;
	}

	const iterator<T>& cbegin(){
		return *new iterator<T>(__head->next);
	}

	const iterator<T>& cend(){
		return *new iterator<T>(__tail);
	}

	iterator<T>& begin(){
		return *new iterator<T>(__head->next);
	}

	iterator<T>& end(){
		return *new iterator<T>(__tail);
	}

};


#endif