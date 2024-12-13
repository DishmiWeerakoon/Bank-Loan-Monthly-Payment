#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

float IR = 0;
float D = 0;
float repay = 0;
float tot = 0;
float totinterest = 0;
string choice;

void CustomerChoice (int age, int income)
{
    cout<< "\tOptions for you"<<endl<<endl;;
    if (age >= 18 && age <= 55){
        if (income >= 45000){
            cout<< "Option number : 1"<<endl;
            cout<< "Name : Vehicle"<< endl;
            cout<< "Maximum loan Amount : LKR 1,000,000"<< endl;
            cout<< "Maximum repay period allowed : 60 months"<< endl;
            cout<< "Annual interest rate : 14%"<< endl<<endl;
            choice = "yes";
        }
    }
    if (age >= 25 && age <= 55){
        if (income >= 100000){
            cout<< "Option number : 2"<<endl;
            cout<< "Name : Housing"<< endl;
            cout<< "Maximum loan Amount : LKR 2,500,000"<< endl;
            cout<< "Maximum repay period allowed : 60 months"<< endl;
            cout<< "Annual interest rate : 8%"<< endl<<endl;
            choice = "yes";
        }
    }
    if (age >= 25 && age <= 35){
        if (income >= 45000){
            cout<< "Option number : 3"<<endl;
            cout<< "Name : Education"<< endl;
            cout<< "Maximum loan Amount : LKR 1,500,000"<< endl;
            cout<< "Maximum repay period allowed : 284 months"<< endl;
            cout<< "Annual interest rate : 6%"<< endl<<endl;
            choice = "yes";
        }
    }
    if (age >= 60){
        if (income >= 35000){
            cout<< "Option number : 4"<<endl;
            cout<< "Name : Senior Citizen"<< endl;
            cout<< "Maximum loan Amount : LKR 500,000"<< endl;
            cout<< "Maximum repay period allowed : 60 months"<< endl;
            cout<< "Annual interest rate : 4.5%"<< endl<<endl;
            choice = "yes";
        }
    }
    if (age >= 30 && age <= 55){
        if (income >= 100000){
            cout<< "Option number : 5"<<endl;
            cout<< "Name : Personal"<< endl;
            cout<< "Maximum loan Amount : LKR 2,000,000"<< endl;
            cout<< "Maximum repay period allowed : 60 months"<< endl;
            cout<< "Annual interest rate : 14.5%"<< endl<<endl;
            cout<< "Option number : 6"<<endl;
            cout<< "Name : Personal"<< endl;
            cout<< "Maximum loan Amount : LKR 3,000,000"<< endl;
            cout<< "Maximum repay period allowed : 84 months"<< endl;
            cout<< "Annual interest rate : 16.2%"<< endl<<endl;
            choice = "yes";

        }
    }
    if (!(age >= 18 && age <= 55 && income >= 45000) &&
        !(age >= 25 && age <= 55 && income >= 100000) &&
        !(age >= 25 && age <= 35 && income >= 45000) &&
        !(age >= 60 && income >= 35000) &&
        !(age >= 30 && age <= 55 && income >= 100000)) {
        cout << "No suitable options found." <<endl<<endl;
        choice = "No";
    }

}

bool Valid(int option, int age, int income) 
{
    if (age >= 18 && age <= 55) {
        if (income >= 45000) {
            if (option == 1) 
                    return true;
        }
    }
    if (age >= 25 && age <= 55) {
        if (income >= 100000) {
            if (option == 2 || option == 5) 
                    return true;           
        }
    }
    if (age >= 25 && age <= 35) {
        if (income >= 45000) {
            if (option == 3) 
                return true;
        }
    }
    if (age >= 60) {
        if (income >= 35000) {
            if (option == 4) 
                    return true;    
        }
    }
    if (age >= 30 && age <= 55) {
        if (income >= 100000) {
            if (option == 5 || option == 6) 
                return true;
        }
    }
    return false; 
}

int rate (int option)
{
    switch (option)
    {
    case 1: return 14; break;
    case 2: return 8; break;
    case 3: return 6; break;
    case 4: return 4.5; break;
    case 5: return 14.5; break;
    case 6: return 16.2; break;
    default:
        cout<< "Invalid Option!"<<endl;
        return 0;
        break;
    }
}

void Display (int n, float rate, float barrow)
{
    IR = (rate * 0.01)/12;
    D = (((pow(1 + IR, n)) - 1) / (IR * pow(1 + IR, n)));
    repay = barrow/D;
    tot = repay * n;
    totinterest = tot - barrow;

    cout<< "Monthly repay amount = LKR "<< std::fixed << std::setprecision(2) <<repay<<endl;
    cout<< "Total amount of money that customer pays = LKR "<< std::fixed << std::setprecision(2) <<tot<<endl;
    cout<< "Total amount of interest earned by the bank at the end of the period = LKR "<< std::fixed << std::setprecision(2) <<totinterest<<endl<<endl;

}

void DetailsofLoan (int option, float barrow, int possible)
{
    int n = possible * 12;
    switch(option){
        case 1:
            if (barrow <=1000000 && n <= 60)
                Display (n, 14, barrow);
            else
                cout<< "Maximum limit of amount or period is exeeded."<<endl;
            break;

        case 2:
            if (barrow <=2500000 && n <= 60)
                Display (n, 8, barrow);
            else
                cout<< "Maximum limit of amount or period is exeeded."<<endl;
            break;

        case 3:
            if (barrow <=1500000 && n <= 284)
                Display (n, 6, barrow);
            else
                cout<< "Maximum limit of amount or period is exeeded."<<endl;   
            break;

        case 4:
            if (barrow <=500000 && n <= 60)
                Display (n, 4.5, barrow);
            else
                cout<< "Maximum limit of amount or period is exeeded."<<endl;  
            break;

        case 5:
            if (barrow <=2000000 && n <= 60)
                Display (n, 14.5, barrow);
            else
                cout<< "Maximum limit of amount or period is exeeded."<<endl;
            break;

        case 6:
            if (barrow <=3000000 && n <= 84)
                Display (n, 16.2, barrow);
            else
                cout<< "Maximum limit of amount or period is exeeded."<<endl;
            break;

        default:
            cout<< "Invalid Option!"<<endl;

    }  
}

string SelectedOption (int option)
{
    string opName, repayperiod, fixed;
    switch (option)
    {
    case 1:
        opName = "Vehicle";
        repayperiod = "60 months";
        fixed = "14%";
        break;

    case 2:
        opName = "Housing";
        repayperiod = "60 months";
        fixed = "8%";
        break;
    
    case 3:
        opName = "Education";
        repayperiod = "284 months";
        fixed = "6%";
        break;
    
    case 4:
        opName = "Senior Citizen";
        repayperiod = "60 months";
        fixed = "4.5%";
        break;
    
    case 5:
        opName = "Personal";
        repayperiod = "60";
        fixed = "14.5";
        break;

    case 6:
        opName = "Personal";
        repayperiod = "84 months";
        fixed = "16.2%";
        break;
    
    default:
        opName = "Invalid Option!";
        break;
    }

    string result = "Selected Loan : " + opName + "\nMaximum repay period allowed : " + repayperiod + "\nAnnual interest rate : " + fixed;
    return result;

}

void Table (ofstream &outputFile, int possible, int barrow)
{
    int n = possible * 12;
    float interest = 0;
    float repaid = 0;

    outputFile <<"\tMonth\t\tRemaining Loan Amont\t\tInterest\t\tRepaid loan amount"<<endl;
    for(int i = 0; i<n; i++ )
    {
        outputFile<<"\t"<< i+1<<"\t\t\t";
        barrow = barrow - repaid;
        outputFile<<barrow<<"\t\t\t";
        interest = barrow * IR;
        outputFile<< interest<<"\t\t\t";
        repaid = repay - interest;
        outputFile<< repaid <<endl;
    }
    outputFile << endl;
}


int main()
{
    while (true){

    string name;
    int age;
    float income;

    cout<< "\t\tCustomer's Details"<<endl;
    cout<< "Customer Name (Enter with initials Eg: ABC.Perera): ";
    cin>> name;
    cout<< "Customer Age : ";
    cin>> age;
    cout<< "Customer Monthly Income : LKR ";
    cin>> income;
    cout<<endl<<endl;

    CustomerChoice(age, income);

    int option, possible;
    float barrow;

    if (choice != "yes") {
        continue; // Return to the start of the loop in the main function
    }

    cout<< "Enter the index number of the loan option you are willing to select among the possible options:";
    cin>> option;

    if (!Valid(option, age, income)){ //Check whether input option number is valid or not
            cout<<"Invalid Option! Please select a valid option" << endl<<endl;
            continue; // Return to the start of the loop in the main function
        }

    cout<< "Enter the amount of money that customer wishes to barrow (Do not exeed the maximum amount): LKR ";
    cin>>barrow;
    cout<< "Enter the possible repay period in years (Do no exeed maximum period): ";
    cin>>possible;
    cout<<endl;

    DetailsofLoan (option, barrow, possible);

    for (size_t i = 0; i < name.length() - 6; ++i) { //Replace "." with "_"
        if (name[i] == '.' && name[i + 6] != '.') {
            name[i] = '_';
        }
    }

    string fileName = "Mr_" + name + ".txt";
    ofstream outputFile(fileName);

    if (outputFile.is_open()) {
        outputFile<< "Name of the customer : "<< name <<endl;
        outputFile<< SelectedOption(option) <<endl;
        outputFile<< "Requested Loan amount and repay period : LKR "<< std::fixed << std::setprecision(2) <<barrow<<" from "<<possible<<" years"<<endl;
        outputFile<< "Loan repayment schedule :"<<endl<<endl;
        Table(outputFile, possible, barrow); 
        outputFile<< "Total amount of money paid by the customer at the end of the loan repay period : LKR "<< std::fixed << std::setprecision(2) <<tot<<endl;

        outputFile.close();
    }
    else{
        cout << "Unable to open the file." << endl;
    }

    }
    return 0;

}