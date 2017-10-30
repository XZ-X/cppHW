#include"xxzString.h"
#define isSpace(x) ((x)==' '||(x)=='\t')
#define isEnd(x) ((x)=='\n'||(x)==EOF)


void xxzString::extend(){
	auto tmp = new char[__size << 1];
	memcpy(tmp, str, __size);
	__size <<= 1;
	delete[] str;
	str = tmp;
}

xxzString::xxzString(const xxzString& s){
	str = new char[s.__size];
	__size = s.__size;
	__length = s.__length;
	memcpy(str, s.str, __size);
}

xxzString::xxzString(const char & c){
	__size = 16;
	str = new char[16];
	__length = 1;
	str[0] = c;
	str[1] = 0;
}

xxzString::xxzString(const char* c){
	__size = 16;
	str = new char[16];
	int j = 0;
	while (str[__length++] = c[j++]){
		if (__length < __size - 2){
			extend();
		}
	}
}



bool xxzString::operator==(const xxzString& s)const{
	if (s.__size != __size){
		return false;
	}
	for (int i = 0; i < __size; i++){
		if (str[i] != s.str[i]){
			return false;
		}
	}
	return true;
}

bool xxzString::operator==(const char* s)const{
	for (int i = 0; s[i] * str[i] != 0; i++){
		if (str[i] != s[i]){
			return false;
		}
	}
	return true;
}

xxzString& xxzString::operator=(const xxzString& s){
	str = new char[s.__size];
	__size = s.__size;
	__length = s.__length;
	memcpy(str, s.str, __size);
	return *this;
}

xxzString& xxzString::operator+=(const xxzString& str){
	int tmp = str.__length + __length;
	while (tmp >= __size - 2){
		extend();
	}
	int j = 0;
	while ((this->str)[__length++] = str[j++]);
	//remove the length of \0
	__length--;
	return *this;
}



std::istream& operator>>(std::istream& cin, xxzString& s){

	s.__length = 0;
	char c;
	/* make full use of iostream
	//remove spaces
	while (!cin.eof() && isSpace(cin.peek()) && cin.get());
	//read the next word
	*/
	cin >> c;
	do{
		s.str[s.__length++] = c;
		if (s.__length >= s.__size - 2){
			s.extend();
		}
	} while (!cin.eof() && !isSpace(cin.peek()) && !isEnd(cin.peek()) && cin.get(c));
		
	/* make full use of iostream
	//remove spaces
	while (!cin.eof() && isSpace(cin.peek()) && cin.get());
	*/
	s.str[s.__length] = 0;
	return cin;
}

std::ostream& operator<<(std::ostream& os, xxzString& s){
	return os << s.str;

}

