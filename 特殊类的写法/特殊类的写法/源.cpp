#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class StackOnly{
public:
	StackOnly(){}
	~StackOnly(){}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};
class HeapOnly{
public:
	static HeapOnly* Create()
	{
		return new HeapOnly;
	}
private:
	//禁用构造与拷贝构造
	HeapOnly(){}
	HeapOnly(const HeapOnly& h) = delete;
};
class CopyBan{
public:
	//禁用拷贝构造和赋值运算法
	CopyBan(const CopyBan& c) = delete;
	CopyBan& operator=(const CopyBan& c) = delete;
};
class InheritBan final{

};
int main()
{

	system("pause");
	return 0;

}