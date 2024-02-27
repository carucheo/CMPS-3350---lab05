#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> dictionary;

void displayAsciiArt()
{
    cout << "  _______                                                          " << endl;
    cout << " ;   /   ; .___    ___  , __     ____  |     ___  _/_     __.  .___ " << endl;
    cout << "     |     /   \\  /   ` |'  `.  (      |    /   `  |    .'   \\ /   \\" << endl;
    cout << "     |     |   ' |    | |    |  `--.   |   |    |  |    |    | |   '" << endl;
    cout << "     /     /     `.__/| /    | \\___.' /\\__ `.__/|  \\__/  `._.' /    " << endl;
    cout << "                                                                  " << endl;
}

void loadFile(const string &word)
{
    ifstream file(word);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string english, spanish;
            getline(ss, english, ',');
            getline(ss, spanish);
            dictionary[english] = spanish;
        }
        file.close();
    }
    else
    {
        cerr << "Cannot open file" << endl;
    }
}

bool isColorInFile(const string &word)
{
    return dictionary.find(word) != dictionary.end();
}

string translateColor(const string &word)
{
    auto text = dictionary.find(word);
    if (text != dictionary.end())
    {
        return "         Translation for " + word + ": " + text->second;
    }
    else
    {
        return "         Translation not found";
    }
}

int main()
{
    displayAsciiArt();
    loadFile("text.csv");

    string user_input;
    cout << "\n         ";
    cout << "Enter text to translate from English to Spanish: ";
    cin >> user_input;

    cout << translateColor(user_input);
    cout << endl;

    return 0;
}
