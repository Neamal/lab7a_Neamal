// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int result = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		for (size_t k = 0; k < table[i].size(); k++) {
			result += table[i][k].second;
		}
	}
	return result;
}

int WordCount::getNumUniqueWords() const {
	int result = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		for (size_t j = 0; j < table[i].size(); j++) {
			result += 1;
		}
	}
	return result;
}

int WordCount::getWordCount(std::string word) const {
	string newWord = makeValidWord(word);
	int target = hash(newWord);
	if (newWord == "") {
		return 0;
	}
	for (size_t i = 0; i < table[target].size(); i++) {
		if (table[target][i].first == newWord) {
			return table[target][i].second;
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	string newWord = makeValidWord(word);
	int target = hash(newWord);
	if (newWord == "") {
		return 0;
	}
	for (size_t i = 0; i < table[target].size(); i++) {
		if (table[target][i].first == newWord) {
			table[target][i].second++;
			return table[target][i].second;
		}
	}
	pair<string, int> insert;
	insert.first = newWord;
	insert.second = 1;
	table[target].push_back(insert);
	return insert.second;
}

int WordCount::decrWordCount(std::string word) {
	string newWord = makeValidWord(word);
	int target = hash(newWord);
	if (newWord == "") {
		return 0;
	}
	for (size_t i = 0; i < table[target].size(); i++) {
		if (table[target][i].first == newWord) {
			if (table[target][i].second > 1) {
				table[target][i].second--;
				return table[target][i].second;
			}
			if (table[target][i].second == 1) {
				table[target].erase(table[target].begin() + i);
				return 0;
			}
		}
	}
	return -1;
}

bool WordCount::isWordChar(char c) {
	return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
	string result = "";
	size_t i = 0;
	while (i < word.size()) {
		if (word[i] == '-') {
			if (i > 0 && i < word.size() - 1 && isWordChar(word[i - 1]) && isWordChar(word[i + 1])){
				result += word[i];
			}
			i++;
		} else if (word[i] == '\'') {
			if (i > 0 && i < word.size() - 1 && isWordChar(word[i - 1]) && isWordChar(word[i + 1])){
				result += word[i];
			}
			i++;
		}
		else if (isWordChar(word[i])) {
			result += tolower(word[i]);
			i++;
		}
		else {
			i++;
		}
	}
	return result;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
    map<string, int> data;
    for (size_t i = 0; i < CAPACITY; i++) {
        for (size_t j = 0; j < table[i].size(); j++) {
            data[table[i][j].first] = table[i][j].second;
        }
    }
    for (auto itr = data.rbegin(); itr != data.rend(); itr++) {
        out << itr->first << "," << itr->second << "\n";
    }
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
    map<int, set<string>> data;
    for (size_t i = 0; i < CAPACITY; i++) {
        for (size_t j = 0; j < table[i].size(); j++) {
            data[table[i][j].second].insert(table[i][j].first);
        }
    }
    for (auto itr = data.begin(); itr != data.end(); itr++) {
        for (auto itr2 = (itr->second).begin(); itr2 != (itr->second).end(); itr2++){
            out << *itr2 << "," << itr->first << "\n";
        }
    }
}

void WordCount::addAllWords(std::string text) {
    string tempString = "";
    for (size_t i = 0; i < text.size(); i++) {
        if (i == text.size() - 1){
            tempString += text[i];
            incrWordCount(tempString);
        }
        else if (text[i] != ' ' && text[i] != '\n' && text[i] != '\t') {
            tempString += text[i];
        } 
        else {
            incrWordCount(tempString);
            tempString = "";
        }
    }
}




