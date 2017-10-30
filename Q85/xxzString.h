#ifndef xxz_string_h
#define xxz_string_h
#include<iostream>
class xxzString{
private:
	char* str;
	int __size = 0;
	int __length = 0;
	void extend();
public:
	//constructor
	xxzString(const xxzString& str);
	xxzString(const char* c);
	xxzString(const char& c);
	xxzString(){ __size = 16; str = new char[16]; }
	//destructor
	~xxzString(){
		delete[] str;
	}
	//operator
	bool operator==(const xxzString& str)const;
	bool operator!=(const xxzString& str)const{ return !operator==(str); }
	bool xxzString::operator==(const char* s)const;
	bool xxzString::operator!=(const char* s)const{ return !operator==(s); }
	xxzString& operator=(const xxzString& str);
	xxzString& operator+=(const xxzString& str);
	char& operator[](const int& i)const{ return str[i]; }
	//friends
	friend std::istream& operator>>(std::istream& is, xxzString& s);
	friend std::ostream& operator<<(std::ostream& os, xxzString& str);
	//other functions
	int size()const{ return __length; }
	char* getStr(){ 
		return str; 
	}


};

std::istream& operator>>(std::istream& is, xxzString& str);
std::ostream& operator<<(std::ostream& os, xxzString& str);


#endif