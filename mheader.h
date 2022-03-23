#ifndef MHEADER_H
#define MHEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;
void inputUpload();
void paraphrasing();
string text;
string targetWord;
string theWord;

void paraphrasing() {
	if (text.find(targetWord) != string::npos) {
		//replace the target words with the word specified
		text = regex_replace(text, std::regex(targetWord), theWord);
		cout << text << endl;
		// creating the output file
		ofstream outfile("output.txt");
		outfile << text << std::endl;
		outfile.close();
	}
	else {
		cout << "Couldn't find the target word in the text" << "\n";
	}
}
void inputUpload() {
	cout << "Paste the text:" << "\n";
	cin.ignore();
	getline(cin, text);
	cout << "The word you want to paraphrase:" << "\n";
	getline(cin, targetWord);
	cout << "The word you want to change it with:" << "\n";
	getline(cin, theWord);
	paraphrasing();
}
void fileUpload() {
	string filePath;
	cout << "Paste the file location:" << "\n";
	cin.ignore();
	// get the file path
	getline(cin, filePath);
	ifstream file(filePath);
	string line;
	// read the file and convert it into the my beloved "text" string
	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			text.append(line);
			text.append("\n");
		}
	}
	file.close();
	cout << "The word you want to paraphrase:" << "\n";
	getline(cin, targetWord);
	cout << "The word you want to change it with:" << "\n";
	getline(cin, theWord);
	paraphrasing();
}


#endif