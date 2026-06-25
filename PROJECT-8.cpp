//Tax Paying Management System of FBR

#include<iostream>
#include<iomanip>
using namespace std;

class TaxPayer  //base class
{
protected:
    string PayerName;
    string PayerType;
    double tax_rate;

public:
    TaxPayer(string name,string type,double rate)
    {
        PayerName = name;
        PayerType = type;
        tax_rate = rate;
    }
    virtual double CalcWithHoldingTax(double propertycost)=0;
    virtual void DetailInfo() = 0;
    virtual ~TaxPayer(){}
};

class FilerTaxPayer: public TaxPayer  //derived class
{
private:  
    string NTN;
    int nFilerYears;
    double cost;

public:
    FilerTaxPayer(string name, string type, double rate, string ntn, int year)
    : TaxPayer(name,type,rate)
    {
        NTN = ntn;
        nFilerYears = year;
        cost = 0;
    }

    double CalcWithHoldingTax(double propertycost)override
    {
        cost = propertycost;
        return (tax_rate / 100) * cost;
    }

    void DetailInfo()override
    {
       cout<<"\n========= Filer Tax Payer ========="<<endl;
       cout<<"Payer Name    : "<<PayerName<<endl;
       cout<<"Payer Type    : "<<PayerType<<endl;
       cout<<"National Tax Number   : "<<NTN<<endl;
       cout<<"Property Cost : "<<fixed<<setprecision(3)<<cost<<endl;
       cout<<"Tax Rate      : "<<tax_rate<<"%"<<endl;
       cout<<"Withholding Tax     : "<<CalcWithHoldingTax(cost)<<endl;
       cout<<"Number of Years from which the Payer is filer: "<<nFilerYears<<endl;
       cout<<"********************************************"<<endl<<endl; 
    }

    ~FilerTaxPayer()override
    {
        cout<<"Destructor of FilerTaxPayer called for "<<PayerName<<endl<<endl;
    }
};

class NonFilerTaxPayer: public TaxPayer  //derived class
{
private:
    string IsEligible;
    double cost;

public:
    NonFilerTaxPayer(string name,string type,double rate)
    : TaxPayer(name,type, rate)
    {
        IsEligible = "";
        cost = 0;
    }

    double CalcWithHoldingTax(double propertycost)override
    {
        cost = propertycost;
        if(cost<=3000000)
        {
            IsEligible = "Yes";
            return (tax_rate/100.0)*cost;
        }
        else{
            IsEligible = "No";
           return 0;
        }
    }
    void DetailInfo()override
    {
       cout<<"\n========= Non-Filer Tax Payer ========="<<endl;
       cout<<"Payer Name    : "<<PayerName<<endl;
       cout<<"Payer Type    : "<<PayerType<<endl;
       cout<<"Eligible      : "<<IsEligible<<endl;
       cout<<"Property Cost : "<<fixed<<setprecision(2)<<cost<<endl;
       cout<<"Tax Rate      : "<<tax_rate<<"%"<<endl;
    
       if(IsEligible == "Yes")
       cout<<"Withholding Tax: "<<CalcWithHoldingTax(cost)<<endl;
       else
       cout<<"Not eligible to buy property above 30 lac."<<endl;
       
       cout<<"***********************************"<<endl<<endl;
    }

    ~NonFilerTaxPayer()override
    {
        cout<<"Destructor of NonFilerTaxPayer called for "<<PayerName<<endl<<endl;
    }

};

int main()
{
    double PropertyCost;

    cout<<"Enter the cost of property to buy: ";
    cin>>PropertyCost;

    cout<<"\n******* FBR Tax Paying Management System ********"<<endl;

    TaxPayer *ptr;
    ptr = new FilerTaxPayer("Umar","Filer",2.500, "17301507", 3);
    ptr->CalcWithHoldingTax(PropertyCost);
    ptr->DetailInfo();
    delete ptr;

    ptr = new NonFilerTaxPayer("Ahmed","Non-Filer", 5.00);
    ptr->CalcWithHoldingTax(PropertyCost);
    ptr->DetailInfo();
    delete ptr;


}