#include "xxzNumber.h"

xxzNumber::xxzNumber(){
	initial();
}

void xxzNumber::initial(){
	data.pushV(0);
}

std::istream& operator>>(std::istream& cin, xxzNumber& num){
	char c;
	while (cin.peek() != 'n'){
		cin >> c;
			num.data.pushV(c - '0');
		//'>'
		cin >> c;
	}
	//n u l l 
	cin >> c >> c >> c >> c;	
	return cin;
}

std::ostream& operator<<(std::ostream& cout, const xxzNumber& num){
	auto tmp = num.data;
	int size = num.data.size();
	bool isLZ = true;
	for (int i = 0; i < size; i++){
		if (isLZ&&tmp[0] == 0 && i != size - 1){
			tmp.dequeue();
		}
		else{
			isLZ = false;
			cout << tmp[0];
			tmp.dequeue();
			cout << ">";
		}
	}
	cout << "null";
	return cout;
}

xxzNumber xxzNumber::operator+(xxzNumber& op){
	list<int> ret;
	auto tb = op.data;
	int cin = 0;
	while (!data.empty() && !op.data.empty()){
		int a = data.pop();
		int b = op.data.pop();
		int tmp = a + b + cin;
		ret.insertV(0,tmp%10);
		cin = tmp / 10;
	}
	if (!data.empty()){
		while (!data.empty()){
			int a = data.pop();
			int tmp = a + cin;
			ret.insertV(0, tmp % 10);
			cin = tmp / 10;
		}
	}
	if (!op.data.empty()){
		while (!op.data.empty()){
			int a = op.data.pop();
			int tmp = a + cin;
			ret.insertV(0, tmp % 10);
			cin = tmp / 10;
		}
	}
	ret.insertV(0, cin);
	op.data = tb;
	data = ret;
	return *this;
}


