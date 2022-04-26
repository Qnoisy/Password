#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

class Password {
private:
	string letters = "abcdefgABCDEFG";
	string number = "1234567890";
	string specialChar = "@#$%&";
	bool key = true;
	bool keyNumber = true;
	vector <string> password;
	int sizeVec = 16;
	int brain = 2;
public:
	Password() {
		cout << "create password? \n-> '1'  yes\n-> '2' no\n";
		int value = 0;
		int size = 0;
		cin >> value;
		cout << "do you want to change the password size? according to standard '16'.\n-> '1'  yes\n-> '2' no\n";
		cin >> size;
		if (size == 1) {
			int sizeVec = 0;
			cout << "enter size vector: ";
			cin >> sizeVec;
			setSizePass(sizeVec);
		}
		if (value == 1) {
			brainProgram();
		}
		else if (value == 2) {
			cout << "error";
		}
	}
	void brainProgram() {
		for (int i = 0; i < this->sizeVec; i++){
			if (rand() % brain + 1 == 2 && this->keyNumber == true) {
				this->brain = 1;
				this->keyNumber = false;
			if (rand() % 2 + 1 == 1 && this->key == true) {
				this->password.push_back(setPasSpecialChar());
				this->key = false;
			}else { this->password.push_back(setPassNumber()); }
			}else { this->password.push_back(setPassletters()); }
			if (i % 4 == 0 && i != 0) {
				this->brain = 2;
				this->keyNumber = true;}
		}
	}
	void setSizePass(int sizeVec) {
		this->sizeVec = sizeVec;
	}
	string setPassletters() {
		string value;
		value = this->letters[rand() % this->letters.size()];
		return value;
	}
	string setPassNumber() {
		string value;
		value = this->number[rand() % this->number.size()];
		return value;
	}
	string setPasSpecialChar() {
		string value;
		value = this->specialChar[rand() % this->specialChar.size()];
		return value;
		
	}
	void PassShow() {
		cout << "Your Password: ";
		for (int i = 0; i < this->sizeVec; i++){
			//if (i % 4 == 0 && i != 0) {
			//	cout << " ";
			//}
			cout << password[i];
		}
	}
	~Password() {
		cout << "\nclass is delete" << endl;
	}
};
int main(){
	srand(time(0));
	Password* obj = new Password();
	obj->PassShow();
	obj->~Password();
}