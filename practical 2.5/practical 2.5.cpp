#include <iostream>
#include <math.h>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int Months;
    float emi;
    public:

    Loan()
    {
        loanID = 0;
        applicantName = "Angel";
        loanAmount = 500;
        annualInterestRate = 5;
        Months = 7;
        calculateEMI();
    }


    Loan(int id, string name, double amount, double rate, int months)
    {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        Months = months;
        calculateEMI();
    }


    void calculateEMI()
    {
        double monthlyRate = annualInterestRate / (12 * 100);
        emi = (loanAmount * monthlyRate * pow(1 + monthlyRate, Months)) /
                     (pow(1 + monthlyRate, Months) - 1);

    }
    void display()
    {
        cout<<"======================================"<<endl;
        cout<<"loan id :"<<loanID<<endl;
        cout<<"applicant name : "<<applicantName<<endl;
        cout<<"total loan amount : "<<loanAmount<<endl;
        cout<<"annual interest rate : "<<annualInterestRate<<endl;
        cout<<"loan tenure (months) : "<<Months<<endl;
        cout<<"EMI : "<<emi<<endl;
        cout<<"======================================"<<endl;
    }
};
int main()
{
   Loan l1;
   cout<<"default loan details: "<<endl;
   l1.display();

   Loan l2(20,"yatri",5000,10,12);
   cout<<"parameterized loan details : "<<endl;
   l2.display();
}
