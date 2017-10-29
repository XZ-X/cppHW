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
	xxzString(){ __size = 16; str = new char[16]; }
	//destructor
	~xxzString(){
		delete[] str;
	}
	//operator
	bool operator==(const xxzString& str)const;
	bool xxzString::operator==(const char* s)const;
	xxzString& operator=(const xxzString& str);

	//friends
	friend std::istream& operator>>(std::istream& is, xxzString& s);
	friend std::ostream& operator<<(std::ostream& os, xxzString& str);
	//other functions
	int size()const{ return __length; }



};

std::istream& operator>>(std::istream& is, xxzString& str);
std::ostream& operator<<(std::ostream& os, xxzString& str);


#endif