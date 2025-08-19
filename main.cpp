#include <iostream>
#include <string>
#include <vector>

using namespace std;

void enterData(int n, vector<string>& subjects, vector<double>& marks)
{


	for (int i = 0; i < n; i++) {
		cout << "Enter the name of subject No." << i + 1 << " = ";
		cin >> subjects[i];

	again2:
		cout << "Enter the " << subjects[i] << " mark = ";
		cin >> marks[i];
		if (marks[i] < 0) {
			cout << "Invalid mark! Please enter a positive value.\n";
			goto again2;
		}
	}
}
double calculateTotal(vector<double>& marks)
{
	double total = 0;
	for (int i = 0;i < marks.size();i++) {
		total += marks[i];
	}
	return total;
}
char calculateGrade(double total, int n)
{
	double pre = total / n;
	if (pre <= 100 && pre >= 90) {
		return 'A';
	}
	else if (pre >= 80 && pre < 90) {
		return 'B';
	}
	else if (pre >= 70 && pre < 80) {
		return 'C';
	}
	else if (pre >= 60 && pre < 70) {
		return 'D';
	}
	else {
		return 'F';
	}
}
void displayData(int n, vector<string>& subjects, vector<double>& marks, double total, char grade)
{
	cout << "\n========= Your Marks ========= \n";

	for (int i = 0; i < n; i++) {
		cout << subjects[i] << " = " << marks[i] << "\n";
	}
	cout << "\n";
	cout << "Total Marks : " << total << "\n";
	double percent = total / n;
	cout << "Percentage : " << percent << "%\n";
	cout << "Grade : " << grade << "\n";
}

int main()
{
	cout << "======= Student Grade Calculator =======\n\n";

again:    // To re-enter the number of subjects
	cout << "Enter the number of subjects = ";

	int n;
	cin >> n;
	if (n <= 0) {
		goto again;
	}

	vector<string>subjects(n);
	vector<double>marks(n);

	enterData(n, subjects, marks);
	cout << "\n*************************************************\n";
	double Total = calculateTotal(marks);
	char Grade = calculateGrade(Total, n);
	displayData(n, subjects, marks, Total, Grade);

	return 0;
}
