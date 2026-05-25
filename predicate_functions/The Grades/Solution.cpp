#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;
#define ll long long int
#define endl "\n"

struct Student
{
    string name;
    int totalGrade;
};
bool predicateFunction(const pair<Student, array<int, 4>> &P1, const pair<Student, array<int, 4>> &P2)
{
    if (P1.first.totalGrade == P2.first.totalGrade)
        return (P1.first.name < P2.first.name);
    else
        return (P1.first.totalGrade > P2.first.totalGrade);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    int N;
    cin >> N;
    vector<pair<Student, array<int, 4>>> students(N);
    for (int i{}; i < N; i++)
    {
        cin >> students[i].first.name;
        int sumOfGrades{};
        for (int j{}; j < 4; j++)
        {
            cin >> students[i].second[j];
            sumOfGrades += students[i].second[j];
        }
        students[i].first.totalGrade = sumOfGrades;
    }
    sort(students.begin(), students.end(), predicateFunction);
    for (const auto &student : students)
    {
        cout << student.first.name << " " << student.first.totalGrade << " ";
        for (int i{}; i < 4; i++)
            cout << student.second[i] << " \n"[i == 3];
    }
    return 0;
}