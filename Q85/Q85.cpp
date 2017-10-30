#include<iostream>
#include"list.h"
#include"xxzString.h"


list<int> data;
bool first=true;
void print(){
	if (!first){
		std::cout << std::endl;
	}
	first = false;
	bool o = true;
	auto end = data.cend();
	auto now = data.begin();
	for (; now != end; now++){
		if (!o){
			std::cout << " ";
		}
		o = false;
		std::cout << now;
	}
	//std::cout << std::endl;
}
void replace(){
	int rep, latest;
	std::cin >> rep >> latest;
	auto begin = data.begin(), end = data.cend();
	for (; begin != end; begin++){
		if (begin.mem() == rep){
			begin.mem() = latest;
		}
	}
}
void move(){
	int num;
	xxzString op;
	std::cin >> op >> num;
	if (op == "head"){
		auto begin = data.begin(), end = data.cend(),cbegin=data.cbegin();
		for (; begin != end; begin++){
			if (begin.mem() == num&&begin!=cbegin){
				data.insertV(0, begin.mem());
				data.remove(begin);
				begin--;
			}
		}
	}
	else if (op == "tail"){
		auto begin = data.cbegin(), end = data.end()-1, cend = data.cend();
		for (; begin != end; end--){
			if (end.mem() == num&&end != cend-1){
				data.pushV(end.mem());
				data.remove(end);
			}
		}
		if (end.mem() == num&&end != cend - 1){
			data.pushV(end.mem());
			data.remove(end);
		}
	}
}

void trans(){
	xxzString cmd;
	int cnt;
	std::cin >> cmd >> cnt;
	if (cmd == "tail"){
		for (int i = 0; i < cnt; i++){
			data.insertV(0,data.pop());
		}
	}
	else if (cmd == "head"){
		for (int i = 0; i < cnt; i++){
			data.pushV(data.dequeue());
		}
	}
}
int main(){
	int n,x;
	std::cin >> n;
	for (int i = 0; i < n; i++){
		std::cin >> x;
		data.pushV(x);
	}
	std::cin >> n;
	int cnt = 0;
	while (cnt++ != n){
		xxzString cmd;
		std::cin >> cmd;
		switch (cmd[0]){
		case 'p':
			print();
			break;
		case 'r':
			replace();
			break;
		case 'm':
			move();
			break;
		case't':
			trans();
			break;
		}
	}
	return 0;
}