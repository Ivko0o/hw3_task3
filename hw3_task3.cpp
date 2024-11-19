#include <iostream>
#include <string>
#include <new>

//This program will take a random text and count the number of words in it and separate the different numbers by count

using namespace std;

void UserInput(string& text);
void CountWords(int& countWords, string text);
void SplitText(string text, string wordsArray[], int& countWords);

int main()
{
	string text = "";
	int countWords = 0;

	UserInput(text);
	CountWords(countWords, text);
	cout << countWords;
	string* wordsArray = new string[countWords];		//This creates the array which will be used to store the different words
	SplitText(text, wordsArray, countWords);

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
	return (ch == '?' || ch == '!' || ch == '@' || ch == '$' || ch == '%' || ch == '^' || ch == '&' 
		|| ch == '*' || ch == '\n' || ch == '\t' || ch == ' ' || ch == '.' || ch == ',' || ch == '\0'
		);
}

//This will first calculate the number of words in the text before the array is allocated
void CountWords(int& countWords, string text) {

	string tempWord = "";

	for (char ch : text) {
		if (!IsDelimiter(ch)) {
			tempWord += ch;
		}
		else {
			if (!tempWord.empty()){
				countWords++;
				tempWord = "";
			}
		}
	}
	//This covers the last letter if there is no delimiter
	if (!tempWord.empty())
		countWords++;
}

//This function will seprate the whole text word by word
void SplitText(string text, string wordsArray[], int& countWords) {

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