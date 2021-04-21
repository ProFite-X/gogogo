#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class mystring{
private:
	char* _str;
public:
	//构造函数
	mystring(const char* str = "")
	{
		cout << "构造函数" << endl;
		if (str == nullptr)
		{
			//字符串为空
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//拷贝构造函数
	mystring(const mystring& s)
	{
		cout << "拷贝构造函数" << endl;
		mystring tmp(s);
		swap(tmp._str, _str);
	}
	//移动构造构造函数
	mystring(mystring&& s)
	{
		cout << "移动构造函数" << endl;
		_str = s._str;
		cout << _str << endl;
		s._str = nullptr;
	}
	//赋值运算符重载
	mystring& operator=(const mystring& s)
	{
		cout << "赋值运算符重载" << endl;
		mystring tmp(s);
		swap(_str, tmp._str);
		return *this;
	}
	//移动赋值运算符重载
	mystring& operator=(mystring&& s)
	{
		cout << "移动赋值函数" << endl;
		_str = s._str;
		s._str = nullptr;
		cout << _str << endl;
		return *this;
	}
	mystring operator+(const mystring& s)
	{
		char* tmp = new char[strlen(s._str) + strlen(_str) + 1];
		strcpy(tmp, _str);
		strcat(tmp, s._str);
		mystring res(tmp);
		delete[] tmp;
		return res;
	}
	//析构函数
	~mystring()
	{
		cout << "析构函数" << endl;
		if (_str != nullptr)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
};
int main()
{
	mystring s1("abc");
	mystring s2("def");
	mystring s3;
	s3 = s1 + s2;
	system("pause");
	return 0;
	
}