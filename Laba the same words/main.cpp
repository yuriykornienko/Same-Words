#include<iostream>
#include "sameWordsAnalyzer.h"

int main() 
{
    sameWordsAnalyzer analyzer;
    analyzer.createListFromFile("Wordslist.txt");
    analyzer.createReportFile("ResultPairs.txt");

    return 0;
}