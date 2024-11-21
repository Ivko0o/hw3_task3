#include <iostream>
#include <string>
#include <new>

//This program will take a random text and give feedback on the number of words in it and separate the different numbers by count

using namespace std;

void UserInput(string& text);
int CountWords(const string& text);
void SplitText(const string& text, string wordsArray[]);
int CountDistinctWords(string wordsArray[], int countWords);
void UniqueWord(string wordsArray[], string distinctWordsArray[], int countWords);
char toLower(char ch);

int main()
{
	string text = "";

	UserInput(text);

	int countWords = CountWords(text);										//This function counts the words in the text
	string* wordsArray = new string[countWords];							//This creates the array which will be used to store the different words

	SplitText(text, wordsArray);
	
	int distinctWords = CountDistinctWords(wordsArray, countWords);			//This will be used to create the array with the distinct words
	string* distinctWordsArray = new string[distinctWords];     

	UniqueWord(wordsArray, distinctWordsArray, countWords);

	for (int i = 0; i < distinctWords; i++) {
		cout << distinctWordsArray[i] << endl;
	}

	delete[] wordsArray;
	delete[] distinctWordsArray;
}

//This will be used to input the text by the user.
void UserInput(string& text) {

	cout << "Enter a random text so you can check the following: " << endl;
	cout << "1. The total number of words in it" << endl;
	cout << "2. How many distinct words are there in the text" << endl;
	cout << "3. How many times the different words appear in the text." << endl << endl;
	cout << "Enter # to stop!" << endl;

		getline(cin, text, '#');

		cout << endl;

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
			tempWord += toLower(ch);
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

	cout << "The number of words in the text is: " << countWords << endl;;
	return countWords;
}

//This function will seprate the whole text word by word
void SplitText(const string& text, string wordsArray[]) {
	string tempWord = "";
	int j = 0;

	for (char ch : text) {
		if (!IsDelimiter(ch)) {
			tempWord += toLower(ch);
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

//This function will check how many distinct words are there in the text
int CountDistinctWords(string wordsArray[], int countWords) {
	
	int distinctWords = 1;
	
	//This iterates through the array to compare the words - e.g - it compares the 2nd word to the 1st word, after that the 3rd to the 2nd and 1st, etc.
	for (int i = 1; i < countWords; i++) {
		int j = 0;
		int iterations = 0;

		while (j != i) {
			if (wordsArray[i] != wordsArray[j]) {
				iterations++;
			}
			j++;
		}

		if (iterations == i) {
			distinctWords++;
		}
	}

	cout << "The number of distinct words in the text is: " << distinctWords << endl;

	return distinctWords;

}

//This function will seprate the distinct words in an array
void UniqueWord(string wordsArray[], string distinctWordsArray[], int countWords) {
	int k = 0;
	//This accepts that the first word of the text is distinct
	distinctWordsArray[k] = wordsArray[0];

	for (int i = 1; i < countWords; i++) {

		bool isDistinct = true;
		int j = 0;

		while (j != i) {

			if (wordsArray[i] == wordsArray[j]) {
				isDistinct = false;
				break;
			}

			j++;
		}


		if (isDistinct) {
			++k;
			distinctWordsArray[k] = wordsArray[i];
		}
	}
	

}


//This function will make sure that it does make a difference between upper and lower case letters in the text
char toLower(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return ch + ('a' - 'A');
	}
	return ch;
}