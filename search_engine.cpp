// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// using namespace std;

// vector<string> searchFiles(const string& query) {
//     vector<string> results;
//     vector<string> files = {
//         "data/file1.txt",
//         "data/file2.txt",
//         "data/file3.txt"
//     };

//     for (const string& filename : files) {
//         ifstream file(filename);
//         if (!file) continue;

//         string line;
//         while (getline(file, line)) {
//             if (line.find(query) != string::npos) {
//                 results.push_back(filename + ": " + line);
//             }
//         }
//     }

//     return results;
// }

// int main(int argc, char* argv[]) {
//     if (argc < 2) return 1;
//     string query = argv[1];
//     vector<string> results = searchFiles(query);
//     for (const string& line : results)
//         cout << line << endl;
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> searchFiles(const string& queryRaw) {
    vector<string> results;
    vector<string> files = {
        "data/file1.txt",
        "data/file2.txt",
        "data/file3.txt"
    };

    // Convert query to lowercase for case-insensitive search
    string query = queryRaw;
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    for (const string& filename : files) {
        ifstream file(filename);
        if (!file) continue;

        string line;
        bool fileHeaderPrinted = false;

        while (getline(file, line)) {
            string lineLower = line;
            transform(lineLower.begin(), lineLower.end(), lineLower.begin(), ::tolower);

            if (lineLower.find(query) != string::npos) {
                if (!fileHeaderPrinted) {
                    results.push_back("[" + filename + "]");
                    fileHeaderPrinted = true;
                }
                results.push_back("  " + line);  // indent for clarity
            }
        }
    }

    return results;
}

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    string query = argv[1];
    vector<string> results = searchFiles(query);
    for (const string& line : results)
        cout << line << endl;
    return 0;
}
