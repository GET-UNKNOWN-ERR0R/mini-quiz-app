#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define TIME_LIMIT 10 

typedef struct {
    char question[256];
    char options[4][50];
    int correctOption; 
} QuizQuestion;

// Function prototypes
void loadQuestions(QuizQuestion questions[]);
void playQuiz(QuizQuestion questions[]);
int askQuestion(QuizQuestion question);

int main() {
    QuizQuestion questions[MAX_QUESTIONS];
    loadQuestions(questions);
    playQuiz(questions);
    return 0;
}

void loadQuestions(QuizQuestion questions[]) {
    strcpy(questions[0].question, "What does HTML stand for?");
    strcpy(questions[0].options[0], "1. HyperText Markup Language");
    strcpy(questions[0].options[1], "2. HyperText Machine Language");
    strcpy(questions[0].options[2], "3. HighText Markup Language");
    strcpy(questions[0].options[3], "4. None of the above");
    questions[0].correctOption = 1;

    strcpy(questions[1].question, "Which programming language is used for web development?");
    strcpy(questions[1].options[0], "1. Python");
    strcpy(questions[1].options[1], "2. JavaScript");
    strcpy(questions[1].options[2], "3. C++");
    strcpy(questions[1].options[3], "4. Java");
    questions[1].correctOption = 2;

    strcpy(questions[2].question, "What does CSS stand for?");
    strcpy(questions[2].options[0], "1. Creative Style Sheets");
    strcpy(questions[2].options[1], "2. Cascading Style Sheets");
    strcpy(questions[2].options[2], "3. Computer Style Sheets");
    strcpy(questions[2].options[3], "4. Control Style Sheets");
    questions[2].correctOption = 2;

    strcpy(questions[3].question, "Which HTTP status code indicates 'Not Found'?");
    strcpy(questions[3].options[0], "1. 200");
    strcpy(questions[3].options[1], "2. 301");
    strcpy(questions[3].options[2], "3. 404");
    strcpy(questions[3].options[3], "4. 500");
    questions[3].correctOption = 3;

    strcpy(questions[4].question, "What is the correct syntax for linking a CSS file in HTML?");
    strcpy(questions[4].options[0], "1. <style src='style.css'>");
    strcpy(questions[4].options[1], "2. <link rel='stylesheet' href='style.css'>");
    strcpy(questions[4].options[2], "3. <css href='style.css'>");
    strcpy(questions[4].options[3], "4. <script src='style.css'>");
    questions[4].correctOption = 2;
}

void playQuiz(QuizQuestion questions[]) {
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int correct = askQuestion(questions[i]);
        if (correct) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }
    printf("\n--- Quiz Over ---\n");
    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
}

int askQuestion(QuizQuestion question) {
    time_t start, end;
    int userAnswer;

    printf("\n%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", question.options[i]);
    }

    printf("You have %d seconds to answer.\n", TIME_LIMIT);
    time(&start);
    printf("Enter your answer (1-4): ");
    scanf("%d", &userAnswer);
    time(&end);

    if (difftime(end, start) > TIME_LIMIT) {
        printf("Time's up!\n");
        return 0;
    }
    return userAnswer == question.correctOption;
}
