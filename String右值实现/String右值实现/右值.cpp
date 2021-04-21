#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class mystring{
private:
	char* _str;
public:
	//���캯��
	mystring(const char* str = "")
	{
		cout << "���캯��" << endl;
		if (str == nullptr)
		{
			//�ַ���Ϊ��
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//�������캯��
	mystring(const mystring& s)
	{
		cout << "�������캯��" << endl;
		mystring tmp(s);
		swap(tmp._str, _str);
	}
	//�ƶ����칹�캯��
	mystring(mystring&& s)
	{
		cout << "�ƶ����캯��" << endl;
		_str = s._str;
		cout << _str << endl;
		s._str = nullptr;
	}
	//��ֵ���������
	mystring& operator=(const mystring& s)
	{
		cout << "��ֵ���������" << endl;
		mystring tmp(s);
		swap(_str, tmp._str);
		return *this;
	}
	//�ƶ���ֵ���������
	mystring& operator=(mystring&& s)
	{
		cout << "�ƶ���ֵ����" << endl;
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
	//��������
	~mystring()
	{
		cout << "��������" << endl;
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