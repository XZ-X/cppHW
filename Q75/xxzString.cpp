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


xxzString& xxzString::operator=(const xxzString& s){
	str = new char[s.__size];
	__size = s.__size;
	__length = s.__length;
	memcpy(str, s.str, __size);
	return *this;
}


std::istream& operator>>(std::istream& cin, xxzString& s){

	s.__length = 0;
	char c;
	//remove spaces
	while (!cin.eof() && isSpace(cin.peek()) && cin.get());
	//read the next word

	while (!cin.eof() && !isSpace(cin.peek()) && !isEnd(cin.peek()) && cin.get(c)){
		s.str[s.__length++] = c;
		if (s.__length >= s.__size - 2){
			s.extend();
		}
	}

	//remove spaces
	while (!cin.eof() && isSpace(cin.peek()) && cin.get());
	s.str[s.__length] = 0;
	return cin;
}

std::ostream& operator<<(std::ostream& os, xxzString& s){
	return os << s.str;
	
}

