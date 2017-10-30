#include<iostream>
#include"list.h"
#include"xxzString.h"

#define isUpper(x) ((x)<='Z'&&(x)>='A')

using namespace std;
bool result = true;
list<xxzString> contentStack;
xxzString first,last;

bool pushTagName(){
	xxzString tmp;
	char c;
	while (cin.peek() != '>'){
		cin >> c;
		if (!isUpper(c)){
			return result = false;
			
		}
		tmp += c;
	}
	if (tmp.size() > 9||tmp.size()<1){
		return result = false;
	}
	contentStack.pushV(tmp);
}
bool isComment(){
	char c;
	xxzString str;
	if (cin.peek() == '!'){
		cin.read(str.getStr(), 3);
		str[3] = 0;
		if (str != "!--")
			return result = false;
		else{
			int state = 0;
			char c;
			while (cin>>c){
				if (cin.eof()){
					return result = false;
				}
				//"-->"
				if (c == '-'){
					state = (state == 2) ? 2 : state+1;
				}
				else if (c == '>'){
					if (state == 2){
						cin.unget();
						return true;
					}
					else{
						state = 0;
					}
				}
				else{
					state = 0;
				}
				
			}
		}		
	}else{
		return false;
	}
}

bool judgeTagContents(){
	char c;
	xxzString str;
	bool one = true;
	while (result && (cin.peek() != '\n'&&cin.peek() != EOF)){
		cin >> c;
		switch (c)
		{
		case'<':
			if (!isComment()){
				if (cin.peek() != '/'){
					//is open tag
					if (one || !contentStack.empty()){
						if (pushTagName()) return false;
						one = false;
						if (first.size() == 0) first = contentStack.getLast();
						//the close '>' of Tag
						cin >> c;
					}
					else{
						return result = false;
					}
				}
				else{//is close tag
					//the '/' of close tag
					cin >> c;
					if (pushTagName()) return false;
					xxzString ctag = contentStack.pop();
					xxzString otag = contentStack.pop();
					if (ctag != otag) return result=false;
					//the '>'
					last = ctag;
					cin >> c;
				}
			}
			else{
				//the close '>' of comment
				if (contentStack.empty()) return result = false;
				cin >> c;
			}
			break;
		case'(':
			contentStack.pushV(c);
			break;
		case')':
			if (contentStack.pop()[0] != '(') return result = false;
			break;
		default:
			break;
		}
	}

}

int main(){

	if (cin.peek() != '<'){
		result = false;
	}
	else{
		judgeTagContents();
	}
	if (result&&contentStack.empty()&&last==first){
		cout << "True";
	}
	else{
		cout << "False";
	}
	

	return 0;
}