#include <iostream>
#include <string>
#include <new>

//This program will take a random text and count the number of words in it and separate the different numbers by count

using namespace std;

void UserInput(string& text);
void SplitText(string text, char ch);

int main()
{
	string text = "";
	char ch = ' ';
	string* wordsArray = new string[20000];
	UserInput(text);
	SplitText(text, ch);

	delete[] wordsArray;
}

//This will be used to input the text by the user.
void UserInput(string& text) {

	cout << "Enter a random text so you can check the following: " << endl;
	cout << "1. The total number of words in it" << endl;
	cout << "2. How many distinct words are there in the text" << endl;
	cout << "3. How many times the different words appear in the text." << endl << endl;
	cout << "Enter # to stop!" << endl;

	char entryStop = '#';		// This will be used to stop the input
	while (true) {
		getline(cin, text);
	}
}

//This function will seprate the whole text word by word
void SplitText(string text, char ch) {

	string tempWord = "";
	int countWords = 0;
	string wordArray[20];			//This array will store the words

	int j = 0;						//Needed to store the words in the array

	//This will be used to save the separate words
		for (int i = 0; i < text.size(); i++) {
				if (text[i] != ch) {
					tempWord += text[i];

				}
				else {
					wordArray[j] = tempWord;
					tempWord = "";
					j++;

				}
		}

		for (int a = 0; a < 20; a++) {
			cout << wordArray[a] << endl;
	}
}
