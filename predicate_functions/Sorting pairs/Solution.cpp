#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;
#define ll long long int
#define endl "\n"

struct Employee
{
    string name;
    int salary;
};
bool predicateFunction(const Employee &E1, const Employee &E2)
{
    if (E1.salary == E2.salary)
        return (E1.name < E2.name);
    else
        return (E1.salary > E2.salary);
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
    vector<Employee> employees(N);
    for (int i{}; i < N; i++)
        cin >> employees[i].name >> employees[i].salary;

    sort(employees.begin(), employees.end(), predicateFunction);
    for (const auto &employee : employees)
        cout << employee.name << " " << employee.salary << "\n";

    return 0;
}