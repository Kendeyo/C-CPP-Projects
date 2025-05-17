/**
 *                  QUIZ GAME    
 * ===================================================================
 *                  Features:
 * 1. Read quiz questions , options and answers from a .txt file.
 * 2. Display questions one by one with multiple choice options.
 * 3. Track and display the user score in real time.
 * 4. Handle invalid inputs gracefully.(non integer choices)
 * 5. Show a finall summary with the total correct/ incorect answers.
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std; //standard library components are contained in the std namespace

/**
 * NOTE: while adding `using namespace std;` can make the code shorter,
 *  it's generally considered bad practice, especially in headers or larger projects,
 *  because it can lead to name collisions. For example, if someone defines a function
 *  or variable with the same name as something in the standard library, it could cause ambiguity.
 * 
 * 
 * You can selectively import specific symbols to skip std:::
 * ---------------------------
 * cpp
 * using std::cout;     // Now you can write "cout" instead of "std::cout"
 * using std::vector;   // Now you can write "vector" instead of "std::vector"
 * 
 * But this is still explicit and safer than importing the entire std namespace.
 */

struct Question {
    string text;
    vector<string> options;
    int correctAnswer;
};

vector<Question> loadQuestions(const string& filename) {
    vector<Question> questions;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        Question q;
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 5) {
            q.text = tokens[0];
            for (size_t i = 1; i < tokens.size() - 1; i++) {
                q.options.push_back(tokens[i]);
            }
            q.correctAnswer = stoi(tokens.back()) - 1; // Convert to 0-based index
            questions.push_back(q);
        }
    }
    return questions;
}

int main() {
    vector<Question> questions = loadQuestions("questions.txt");
    int score = 0;

    cout << "Welcome to the Quiz!\n";

    for (size_t i = 0; i < questions.size(); i++) {
        Question& q = questions[i];
        cout << "\nQuestion " << (i + 1) << ": " << q.text << "\n";

        for (size_t j = 0; j < q.options.size(); j++) {
            cout << q.options[j] << "\n";
        }

        int answer;
        cout << "Your choice (1-" << q.options.size() << "): ";
        cin >> answer;
        answer--; // Convert to 0-based index


        if (answer == q.correctAnswer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect. The correct answer was: " 
                      << (q.correctAnswer + 1) << "\n";
        }
    }

    cout << "\nQuiz ended! Final score: " << score << "/" << questions.size() << "\n";
    return 0;
}