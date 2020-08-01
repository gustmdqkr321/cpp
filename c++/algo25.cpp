#include<iostream>
#include<cstdio>
#include<string>
#include<bitset>
#include<fstream>
using namespace std;

class Hamming {
private:
	int result; //mod=0이면 해밍코드, 1이면 복호코드

	string toBinaryString(int num, int mod) {
		return bitset<32>(num).to_string();;
	}

	void toDecimalInteger(string binary) {
		result = bitset<32>(binary).to_ulong();;
	}

	void toHammingCode(string binary) {
		string hammingCode;
		int i, len = binary.length(), hammingLen, cur = len - 1, numberOfOne;
		for (i = 1; i < 32; i++) {
			if (i == 1 || i == 2 || i == 4 || i == 8 || i == 16)
                hammingCode.insert(0, 1, 'p');
			else hammingCode.insert(0, 1, binary[cur--]);
		}

		hammingLen = hammingCode.length();

		for (i = 1; i <= 16; i <<= 1) {
			numberOfOne = checkBits(hammingCode, i);
			hammingCode[hammingLen - i] = (numberOfOne % 2 ? '1' : '0');
		}

		toDecimalInteger(hammingCode);
	}

	void toOriginalCode(string binary) {
		int i, k = 0, numberOfOne, numberOfError = 0;
        int errorParityBit[5]={ 0 }, errorBit=0, binaryLen=binary.length();
		string origin;
		for (i = 1; i <= 16; i <<= 1) {
			numberOfOne = checkBits(binary, i);
			if (numberOfOne % 2) {
				numberOfError++;
				errorParityBit[k++] = i;
			}
		}

		if (numberOfError > 1) {
			for (i = 0; i < 5; i++) errorBit += errorParityBit[i];
			binary[binaryLen - errorBit] = '1';
		}

		for (i = 1; i < binaryLen; i++)
			if (!(i == 1 || i == 2 || i == 4 || i == 8 || i == 16))
				origin.insert(0, 1, binary[binaryLen - i]);

		toDecimalInteger(origin);
	}

	int checkBits(const string &hammingCode, int gap) {
		int i, numberOfOne = 0, len = hammingCode.length();
        int start = len - gap, checked = 0;

		for (i = start; i >= 0; i--) {
			if (hammingCode[i] == '1') numberOfOne++;
			checked++;
			if (checked == gap) {
				checked = 0;
				i -= gap;
			}
		}

		return numberOfOne;
	}

public:
	Hamming(int mod, int num) {
		if (mod) toOriginalCode(toBinaryString(num, mod));
		else toHammingCode(toBinaryString(num, mod));
	}
	int getResult() {
		return result;
	}
};

int main() {
	int t, mod, num;
  cin >> t;
	while (t--) {
		cin >> mod >> num;
		Hamming hamming(mod, num);
		printf("%d\n", hamming.getResult());
	}
}
