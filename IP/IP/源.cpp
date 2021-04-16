#include <iostream>
#include <string>
#include <vector>
using namespace std;
void IPtoINT(string s)
{
	s += ".";
	vector<string> res;
	const char *delim = ".";
	char *str = new char[strlen(s.c_str()) + 1];
	strcpy(str, s.c_str());
	string token = strtok(str, delim);
	while (!token.empty())
	{
		res.push_back(token);

	}

}
int IPTOint(string s)
{
	//192.168.1.1
	vector<int> IP;
	int pos1 = 0;
	int pos2 = 0;
	pos2 = s.find(".");
	while (pos2 != string::npos)
	{
		string tmp = s.substr(pos1, pos2 - pos1);
		IP.push_back(stoi(tmp));
		pos1 = pos2 + 1;
		pos2 = s.find(".", pos1);
	}
	IP.push_back(stoi(s.substr(pos1, pos2 - pos1)));
	int res = IP[0] * 256 * 256 * 256 + IP[1] * 256 * 256 + IP[2] * 256 + IP[3];
	return res;
}
string INtoIP(int ip)
{
	//提取第四部分IP
	string addr4 = to_string(ip % 256);
	ip /= 256;
	string addr3 = to_string(ip % 256);
	ip /= 256;
	string addr2 = to_string(ip % 256);
	ip /= 256;
	string addr1 = to_string(ip % 256);
	ip /= 256;
	string IP = addr1 + "." + addr2 + "." + addr3 + "." + addr4;
	return IP;
}
int main()
{
	cout << IPTOint("10.0.3.193") << endl;
	cout << INtoIP(IPTOint("10.0.3.193")) << endl;
	return 0;
}