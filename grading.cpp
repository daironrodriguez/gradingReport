#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main () {

ifstream inData;
ofstream outData;
string fileName;
string answer;

cout << "Do you have a file? Y/N "<<endl;
cin >> answer;
if (answer == "Y"){
cout << "Enter the full path of the file: ";
cin >> fileName;
inData.open(fileName);
}
else {
inData.open("gradesText.txt");
}
outData.open("grades.out");

char leterGrade;
double percentGrade;
string name;
double sum = 0;
unsigned int counter = 0;
double mean = 0;
double max;
double min;

int studentA;
int studentB;
int studentC;
int studentD;
int studentF;

if (!inData){
	cout << "Unable to open grades.txt"<<endl;
	exit(0);
}
if(!outData){
	cout << "Unable to open grades.out"<<endl;
	exit(0);
}
cout << fixed <<showpoint << setprecision(2) ;
outData << setw(10) << left << "Name"<<  setw(12) << left << "Leter Grade" << setw(14) << right << "Percent Grade"<<endl;
cout << setw(10) << left << "Name"<<  setw(12) << left << "Leter Grade" << setw(14) << right << "Percent Grade"<<endl;

while (inData >> name >> percentGrade){

    sum += percentGrade;
    //high and low grade 
    if (counter == 0){
		max = percentGrade;
		min = percentGrade;
	}
    if (percentGrade > max) {
		max = percentGrade;

		}
	if (percentGrade < min){
		min = percentGrade;
		}

	//seting the grades 
	if (percentGrade >= 90){
		leterGrade = 'A';
		studentA++;
	} 
	else if (percentGrade >= 80){
	    leterGrade = 'B';
	    studentB++;
	}else if(percentGrade >= 70) {
		leterGrade = 'C';
		studentC++;
	}else if (percentGrade > 65){
		leterGrade = 'D';
		studentD++;
	}else {
		leterGrade = 'F';
		studentF++;
	}
	//writing the data 
	cout <<setw(10) << left << name<< setw(6) << right << leterGrade <<  setw(14) << right  << percentGrade << endl;
	outData <<setw(10) << left << name<<  setw(6) << right << leterGrade <<  setw(16) << right  << percentGrade << endl;
counter++;
}
mean = sum /counter; 

//output file 
	outData <<"\nSummary: "<<endl;
	outData<< '\t' <<"Number of students : "<< counter<< endl;
	outData<< '\t' <<"Higher grade: "<< max << endl;
	outData<< '\t' <<"Minimun grade: "<< min << endl;
	outData<< '\t' <<"Mean : "<< mean <<"\n"<<endl;
	outData<< '\t' <<"Studet with A's: "<< studentA <<endl;
	outData<< '\t' <<"Studet with B's: "<< studentB <<endl;
	outData<< '\t' <<"Studet with C's: "<< studentC <<endl;
	outData<< '\t' <<"Studet with D's: "<< studentD <<endl;
	outData<< '\t' <<"Studet with F's: "<< studentF <<endl;
//output 
	cout <<"\nSummary: "<<endl;
	cout<< '\t' <<"Number of students : "<< counter<< endl;
	cout<< '\t' <<"Higher grade: "<< max << endl;
	cout<< '\t' <<"Minimun grade: "<< min << endl;
	cout<< '\t' <<"Mean : "<< mean <<"\n"<<endl;
	cout<< '\t' <<"Studet with A's: "<< studentA <<endl;
	cout<< '\t' <<"Studet with B's: "<< studentB <<endl;
	cout<< '\t' <<"Studet with C's: "<< studentC <<endl;
	cout<< '\t' <<"Studet with D's: "<< studentD <<endl;
	cout<< '\t' <<"Studet with F's: "<< studentF <<endl;

	
return 0;
}




