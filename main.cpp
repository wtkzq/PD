#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "dict.h"

const char *version = "0.1.0";
void init();
void main_loop();
void print_help();
std::vector<std::string> stringSplit(const std::string& str, char delim);
int main(int argc,char * argv[])
{
	init();
	main_loop();
	std::cout << "exit" << std::endl;
	return 0;
}
void init()
{
	using namespace std;
	cout << "PD " << version << " " << endl;
	cout << "键入\"help\"以获取帮助" << endl;
}
void main_loop()
{
	using namespace std;
	dict this_dict;
	string cmd;
	vector<string> cmdv;
	do
	{
		cout << "\033[32m" << this_dict.get_name() << "> \033[0m";
		getline(cin, cmd);
		cmdv = stringSplit(cmd, ' ');
		if (cmdv[0] == "help")
		{
			print_help();
		}
		else if (cmdv[0] == "exit")
		{
			break;
		}
		else if (cmdv[0] == "load_dict")
		{
			if (cmdv.size() == 2)
			{
				this_dict=cmdv[1];
			}
			else
			{
				cout << "\033[31m参数错误。\033[0m" << endl;
			}
		}
		else cout << "\033[31m命令未找到。\033[0m" << endl;
	}
	while (true);
}
std::vector<std::string> stringSplit(const std::string& str, char delim) {
	std::stringstream ss(str);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, delim))
		if (!item.empty())
			elems.push_back(item);
	return elems;
}
void print_help()
{
	using namespace std;
	cout << "PD " << version << endl;
	cout << "命令列表:" << endl;
	cout << "help\t获取帮助" << endl;
	cout << "exit\t从PD中退出" << endl;
}
