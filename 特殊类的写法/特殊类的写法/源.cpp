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
	//���ù����뿽������
	HeapOnly(){}
	HeapOnly(const HeapOnly& h) = delete;
};
class CopyBan{
public:
	//���ÿ�������͸�ֵ���㷨
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