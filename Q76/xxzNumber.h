#ifndef xxz_number_h
#define xxz_number_h
#include <iostream>
#include"list.h"
class xxzNumber{
private:
	list<int> data;
	void initial();
public :
	//constructor
	xxzNumber();
	
	

	//operator
	xxzNumber operator+(xxzNumber& b);
	xxzNumber operator-(xxzNumber& b);


	//friend
	friend std::ostream& operator<<(std::ostream& cout, const xxzNumber& num);
	friend std::istream& operator>>(std::istream& cin, xxzNumber& num);

};


#endif