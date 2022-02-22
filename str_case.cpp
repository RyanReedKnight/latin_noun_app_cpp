#include"str_case.h"
#include<string>
#include<ctype.h>

using std::string;	using std::toupper;	using std::tolower;

typedef string::size_type str_sz;
typedef string::iterator str_itr;

// Takes string reference as argument, capitalizes first character of string
// and makes following characters lowercase, changes string.
void capitalize_void(string& str) {
	str_itr itr = str.begin();
	*itr = toupper(*itr);
	
	for (itr = str.begin() + 1; itr != str.end(); ++itr)
		*itr = tolower(*itr);
}

// Takes string as an argument and returns a capitalized copy of that string.
string capitalize_str(string str) {
	capitalize_void(str);
	return str;
}
void str_tolower(string& str) {
	str_itr itr;
	for (itr = str.begin(); itr != str.end(); ++itr)
		*itr = tolower(*itr);
}
string str_tolower_rtn(string str) {
	str_tolower(str);
	return str;
}