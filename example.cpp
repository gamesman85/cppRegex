// Regex search based on Stroustrup's "Principles and Practices"

#include <regex>
using std::regex;
using std::smatch;
#include <iostream>
using std::cerr;
using std::cout;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;

int main() {
    ifstream in {"file.txt"};
    if(!in) cerr << "no file\n";

    // Pattern representing U.S. postal code like "TX77845" or "TX77845-5629"
    regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"};

    int lineno = 0;
    for (string line; getline(in,line); ) {
        ++lineno;
        smatch matches;
        if(regex_search(line, matches, pat))
            cout << lineno << ": " << matches[0] << '\n';
            if(1<matches.size() && matches[1].matched)
                cout << "\t: " << matches[1] << '\n';
    }
}