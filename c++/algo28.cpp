#include<iostream>
#include<fstream>
#include<string>
#include<bitset>
#include<cstdio>
#include<cmath>
using namespace std;

typedef unsigned int uint;

class IP {
	string ip;
	uint dec;

	void parseInt(const string &ip) {
		string strDec, tmp;
		int i, n = ip.length();
		for (i = 0; i < n; i++) {
			if (ip[i] != '.') tmp += ip[i];
			else {
				strDec += bitset<8>(myStoi(tmp)).to_string();
				tmp.clear();
			}
		}
		strDec += bitset<8>(myStoi(tmp)).to_string();
		dec = bitset<32>(strDec).to_ulong();
	}

	int myStoi(string num) {
		int res = 0, i, n = num.length();
		for (i = 0; i < n; i++)
			res += int(pow(10, n - i - 1))*(num[i] - 48);
		return res;
	}

	string toString(int num) {
		if (!num) return "0";
		string res;
		char ch;
		while (num) {
			ch = (num % 10) + 48;
			num /= 10;
			res = ch + res;
		}
		return res;
	}

	void toBinaryString(const uint &dec) {
		string tmp = bitset<32>(dec).to_string();
		for (int i = 0; i <= 24; i += 8)
			ip += toString(bitset<8>(tmp.substr(i, i + 8)).to_ulong()) + ".";
		ip.erase(ip.length() - 1);
	}
public:
	IP(int a) {
		int k;
    cin >> k;
		if (k == 1) {
			cin >> ip;
			parseInt(ip);
			printf("%u\n", dec);
		}
		else {
			cin >> dec;
			toBinaryString(dec);
			puts(ip.c_str());
		}
	}
};

int main() {
	int t;
  cin >> t;
	while (t--) IP ip(t);
}
