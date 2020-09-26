/* 
    Program Name: Quiz Grader (quizGrader.cpp)
    Compile: c++ quizGrader.cpp -o quizGrader
    Author: Malachi Payne
    Course: COMP B12
    Date: 9.25.2020
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <random>

using namespace std;

// ---------- GLOBAL VARIABLES ---------- //
const int QUESTIONS = 5;
const int STUDENTS = 10;
int studentQuestionArray[STUDENTS][QUESTIONS];
int studentScores[STUDENTS];

// ---------- FUNCTIONS ---------- //
float grades()
{
    int score = 0;
    float averageScore = 0;
    const int key[5] = {1, 1, 3, 2, 4};

    for (int i = 0; i < STUDENTS; i++)
    {
        for (int j = 0; j < QUESTIONS; j++)
        {
            if (studentQuestionArray[i][j] == key[j])
            {
                score += 1;
            }
        }
        studentScores[i] = score;
        score = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        score = score + studentScores[i];
    }
    averageScore = score / 10.0;
    return averageScore;
}

int maxScoreFunc()
{
    int maxScore = studentScores[0];
    for (int i = 0; i < STUDENTS; i++)
    {
        if (maxScore < studentScores[i])
        {
            maxScore = studentScores[i];
        }
    }
    return maxScore;
}

int minScoreFunc()
{
    int minScore = studentScores[0];
    for (int i = 0; i < STUDENTS; i++)
    {
        if (minScore > studentScores[i])
        {
            minScore = studentScores[i];
        }
    }
    return minScore;
}

// -------------------- MAIN -------------------- //
int main()
{
    // ---------- VARIABLES ---------- //
    int answers = 0, maxScore = 0, minScore = 0;
    float averageScore = 0;

    // ---------- RANDOM NUMBER GENERATOR BETWEEN 1 & 4 ---------- //
    std::mt19937 randomNumber;
    randomNumber.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> number(1, 4);
    /*
http://www.cplusplus.com/reference/random/uniform_int_distribution/operator%28%29/
    */

    // ---------- FILLING THE ARRAY ---------- //
    for (int student = 0; student < STUDENTS; student++)
    {
        for (int question = 0; question < QUESTIONS; question++)
        {
            answers = number(randomNumber);
            studentQuestionArray[student][question] = answers;
        }
    }

    // ---------- OUTPUT OF AVG, MAX, & MIN SCORES ---------- //
    averageScore = grades();
    maxScore = maxScoreFunc();
    minScore = minScoreFunc();

    cout << "Average Score: " << fixed << setprecision(1) << averageScore << endl
         << "Max: " << maxScore << endl
         << "Min: " << minScore << endl;

    return (0);
}