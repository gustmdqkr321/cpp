#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

class ISBN{
    vector <string> isbn;

    void splitToVector(string line){
	size_t pos = 0;
	while((pos = line.find("-"))!=string::npos){
	    isbn.push_back(line.substr(0, pos));
	    line.erase(0, pos+1);
	}
	isbn.push_back(line);
    }

    bool isSplittedToFourth(){
	return isbn.size()==4;
    }

    bool isEachDivCorrect(){
	return isNumeric(isbn[0], 5)&&isNumeric(isbn[1], 7)&&isNumeric(isbn[2], 6)&&isNumeric(isbn[3], 1, true);
    }

    bool isNumeric(string line, int maxLen, bool isSpecialCase=false){
	int i, len = line.length();
	if(len>maxLen || len<=0) return false;
	if(isSpecialCase && !line.compare("X")) return true;
	for(i=0;i<len;i++)
	    if('9'<line[i] || line[i]<'0') return false;
	return true;
    }

    bool isCorrectChecksum(){
	string allNumber = (isbn[0]+isbn[1]+isbn[2]);
	if((allNumber+isbn[3]).length()>10) return false;
	int i, sum = 0, checksum = (isbn[3][0]=='X' ? 10 : isbn[3][0]-48);
	for(i=0;i<9;i++) sum+=(allNumber[i]-48)*(10-i);
	sum+=checksum;
	return !(sum%11);
    }
public:
    ISBN(string line){
	splitToVector(line);
	if(isSplittedToFourth()&&isEachDivCorrect()&&isCorrectChecksum())
	    puts("1");
	else
	    puts("0");
    }
};

int main(){

    int t;
    cin >> t;
    string line;
    while(t--){
	cin >> line;
	ISBN isbn(line);
    }
}
