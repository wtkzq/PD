#ifndef _DICT_H_
#define _DICT_H_

#include <string>
using std::string;
class dict
{
private:
	string file_name;
public:
	dict(string fn):file_name(fn) {};
	dict():file_name(""){};
	string get_name(){return file_name;};
};

#endif	
