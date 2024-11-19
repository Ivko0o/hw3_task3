#include <iostream>
#include <string>
#include <new>

//This program will take a random text and count the number of words in it and separate the different numbers by count

using namespace std;

void UserInput(string& text);
void SplitText(string text, char ch, string wordsArray[], int& countWords);

int main()
{
	string text = "";
	char ch = ' ';
	int countWords = 0;


	UserInput(text);
	string* wordsArray = new string[text.size()];		//This creates the array which will be used to store the different words
	SplitText(text, ch, wordsArray, countWords);

	for (int a = 0; a < countWords; a++) {
		cout << wordsArray[a] << endl;
	}

	delete[] wordsArray;
}

//This will be used to input the text by the user.
void UserInput(string& text) {

	cout << "Enter a random text so you can check the following: " << endl;
	cout << "1. The total number of words in it" << endl;
	cout << "2. How many distinct words are there in the text" << endl;
	cout << "3. How many times the different words appear in the text." << endl << endl;
	cout << "Enter # to stop!" << endl;

		getline(cin, text, '#');

}

bool IsDelimiter(char ch) {
	return (ch == '!' || ch == '@' || ch == '$' || ch == '%' || ch == '^' || ch == '&' || ch == '*' || ch == '\n' || ch == '\t' || ch == ' ' || ch == '.' || ch == ',');
}

//This function will seprate the whole text word by word
void SplitText(string text, char ch, string wordsArray[], int& countWords) {

	string tempWord = "";

	//This will be used to save the separate words
	for (int i = 0; i < text.size(); i++) {
		if (!IsDelimiter(text[i])) {
			tempWord += text[i];

		}
		else {
			if (!tempWord.empty()) {
				wordsArray[countWords] = tempWord;
				tempWord = "";
				countWords++;
			}
			else {
				continue;
			}
		}

		//This adds the last word of the text to the array
		if (!tempWord.empty()) {
			wordsArray[countWords + 1] = tempWord;
		}
	}
}