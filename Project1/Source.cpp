#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Employee
{
private:
	string name;
	string EGN;
	float brPayDay;
	int brDayMonth;

public:
	Employee();
	Employee(string, string, float, int);
	void getData();
	void display();
	void displaysNamesAndAgesOfWomen(vector<Employee> array);
	void displaysNamesAndMonthlyPayOfMenUnder30(vector<Employee> array);
	int age();


	string getName() { return name; };
	string getEGN() { return EGN; };
	float getbrPayDay() { return brPayDay; };
	int getbrDayMonth() { return brDayMonth; };
};

Employee::Employee(void)
{
	name = "Unknown";
	EGN = "Unknown";
	brPayDay = 0.0;
	brDayMonth = 0;
}
Employee::Employee(string c_name, string c_EGN, float c_brPayDay, int c_brDayMonth)
{
	name = c_name;
	EGN = c_EGN;
	brPayDay = c_brPayDay;
	brDayMonth = c_brDayMonth;
}


void Employee::getData()
{
	cin.ignore();
	cout << "Enter data about employee...\n";
	cout << "Enter employee's name: "; getline(cin, name);
	cout << "Enter employee's EGN: "; getline(cin, EGN);
	cout << "Enter employee's daily wage: "; cin >> brPayDay;
	cout << "Enter number of days worked per month: "; cin >> brDayMonth; cout << endl;
	cout << endl;
}

void Employee::display()
{
	cout << "Displaying data...\n";
	cout << "Employee's name: " << name << endl;
	cout << "Employee's EGN: " << EGN << endl;
	cout << "employee's daily wage: " << brPayDay << endl;
	cout << "Number of days worked per month: " << brDayMonth << endl;
	cout << endl;
}

void displayDataArray(vector<Employee> array)
{
	for (Employee i : array)
	{
		i.display();
	}
}


int Employee::age() {
	int year, month, age;
	month = stoi(this->EGN.substr(2, 2));
	year = stoi(this->EGN.substr(0, 2));
	if (month < 13)
	{
		year += 1900;
	}
	else
	{
		year += 2000;
	}
	age = 2023 - year;
	return age;
}

void displaysNamesAndAgesOfWomen(vector<Employee> array)
{
	cout << "Displaying names and ages of women...\n";
	for (Employee i : array)
	{
		string egn = i.getEGN();
		if (egn[8] % 2 != 0)
		{
			cout << "Name: " << i.getName() << ", Age: " << i.age() << endl;
		}
	}
	cout << endl;
}

void displaysNamesAndMonthlyPayOfMenUnder30(vector<Employee> array)
{
	vector<Employee> newArray;

	for (Employee i : array)
	{
		string egn = i.getEGN();
		if ((egn[8] % 2) == 0 && i.age() < 30)
		{
			newArray.push_back(i);
			cout << "one object was pushed into vector\n";
		}
	}
	cout << "New array with names and monthly pay of men under 30:\n";


	for (int i = 0; i < newArray.size(); i++)
	{
		cout << "Name: " << array[i].getName() << "\t" << "Month Pay: " << newArray[i].getbrPayDay() * newArray[i].getbrDayMonth() << endl;
	}
}

int main()
{
	vector<Employee> employees;
	char swNumber;

	do
	{
		cout << "MENU \n";
		cout << "1 - Add new employee.\n";
		cout << "2 - Display all information.\n";
		cout << "3 - Display the names and ages of all the women.\n";
		cout << "4 - Creates a new array with the names and monthly pay of men under 30.\n";
		cout << "Choose an operation or press 0: "; cin >> swNumber;

		switch (swNumber)
		{
		case '1':
		{
			Employee emp; emp.getData();
			employees.push_back(emp);
			break;
		}
		case '2':
		{
			displayDataArray(employees);
			break;
		}
		case '3':
		{
			displaysNamesAndAgesOfWomen(employees);
			break;
		}

		case '4':
		{
			displaysNamesAndMonthlyPayOfMenUnder30(employees);
			break;
		}
		}

	} while (swNumber != '0');

	return 0;
}
