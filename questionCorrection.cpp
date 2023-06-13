#include <iostream>

using namespace std;


bool isLetterOrNum(char c){
	// This function return true if the input is an number or letter
	// Otherwise, it return false
	if (c >= 'a' && c <= 'z')	return true;
	else if (c >= 'A' && c <= 'Z')	return true;
	else if (c >= '0' && c <= '9')	return true;
	else return false;
}decltype;


bool isCharValid(char c){
	//	This function return true if the input satisfy the common rules
	if (c >= 'a' && c <= 'z')	return true;
	else if (c >= 'A' && c <= 'Z')	return true;
	else if (c >= '0' && c <= '9')	return true;
	else if (c == ' ' || c == '?' || c == ',')	return true;
	else return false;
}

string questionCorrection(string ques){
	// Replace all invalid char to space
	for (int i = 0; i < ques.length(); i++){
		if (isCharValid(ques[i]) == false){
			ques[i] = ' ';
		}

		// If '?' is not locate at last sentence, replace it by space
		if (ques[i] == '?' && i < ques.length() - 1)
			ques[i] = ' ';
	}

	//	Check if the first character valid or not
	while (ques[0] == ' ' || ques[0] == ','){
		ques.erase(0,1);
	}

	//	Check the first letter, convert to uppercase if it is lowercase
	if (ques[0] >= 'a' && ques[0] <= 'z'){
		ques[0] -= 32;
	}

	// Check if there are more than 1 space next to each other
	for (int i = 1; i < ques.length(); i++){
		if (ques[i] == ' '){
			int tmp = 1;
			int count = 0;
			while (ques[i+tmp] == ' '){
				count++;
				tmp++;
			}
			ques.erase(i+1,count);
		}
	}

	// Check if there are more than 1 comma next to each other
	for (int i = 1; i < ques.length(); i++){
		if (ques[i] == ','){
			int tmp = 1;
			int count = 0;
			while (ques[i+tmp] == ','){
				count++;
				tmp++;
			}
			ques.erase(i+1,count);
		}
	}

	// Delete ' ' if it located at last of sentences
	if (ques[ques.length()-1] == ' ')	ques.erase(ques.length()-1, 1);

	// ========= Comma Rules ========== //

	// Check that there must be 1 letter or number before comma
	for (int i = 1; i < ques.length(); i++){
		if (ques[i] == ','){
			int k = 1;
			int count = 0;
			while (ques[i-k] == ' ' || ques[i-k] == ','){
				count++;
				k++;
			}
			ques.erase(i - count,count);
		}
	}

	// There must be 1 space and 1 letter or number right after comma
	for (int i = 1; i < ques.length(); i++){
		if (ques[i] == ',' && isLetterOrNum(ques[i+1]) == true)
			ques.insert(i+1, " ");
	}

	// delete ',' if it located at last
	if (ques[ques.length() -1] == ',')
		ques.erase(ques.length()-1,1);

	// lowercase 
	for (int i = 1; i < ques.length(); i++){
		if (ques[i] <= 'Z' && ques[i] >= 'A'){
			ques[i] += 32;
		}
	}

	// adding '?' in the last of sentence
		while (ques[ques.length()-1] == ',' || ques[ques.length()-1] == '?')	ques.erase(ques.length()-1,1);
		ques = ques.append("?");

		if (ques[ques.length()-2] == ' ') ques.erase(ques.length()-2,1);


	return ques;
}

int main(){
	string question;
	cout << "Enter your question: ";
	getline(cin, question);
	cout << "Your question after standardized: ";
	cout << questionCorrection(question) << endl;
	return 0;
}
