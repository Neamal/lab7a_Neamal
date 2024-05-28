#include "tddFuncs.h"
#include "WordCount.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    cout << "Testing class WordCount..." << endl;

    WordCount test1;

    ASSERT_EQUALS("junhyungyoon", test1.makeValidWord("019ju1nhyung--*yoon"));
    ASSERT_EQUALS("baboonkeyhehe", test1.makeValidWord("--*baboo91nKeyH*ehe"));
    ASSERT_EQUALS("", test1.makeValidWord(""));

    WordCount test2;

    ASSERT_EQUALS(0, test2.incrWordCount(""));
    ASSERT_EQUALS(0, test2.incrWordCount("****"));
    ASSERT_EQUALS(1, test2.incrWordCount("019ju1nhyung--*yoon"));
    ASSERT_EQUALS(2, test2.incrWordCount("019ju1nhyung--*yoon"));
    ASSERT_EQUALS(0, test2.getWordCount(""));
    ASSERT_EQUALS(2, test2.getWordCount("019ju1nhyung--*yoon"));
    ASSERT_EQUALS(1, test2.decrWordCount("019ju1nhyung--*yoon"));
    ASSERT_EQUALS(0, test2.decrWordCount("019ju1nhyung--*yoon"));
    ASSERT_EQUALS(-1, test2.decrWordCount("019ju1nhyung--*yoon"));
    ASSERT_EQUALS(1, test2.incrWordCount("019ju1nhyung--*yoon"));
    ASSERT_EQUALS(2, test2.incrWordCount("019ju1nhyung--*yoon"));
    ASSERT_EQUALS(2, test2.getTotalWords());
    ASSERT_EQUALS(1, test2.getNumUniqueWords());
    ASSERT_EQUALS(1, test2.incrWordCount("hehehehehehehe"));
    ASSERT_EQUALS(2, test2.getNumUniqueWords());
    ASSERT_EQUALS(3, test2.getTotalWords());

    WordCount test3;
    ostringstream os1;
    ostringstream os2;
    string text = "the mon&&&&key !!!ate the jun's banana Banana";
    string check = "the,2\nmonkey,1\njun's,1\nbanana,2\nate,1\n";
    string check2 = "ate,1\njun's,1\nmonkey,1\nbanana,2\nthe,2\n";
    test3.addAllWords(text);
    test3.dumpWordsSortedByWord(os1);
    ASSERT_EQUALS(check, os1.str());
    test3.dumpWordsSortedByOccurence(os2);
    ASSERT_EQUALS(check2, os2.str());
}