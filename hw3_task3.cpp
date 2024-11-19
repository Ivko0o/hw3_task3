#include <iostream>
#include <string>
#include <new>

//This program will take a random text and count the number of words in it and separate the different numbers by count

using namespace std;

void UserInput(string& text);
int CountWords(const string& text);
void SplitText(const string& text, string wordsArray[]);

int main()
{
	string text = "";

	UserInput(text);
	int countWords = CountWords(text);						//This function counts the words in the text
	string* wordsArray = new string[countWords];			//This creates the array which will be used to store the different words
	SplitText(text, wordsArray);							//This function will seprate the words and save them in the created array

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

//These symbols will be used as delimiters
bool IsDelimiter(char ch) {
	return (ch == '?' || ch == '!' || ch == '@' || ch == '$' || ch == '%' || ch == '^' || ch == '&' 
		|| ch == '*' || ch == '\n' || ch == '\t' || ch == ' ' || ch == '.' || ch == ',' || ch == '\0'
		);
}

//This will first calculate the number of words in the text before the array is allocated
int CountWords(const string& text) {

	string tempWord = "";
	int countWords = 0;
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
	//This covers the last word if there is no delimiter after it
	if (!tempWord.empty())
		countWords++;

	cout << "The number of words in the text is: " << countWords;
	return countWords;
}

//This function will seprate the whole text word by word
void SplitText(const string& text, string wordsArray[]) {
	string tempWord = "";
	int j = 0;

	for (char ch : text) {
		if (!IsDelimiter(ch)) {
			tempWord += ch;
		}
		else {
			if (!tempWord.empty()) {
				wordsArray[j] = tempWord;
				tempWord = "";
				j++;
			}
			else {
				continue;
			}
		}
		//This adds the last word of the text to the array
		if (!tempWord.empty()) {
			wordsArray[j] = tempWord;
		}
	}
}