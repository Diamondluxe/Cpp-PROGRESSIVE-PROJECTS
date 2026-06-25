//Tax Paying Management System of FBR

#include<iostream>
using namespace std;

class TaxPayer
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

class FilerTaxPayer: public TaxPayer
{
    string NTN;
    int nFilerYears;
    double cost;

public:
    FilerTaxPayer(string name, string type, int rate, int ntn, int year)
    : TaxPayer(name,type,rate)
    {
        NTN = ntn;
        nFilerYears = year;
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
       cout<<"Property Cost : "<<cost<<endl;
       cout<<"Tax Rate      : "<<tax_rate<<endl;
       cout<<"Withholding Tax     : "<<CalcWithHoldingTax(cost);
       cout<<"Number of Years from which the Payer is filer: "<<nFilerYears<<endl;
       cout<<"********************************************"<<endl; 
    }

    ~FilerTaxPayer()override
    {
        cout<<"Destructor of FilerTaxPayer called for "<<PayerName<<endl<<endl;
    }
};

class NonFilerTaxPayer: public TaxPayer
{
    string IsEligible;
    double cost;

public:
    NonFilerTaxPayer(string name,string type,int rate, string eligible)
    : TaxPayer(name,type, rate)
    {
        IsEligible = eligible;
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
       cout<<"Property Cost : "<<cost<<endl;
       cout<<"Tax Rate      : "<<tax_rate<<endl;
      
        
    
    }

    ~NonFilerTaxPayer(){}

};

int main()
{

}