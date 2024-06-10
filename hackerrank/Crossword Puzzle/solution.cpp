#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */


 //Design this structure and find the blanks correctly is the key.
 
struct blank {
    pair<int, int> m_coordinates;
    int m_orientation;
    int m_length;
    
    blank (pair<int, int> coordinates, int orientation,int length) {
        m_coordinates = coordinates;
        m_orientation = orientation;
        m_length = length;

    }
    void print() {
        cout << "coordinate [" << m_coordinates.first << ", " << m_coordinates.second << "] " << endl;
        cout << "m_orientation->" << m_orientation << endl;
        cout << "m_length->" << m_length << endl;  
    }
    
};

vector<blank> initialize (const vector<string>& crossword) {
    vector<blank> blanks;
    int n = crossword.size();
    
    // Find horizontal blanks
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n;) {
            if (crossword[i][j] == '-') {
                int start = j;
                while (j < n && crossword[i][j] == '-') j++;
                int length = j - start;
                if (length > 1) {
                    blanks.push_back({{i, start}, 0, length});
                }
            } else {
                j++;
            }
        }
    }

    // Find vertical blanks
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n;) {
            if (crossword[i][j] == '-') {
                int start = i;
                while (i < n && crossword[i][j] == '-') i++;
                int length = i - start;
                if (length > 1) {
                    blanks.push_back({{start, j}, 1, length});
                }
            } else {
                i++;
            }
        }
    }

    return blanks;
}

void fill(vector<string>& crosswords, pair<int, int> coords, string word, int ori, int len, vector<pair<int, int>>& placed) {
    int x = coords.first;
    int y = coords.second;
    // cout << "matched word is " << word << endl;
    if (ori == 0) {
        for(int j = y; j < y + len; j++) {
            crosswords[x][j] = word[j - y];
            placed.push_back({x, j});
        }
    } else {
        for(int i = x; i < x + len; i++) {
            crosswords[i][y] = word[i - x];
            placed.push_back({i, y});
            
        }
    }
    
    //   for (size_t i = 0; i < crosswords.size(); i++) {
    //     cout << crosswords[i];

    //     if (i != crosswords.size() - 1) {
    //         cout << "\n";
    //     }
    // }

    // cout << "\n";
}

//Can't simply undo the locations starts from the blank since some of the locations might be covered by other characters already.
void remove(vector<string>& crosswords, vector<pair<int, int>>& placed){
    for(int i = 0; i < placed.size(); i++) {
        crosswords[placed[i].first][placed[i].second] = '-';
    }
}


bool isFit(vector<string>& crosswords, pair<int, int> coords, string word, int ori, int len) {
    int x = coords.first;
    int y = coords.second;
    char first = crosswords[x][y];
    if (len != word.size()) {
        return false;
    } else {
        if (ori == 0) {
            for(int j = y; j < y + len; j++) {
                if (crosswords[x][j] != '-' && crosswords[x][j] != word[j - y]) {
                    return false;
                }
            }
        } else {
            for(int i = x; i < x + len; i++) {
                if (crosswords[i][y] != '-' && crosswords[i][y] != word[i - x]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool filled = false;//To check if the backtracking ends

void backtracking(vector<string>& crossword, vector<string>& words, vector<blank>& blanks, int index, vector<string>& ans, vector<bool>& used) {
    if (index == blanks.size()) {
        ans = crossword;
        filled = true;
        return;
    }
    if (filled) {
        return ;
    }
    
    // cout << "index = " << index << endl;
    
    pair<int, int> location = blanks[index].m_coordinates;
    int length = blanks[index].m_length;
    int orientation = blanks[index].m_orientation;
    vector<string> tmp = crossword;
    // cout << "location = [" << location.first << ", " << location.second  << "]" << endl;
    // cout << "length = " << length << endl;
    // cout << "orientation = " << orientation << endl;
    
    for(int i = 0; i < words.size(); i++) {
        if (filled) return ;
        string word = words[i];
        if (used[i] == false && isFit(crossword, location, word, orientation, length)) {
            //Use the used vector instead of remove the element from the words
            used[i] = true;
            vector<pair<int, int>> placed;
            fill(crossword, location, word, orientation, length, placed);
            backtracking(crossword, words, blanks, index + 1, ans, used);  
            used[i] = false;
            remove(crossword, placed);
        }
       
    }
}

vector<string> crosswordPuzzle(vector<string> crossword, string words){
    vector <string> allwords;
    words += ";";
    string tmp = "";
    for(char c : words) {
        if (c != ';')
            {
                tmp += c;          
            }
        else {
            // cout << "words: " << tmp << " is put in the words" << endl;
            allwords.push_back(tmp);
            tmp = "";
        }
    }
    vector<string> ans;
    vector<bool> used(allwords.size(), false);
    vector<blank> blanks = initialize(crossword);
    // cout << "FINISHED INITIALIZATION " << endl;
    backtracking(crossword, allwords, blanks, 0, ans, used);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
