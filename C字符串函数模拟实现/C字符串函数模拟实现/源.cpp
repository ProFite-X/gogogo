#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;
//����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination�ڴ��λ��
void* my_memcpy(void* destination, const void* source, size_t num)
{
	assert(destination && source);
	char* dst_ = (char*)destination;
	char* sou_ = (char*)source;
	//��ʼ����n���ַ�
	for (size_t i = 0; i < num; i++)
	{
		dst_[i] = sou_[i];
	}
	return dst_;
}
//memmove��memcpy�������ǣ�memmove������ڴ��ص����⡣
//��source < destation < source + num������ص����Ӻ���ǰ����
void* my_memmove(void* destinaton, const void* sourse, size_t num)
{
	char* des = (char*)destinaton;
	const char* sou = (const char*)sourse;
	if (des > sou && des < sou + num)
	{
		//�Ӻ���ǰ����
		for (int i = num - 1; i >= 0; i--)
		{
			des[i] = sou[i];
		}
	}
	else
	{
		//��ǰ������п���
		for (int i = 0; i < num; i--)
		{
			des[i] = sou[i];
		}
	}
	return des;
}
//�Ƚ�ptr1��ptr2��ʼ��ǰnum���ֽ�

int my_memcmp(const void* ptr1, const void* ptr2, size_t num)
{
	assert(ptr1 && ptr2);
	const char* p1 = (char*)ptr1;
	const char* p2 = (char*)ptr2;
	while (num && *p1 != '\0' && *p2 != '\0')
	{
		if (*((unsigned char*)p1) < *((unsigned char*)p2))
		{
			return 1;
		}
		else if (*((unsigned char*)p1) > *((unsigned char*)p2))
		{
			return -1;
		}
		else
		{
			p1++;
			p2++;
			num--;
		}
	}
	if (num == 0)
	{
		return 0;
	}
	if (*p1 == '\0')
	{
		return -1;
	}
	if (*p2 == '\0')
	{
		return 1;
	}
}
//
size_t my_strlen(const char* str)
{
	assert(str);
	size_t count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}
//
char* my_strcpy(char* destination, const char* source)
{
	assert(destination && source);
	char* des = destination;
	const char* sou = source;
	char* ret = des;
	while (*sou)
	{
		*des = *sou;
		des++;
		sou++;
	}
	//����\0
	*des = '\0';
	return ret;
}
//
char* my_strcat(char* destination, const char* source)
{
	assert(destination && source);
	char* des = destination;
	const char* sou = source;
	char* ret = des;
	while (*des != '\0')
	{
		des++;
	}
	while (*des++ = *sou++);
	return ret;
}
int my_strcmp(const char*  str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*(unsigned char*)str1 > *(unsigned char*)str2)
		{
			return 1;
		}
		else if (*(unsigned char*)str1 > *(unsigned char*)str2)
		{
			return -1;
		}
		else
		{
			str1++;
			str2++;
		}
	}
	if (*str1 != '\0')
	{
		return 1;
	}
	if (*str2 != '\0')
	{
		return -1;
	}
	return 0;
}
//
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 != '\0')
	{
		if (*str1 == *str2)
		{
			const char* begin = str1;
			while (*begin && *str2 && *begin == *str2)
			{
				begin++;
				str2++;
			}
			if (*str2 == '\0')
			{
				return (char*)str1;
			}
		}
		str1++;
	}
	return nullptr;
}
int main()
{
#if 0
	//memcpy
	char dest[1024];
	char* sou = "123456789";
	my_memcpy(dest, sou, 10);
	cout << "my_memcpy result is: " << dest << endl;
	my_memmove
	my_memmove(sou + 2, sou, 5);
	cout << "my_memmove result is:" << dest << endl;
	cout << "my_memmove result is:" << my_memcmp("123", "1234", 4) << endl;
	cout << my_strlen("123456789") << endl;
	//
	char dest[5] = "1234";
	char* sou = "5";
	cout << my_strcat(dest, sou) << endl;
	char sou[1024] = "123456789";
	char *res = (char*)(my_memmove(sou + 2, sou, 5));
	cout << "my_memmove result is:" << *res << endl;
	//
#endif
	char* res = my_strstr("123456789", "456");
	cout << res << endl;
	system("pause");
	return 0;
	
}