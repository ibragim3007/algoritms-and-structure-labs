#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

template<typename T>
void printset(const set<T> & A) {
    cout << "Size: " << A.size() << endl;
    cout << "{";
    copy(A.begin(), A.end(), ostream_iterator<T>(cout, " "));
    cout << "}" << endl;
}

set<string> splitIntoSet(const string text, char delimer = ' ') {
    set<string> words;
    string tempWord;
    for (size_t i = 0; i <= text.size(); i++) {
        if (text[i] == delimer || i == text.size()) {
            if (text.size() == i) tempWord += text[i];
            words.insert(tempWord);
            tempWord = "";
            continue;
        }
        tempWord += text[i];
    }
    return words;
}

set<string> findCross(const set<string> & item1, const set<string> & item2) {
    set<string> cross;

    for(set<string>::iterator it = item1.begin(); it != item1.end(); it++)
        if(item2.find(*it) != item2.end())
            cross.insert(*it);

    return cross;
}

int main () {
    setlocale(LC_ALL, "ru");

    //===== task1 =====
    // set<int> number;
    // int a;
    // for (size_t i = 0; i < 10; i++) {
    //     cout << "Введите элемент множества: ";
    //     cin >> a;
    //     number.insert(a);
    // }
    // printset(number);


    // ===== task2 ====
    // string firstSentence, secondSentence;
    // set<string> firstSet, secondSet;

    // cout << "Введите два предложения" << std::endl;

    // cout << "Введите первое предложение: ";
    // getline(cin, firstSentence);

    // cout << "Введите второе предложение: ";
    // getline(cin, secondSentence);

    // firstSet = splitIntoSet(firstSentence);
    // cout << "\nПервое множество слов: ";
    // printset(firstSet);

    // secondSet = splitIntoSet(secondSentence);
    // cout << "\nВторое множество слов: ";
    // printset(secondSet);

    // set<string> cross = findCross(firstSet, secondSet);
    // cout << "\nCROSS:\n";
    // printset(cross);

    // ==== task3 ====

    const string Cyrillic = "йцукенгшщзхъфывапролджэячсмитьбюё";
    const string Latin = "qwertyuiopasdfghjklzxcvbnm";
    const string Digits = "1234567890";

    // первый варинт 

    // string S;
    // cout << "Введите строку: ";
    // getline(cin, S);
    
    // set<char> A, B, C, everyDigit;

    // // for (int i = 0; i < S.length(); i++) 
    // {
    //     const int charInt = S[i];
    //     const bool Latin = (((charInt >= 'A') && (charInt <= 'Z')) || ((charInt >= 'a') && (charInt <= 'z')));
    //     // const bool Cyrillic = (((charInt >= 'А') && (charInt <= 'Я')) || ((charInt >= 'а') && (charInt <= 'я')));
    //     const bool Cyrillic = ((charInt >= 192) && (charInt <= 255));
    //     const bool Numbers = (charInt >= '0' && charInt <= '9');
    //     if(Latin) A.insert(S[i]);
    //     if(Cyrillic) B.insert(S[i]);
    //     if(Numbers) C.insert(S[i]);
    // }

    // printset(A);
    // printset(B);
    // printset(C);

    //второй вариант 

    string inputString;

    cout << "Enter string with symbols in Latin, Cyrillic or numbers: ";
    getline(std::cin, inputString);

    set<char> S, A, B, C;

    stringstream ss;
    ss = stringstream(inputString);

    while (ss){
        char tmp;
        ss >> tmp;
        S.insert(tmp);
    }

    for(set<char>::iterator it = S.begin(); it!=S.end(); ++it ){
        std::cout << *it << ' ';

        if(Cyrillic.find(*it) != std::string::npos || Cyrillic.find(tolower(*it)) != std::string::npos) A.insert(*it);
        if(Latin.find(*it) != std::string::npos || Latin.find(tolower(*it)) != std::string::npos) B.insert(*it);
        if(Digits.find(*it) != std::string::npos || Digits.find(tolower(*it)) != std::string::npos) C.insert(*it);

    }

        std::cout<< "All Cyrillic: ";
        printset(A);
        std::cout<< "All Latin: ";
        printset(B);
        std::cout<< "All Digits: ";
        printset(C);


}