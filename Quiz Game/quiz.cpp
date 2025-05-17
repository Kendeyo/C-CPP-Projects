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
#include <vector>           //for dynamic arrays (vector)
#include <sstream>          //for string stream operations(string streams)
using namespace std; //standard library components are contained in the std namespace

/**
 * NOTE: while adding `using namespace std;` can make the code shorter,
 *  it's generally considered bad practice, especially in headers or larger projects,
 *  because it can lead to name collisions. For example, if someone defines a function
 *  or variable with the same name as something in the standard library, it could cause ambiguity.
 * 
 * 
 * You can selectively import specific symbols to skip std:::
 * ---------------------------------------------------------------
 * cpp
 * using std::cout;     // Now you can write "cout" instead of "std::cout"
 * using std::vector;   // Now you can write "vector" instead of "std::vector"
 * 
 * But this is still explicit and safer than importing the entire std namespace.
 */

struct Question {
    string text;                //the question text
    vector<string> options;     //lsit of the options
    int correctAnswer;          //index of the correct answer (0-based)
};

vector<Question> loadQuestions(const string& filename) {
    vector<Question> questions;     //vector to store the questions
    ifstream file(filename);        //open the file
    string line;                    //string to store each line of the file

    while (getline(file, line)) {   //read each line of the file
        Question q;                 //create a new question object
        stringstream ss(line);      //split the line using commas
        string token;               //Temporary token storage
        vector<string> tokens;      //splits parts of the line

        // Split the line by commas into tokens
        // The first token is the question text, the rest are options
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        // Pass the tokens to the question object
        if (tokens.size() >= 5) {
            q.text = tokens[0]; // The first token is the question text

            // The next tokens are the optionns from 1 to n-1
            for (size_t i = 1; i < tokens.size() - 1; i++) {
                q.options.push_back(tokens[i]);
            }

            // The last token is the correct answer (1-based index)
            q.correctAnswer = stoi(tokens.back()) - 1; // Convert to 0-based index
            questions.push_back(q); // Add the question to the list
        }
    }
    return questions; //returns  all parsed questions
}

int main() {
    // Load questions from the file
    vector<Question> questions = loadQuestions("questions.txt");
    int score = 0;

    cout << "Welcome to the Quiz!\n";

    // Loop through each question
    for (size_t i = 0; i < questions.size(); i++) {
        Question& q = questions[i];
        cout << "\nQuestion " << (i + 1) << ": " << q.text << "\n";

        // Display options
        for (size_t j = 0; j < q.options.size(); j++) {
            cout << q.options[j] << "\n";
        }

        // Get user input
        int answer;
        cout << "Your choice (1-" << q.options.size() << "): ";
        cin >> answer;
        answer--; // Convert to 0-based index

        // Validate input
        if (answer == q.correctAnswer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect. The correct answer was: " 
                      << (q.correctAnswer + 1) << "\n";
        }
    }

    // Display final score
    cout << "\nQuiz ended! Final score: " << score << "/" << questions.size() << "\n";
    return 0;
}