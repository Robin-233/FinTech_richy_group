#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;

/*
Author:WangYan
*/

void login_interface() {
	cout<<"*****************************************************\n";
	cout<<"*                                                   *\n";
	cout<<"*        Welcome  to  Tax  Calculation  System      *\n";
	cout<<"*            Please choose your platform            *\n";
	cout<<"*                                                   *\n";
	cout<<"*                                                   *\n";
	cout<<"*            1.Youtube         2.Bilibili           *\n";
	cout<<"*            3.RedBook         4.Instagram          *\n";
	cout<<"*                     5.exit                        *\n";
	cout<<"*                                                   *\n";
	cout<<"*****************************************************\n";

}


void utb_cal(string utb_cha[],double utb_b4[],double utb_tax[],double utb_af[],int country,double *income_b4,double *tax_sum,double *income_af,string username) {

	ofstream ou("data_youtube.csv");

	cout<<"Please input your video income: ";
	cin>>utb_b4[0];
	cout<<"Please input your live income: ";
	cin>>utb_b4[1];
	cout<<"Please input your advertising income: ";
	cin>>utb_b4[2];
	*income_b4=utb_b4[0]+utb_b4[1]+utb_b4[2];
	//cout<<*income_b4;
	switch(country) {
		case 1:
			//cout<<"hello";
			if(*income_b4>0&&*income_b4<=11850)
				*tax_sum=0;
			else if(*income_b4>11851&&*income_b4<=46350)
				*tax_sum=(*income_b4-11850)*0.2;
			else if(*income_b4>46351&&*income_b4<=150000)
				*tax_sum=(46350-11850)*0.2+(*income_b4-46350)*0.4;
			else if(*income_b4>150000)
				*tax_sum=(46350-11850)*0.2+(150000-46350)*0.4+(*income_b4-150000)*0.45;
			//cout<<*tax_sum;
		case 2:
			if(*income_b4>0&&*income_b4<=10275)
				*tax_sum=*income_b4*0.1;
			else if(*income_b4>10275&&*income_b4<=41775)
				*tax_sum=10275*0.1+(*income_b4-10275)*0.12;
			else if(*income_b4>41775&&*income_b4<=89075)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(*income_b4-41775)*0.22;
			else if(*income_b4>89075&&*income_b4<=170050)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(*income_b4-89075)*0.24;
			else if(*income_b4>170050&&*income_b4<=215950)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(170050-89075)*0.24+(*income_b4-170050)*0.32;
			else if(*income_b4>215950)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(170050-89075)*0.24+(215950-170050)*0.32+(*income_b4-215950)*0.35;
		case 3:
			if(*income_b4>0&&*income_b4<=1000)
				*tax_sum=*income_b4*0.09;
			else if(*income_b4>1000&&*income_b4<=4000)
				*tax_sum=1000*0.09+(*income_b4-1000)*0.18;
			else if(*income_b4>4000&&*income_b4<=8000)
				*tax_sum=1000*0.09+(4000-1000)*0.18+(*income_b4-4000)*0.27;
			else if(*income_b4>8000)
				*tax_sum=1000*0.09+(4000-1000)*0.18+(8000-4000)*0.27+(*income_b4-8000)*0.36;

		case 4:
			if(*income_b4>0&&*income_b4<=1950000)
				*tax_sum=*income_b4*0.05;
			else if(*income_b4>1950000&&*income_b4<=3300000)
				*tax_sum=1950000*0.05+(*income_b4-1950000)*0.1;
			else if(*income_b4>3300000&&*income_b4<=6950000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(*income_b4-3300000)*0.2;
			else if(*income_b4>6950000&&*income_b4<=9000000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(*income_b4-6950000)*0.23;
			else if(*income_b4>9000000&&*income_b4<=18000000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(*income_b4-9000000)*0.33;
			else if(*income_b4>215950)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(18000000-9000000)*0.33+(*income_b4-18000000)*0.4;
			else if(*income_b4>215950)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(18000000-9000000)*0.33+(40000000-18000000)*0.4+(*income_b4-40000000)*0.45;
	}

	utb_tax[0]=(*tax_sum) * (utb_b4[0]/(utb_b4[0]+utb_b4[1]+utb_b4[2]));
	utb_tax[1]=(*tax_sum) * (utb_b4[1]/(utb_b4[0]+utb_b4[1]+utb_b4[2]));
	utb_tax[2]=(*tax_sum) * (utb_b4[2]/(utb_b4[0]+utb_b4[1]+utb_b4[2]));

	utb_af[0]=utb_b4[0]-utb_tax[0];
	utb_af[1]=utb_b4[1]-utb_tax[1];
	utb_af[2]=utb_b4[2]-utb_tax[2];

	*income_af=*income_b4-*tax_sum;

	//ou << a[i][j] << ",";
	ou<<"Name"<<","<<username<<","<<"Platform"<<","<<"Youtube"<<endl;
	ou<<""<<","<<"Before Tax income"<<","<<"Tax"<<","<<"After-Tax income"<<endl;
	ou<<utb_cha[0]<<","<<utb_b4[0]<<","<<utb_tax[0]<<","<<utb_af[0]<<endl;
	ou<<utb_cha[1]<<","<<utb_b4[1]<<","<<utb_tax[1]<<","<<utb_af[1]<<endl;
	ou<<utb_cha[2]<<","<<utb_b4[2]<<","<<utb_tax[2]<<","<<utb_af[2]<<endl;
	ou<<"Before Tax Total income"<<","<<*income_b4<<endl;
	ou<<"Total Tax Payable"<<","<<*tax_sum<<endl;
	ou<<"After Tax Total income"<<","<<*income_af<<endl;

	ou.close();
}

void bli_cal(string bli_cha[],double bli_b4[],double bli_tax[],double bli_af[],int country,double *income_b4,double *tax_sum,double *income_af,string username) {

	ofstream ou("data_bilibili.csv");

	//   string bli_cha[5]={"Live","Video","Event","Charging Plans","Advertising"};
	cout<<"Please input your live income: ";
	cin>>bli_b4[0];
	cout<<"Please input your video income: ";
	cin>>bli_b4[1];
	cout<<"Please input your event income: ";
	cin>>bli_b4[2];
	cout<<"Please input your charging Plans income: ";
	cin>>bli_b4[3];
	cout<<"Please input your advertising income: ";
	cin>>bli_b4[4];

	*income_b4=bli_b4[0]+bli_b4[1]+bli_b4[2]+bli_b4[3]+bli_b4[4];
	//cout<<*income_b4;
	switch(country) {
		case 1:
			//cout<<"hello";
			if(*income_b4>0&&*income_b4<=11850)
				*tax_sum=0;
			else if(*income_b4>11851&&*income_b4<=46350)
				*tax_sum=(*income_b4-11850)*0.2;
			else if(*income_b4>46351&&*income_b4<=150000)
				*tax_sum=(46350-11850)*0.2+(*income_b4-46350)*0.4;
			else if(*income_b4>150000)
				*tax_sum=(46350-11850)*0.2+(150000-46350)*0.4+(*income_b4-150000)*0.45;
			//cout<<*tax_sum;
		case 2:
			if(*income_b4>0&&*income_b4<=10275)
				*tax_sum=*income_b4*0.1;
			else if(*income_b4>10275&&*income_b4<=41775)
				*tax_sum=10275*0.1+(*income_b4-10275)*0.12;
			else if(*income_b4>41775&&*income_b4<=89075)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(*income_b4-41775)*0.22;
			else if(*income_b4>89075&&*income_b4<=170050)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(*income_b4-89075)*0.24;
			else if(*income_b4>170050&&*income_b4<=215950)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(170050-89075)*0.24+(*income_b4-170050)*0.32;
			else if(*income_b4>215950)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(170050-89075)*0.24+(215950-170050)*0.32+(*income_b4-215950)*0.35;
		case 3:
			if(*income_b4>0&&*income_b4<=1000)
				*tax_sum=*income_b4*0.09;
			else if(*income_b4>1000&&*income_b4<=4000)
				*tax_sum=1000*0.09+(*income_b4-1000)*0.18;
			else if(*income_b4>4000&&*income_b4<=8000)
				*tax_sum=1000*0.09+(4000-1000)*0.18+(*income_b4-4000)*0.27;
			else if(*income_b4>8000)
				*tax_sum=1000*0.09+(4000-1000)*0.18+(8000-4000)*0.27+(*income_b4-8000)*0.36;

		case 4:
			if(*income_b4>0&&*income_b4<=1950000)
				*tax_sum=*income_b4*0.05;
			else if(*income_b4>1950000&&*income_b4<=3300000)
				*tax_sum=1950000*0.05+(*income_b4-1950000)*0.1;
			else if(*income_b4>3300000&&*income_b4<=6950000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(*income_b4-3300000)*0.2;
			else if(*income_b4>6950000&&*income_b4<=9000000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(*income_b4-6950000)*0.23;
			else if(*income_b4>9000000&&*income_b4<=18000000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(*income_b4-9000000)*0.33;
			else if(*income_b4>215950)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(18000000-9000000)*0.33+(*income_b4-18000000)*0.4;
			else if(*income_b4>215950)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(18000000-9000000)*0.33+(40000000-18000000)*0.4+(*income_b4-40000000)*0.45;
	}

	bli_tax[0]=(*tax_sum) * (bli_b4[0]/(bli_b4[0]+bli_b4[1]+bli_b4[2]+bli_b4[3]+bli_b4[4]));
	bli_tax[1]=(*tax_sum) * (bli_b4[1]/(bli_b4[0]+bli_b4[1]+bli_b4[2]+bli_b4[3]+bli_b4[4]));
	bli_tax[2]=(*tax_sum) * (bli_b4[2]/(bli_b4[0]+bli_b4[1]+bli_b4[2]+bli_b4[3]+bli_b4[4]));
	bli_tax[3]=(*tax_sum) * (bli_b4[3]/(bli_b4[0]+bli_b4[1]+bli_b4[2]+bli_b4[3]+bli_b4[4]));
	bli_tax[4]=(*tax_sum) * (bli_b4[4]/(bli_b4[0]+bli_b4[1]+bli_b4[2]+bli_b4[3]+bli_b4[4]));

	bli_af[0]=bli_b4[0]-bli_tax[0];
	bli_af[1]=bli_b4[1]-bli_tax[1];
	bli_af[2]=bli_b4[2]-bli_tax[2];
	bli_af[3]=bli_b4[3]-bli_tax[3];
	bli_af[4]=bli_b4[4]-bli_tax[4];

	*income_af=*income_b4-*tax_sum;

	//ou << a[i][j] << ",";
	ou<<"Name"<<","<<username<<","<<"Platform"<<","<<"Blibili"<<endl;
	ou<<""<<","<<"Before Tax income"<<","<<"Tax"<<","<<"After-Tax income"<<endl;
	ou<<bli_cha[0]<<","<<bli_b4[0]<<","<<bli_tax[0]<<","<<bli_af[0]<<endl;
	ou<<bli_cha[1]<<","<<bli_b4[1]<<","<<bli_tax[1]<<","<<bli_af[1]<<endl;
	ou<<bli_cha[2]<<","<<bli_b4[2]<<","<<bli_tax[2]<<","<<bli_af[2]<<endl;
	ou<<bli_cha[3]<<","<<bli_b4[3]<<","<<bli_tax[3]<<","<<bli_af[3]<<endl;
	ou<<bli_cha[4]<<","<<bli_b4[4]<<","<<bli_tax[4]<<","<<bli_af[4]<<endl;
	ou<<"Before Tax Total income"<<","<<*income_b4<<endl;
	ou<<"Total Tax Payable"<<","<<*tax_sum<<endl;
	ou<<"After Tax Total income"<<","<<*income_af<<endl;

	ou.close();
}

void red_cal(string red_cha[],double red_b4[],double red_tax[],double red_af[],int country,double *income_b4,double *tax_sum,double *income_af,string username) {

	ofstream ou("data_redbook.csv");

	//   string red_cha[4]={"Live","Advertising","Drainage and realization","Online Store"};
	cout<<"Please input your live income: ";
	cin>>red_b4[0];
	cout<<"Please input your advertising income: ";
	cin>>red_b4[1];
	cout<<"Please input your drainage and realization income: ";
	cin>>red_b4[2];
	cout<<"Please input your online Store income: ";
	cin>>red_b4[3];


	*income_b4=red_b4[0]+red_b4[1]+red_b4[2]+red_b4[3];
	//cout<<*income_b4;
	switch(country) {
		case 1:
			//cout<<"hello";
			if(*income_b4>0&&*income_b4<=11850)
				*tax_sum=0;
			else if(*income_b4>11851&&*income_b4<=46350)
				*tax_sum=(*income_b4-11850)*0.2;
			else if(*income_b4>46351&&*income_b4<=150000)
				*tax_sum=(46350-11850)*0.2+(*income_b4-46350)*0.4;
			else if(*income_b4>150000)
				*tax_sum=(46350-11850)*0.2+(150000-46350)*0.4+(*income_b4-150000)*0.45;
			//cout<<*tax_sum;
		case 2:
			if(*income_b4>0&&*income_b4<=10275)
				*tax_sum=*income_b4*0.1;
			else if(*income_b4>10275&&*income_b4<=41775)
				*tax_sum=10275*0.1+(*income_b4-10275)*0.12;
			else if(*income_b4>41775&&*income_b4<=89075)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(*income_b4-41775)*0.22;
			else if(*income_b4>89075&&*income_b4<=170050)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(*income_b4-89075)*0.24;
			else if(*income_b4>170050&&*income_b4<=215950)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(170050-89075)*0.24+(*income_b4-170050)*0.32;
			else if(*income_b4>215950)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(170050-89075)*0.24+(215950-170050)*0.32+(*income_b4-215950)*0.35;
		case 3:
			if(*income_b4>0&&*income_b4<=1000)
				*tax_sum=*income_b4*0.09;
			else if(*income_b4>1000&&*income_b4<=4000)
				*tax_sum=1000*0.09+(*income_b4-1000)*0.18;
			else if(*income_b4>4000&&*income_b4<=8000)
				*tax_sum=1000*0.09+(4000-1000)*0.18+(*income_b4-4000)*0.27;
			else if(*income_b4>8000)
				*tax_sum=1000*0.09+(4000-1000)*0.18+(8000-4000)*0.27+(*income_b4-8000)*0.36;

		case 4:
			if(*income_b4>0&&*income_b4<=1950000)
				*tax_sum=*income_b4*0.05;
			else if(*income_b4>1950000&&*income_b4<=3300000)
				*tax_sum=1950000*0.05+(*income_b4-1950000)*0.1;
			else if(*income_b4>3300000&&*income_b4<=6950000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(*income_b4-3300000)*0.2;
			else if(*income_b4>6950000&&*income_b4<=9000000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(*income_b4-6950000)*0.23;
			else if(*income_b4>9000000&&*income_b4<=18000000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(*income_b4-9000000)*0.33;
			else if(*income_b4>215950)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(18000000-9000000)*0.33+(*income_b4-18000000)*0.4;
			else if(*income_b4>215950)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(18000000-9000000)*0.33+(40000000-18000000)*0.4+(*income_b4-40000000)*0.45;
	}

	red_tax[0]=(*tax_sum) * (red_b4[0]/(red_b4[0]+red_b4[1]+red_b4[2]+red_b4[3]));
	red_tax[1]=(*tax_sum) * (red_b4[1]/(red_b4[0]+red_b4[1]+red_b4[2]+red_b4[3]));
	red_tax[2]=(*tax_sum) * (red_b4[2]/(red_b4[0]+red_b4[1]+red_b4[2]+red_b4[3]));
	red_tax[3]=(*tax_sum) * (red_b4[3]/(red_b4[0]+red_b4[1]+red_b4[2]+red_b4[3]));

	red_af[0]=red_b4[0]-red_tax[0];
	red_af[1]=red_b4[1]-red_tax[1];
	red_af[2]=red_b4[2]-red_tax[2];
	red_af[3]=red_b4[3]-red_tax[3];

	*income_af=*income_b4-*tax_sum;

	//ou << a[i][j] << ",";
	ou<<"Name"<<","<<username<<","<<"Platform"<<","<<"Redbook"<<endl;
	ou<<""<<","<<"Before Tax income"<<","<<"Tax"<<","<<"After-Tax income"<<endl;
	ou<<red_cha[0]<<","<<red_b4[0]<<","<<red_tax[0]<<","<<red_af[0]<<endl;
	ou<<red_cha[1]<<","<<red_b4[1]<<","<<red_tax[1]<<","<<red_af[1]<<endl;
	ou<<red_cha[2]<<","<<red_b4[2]<<","<<red_tax[2]<<","<<red_af[2]<<endl;
	ou<<red_cha[3]<<","<<red_b4[3]<<","<<red_tax[3]<<","<<red_af[3]<<endl;

	ou<<"Before Tax Total income"<<","<<*income_b4<<endl;
	ou<<"Total Tax Payable"<<","<<*tax_sum<<endl;
	ou<<"After Tax Total income"<<","<<*income_af<<endl;

	ou.close();
}

void ins_cal(string ins_cha[],double ins_b4[],double ins_tax[],double ins_af[],int country,double *income_b4,double *tax_sum,double *income_af,string username) {

	ofstream ou("data_instagram.csv");

	//  string ins_cha[3]={"Live","Advertising","Drainage and realization"};
	cout<<"Please input your live income: ";
	cin>>ins_b4[0];
	cout<<"Please input your video income: ";
	cin>>ins_b4[1];
	cout<<"Please input your drainage and realization income: ";
	cin>>ins_b4[2];
	*income_b4=ins_b4[0]+ins_b4[1]+ins_b4[2];
	//cout<<*income_b4;
	switch(country) {
		case 1:
			//cout<<"hello";
			if(*income_b4>0&&*income_b4<=11850)
				*tax_sum=0;
			else if(*income_b4>11851&&*income_b4<=46350)
				*tax_sum=(*income_b4-11850)*0.2;
			else if(*income_b4>46351&&*income_b4<=150000)
				*tax_sum=(46350-11850)*0.2+(*income_b4-46350)*0.4;
			else if(*income_b4>150000)
				*tax_sum=(46350-11850)*0.2+(150000-46350)*0.4+(*income_b4-150000)*0.45;
			//cout<<*tax_sum;
		case 2:
			if(*income_b4>0&&*income_b4<=10275)
				*tax_sum=*income_b4*0.1;
			else if(*income_b4>10275&&*income_b4<=41775)
				*tax_sum=10275*0.1+(*income_b4-10275)*0.12;
			else if(*income_b4>41775&&*income_b4<=89075)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(*income_b4-41775)*0.22;
			else if(*income_b4>89075&&*income_b4<=170050)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(*income_b4-89075)*0.24;
			else if(*income_b4>170050&&*income_b4<=215950)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(170050-89075)*0.24+(*income_b4-170050)*0.32;
			else if(*income_b4>215950)
				*tax_sum=10275*0.1+(41775-10275)*0.12+(89075-41775)*0.22+(170050-89075)*0.24+(215950-170050)*0.32+(*income_b4-215950)*0.35;
		case 3:
			if(*income_b4>0&&*income_b4<=1000)
				*tax_sum=*income_b4*0.09;
			else if(*income_b4>1000&&*income_b4<=4000)
				*tax_sum=1000*0.09+(*income_b4-1000)*0.18;
			else if(*income_b4>4000&&*income_b4<=8000)
				*tax_sum=1000*0.09+(4000-1000)*0.18+(*income_b4-4000)*0.27;
			else if(*income_b4>8000)
				*tax_sum=1000*0.09+(4000-1000)*0.18+(8000-4000)*0.27+(*income_b4-8000)*0.36;

		case 4:
			if(*income_b4>0&&*income_b4<=1950000)
				*tax_sum=*income_b4*0.05;
			else if(*income_b4>1950000&&*income_b4<=3300000)
				*tax_sum=1950000*0.05+(*income_b4-1950000)*0.1;
			else if(*income_b4>3300000&&*income_b4<=6950000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(*income_b4-3300000)*0.2;
			else if(*income_b4>6950000&&*income_b4<=9000000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(*income_b4-6950000)*0.23;
			else if(*income_b4>9000000&&*income_b4<=18000000)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(*income_b4-9000000)*0.33;
			else if(*income_b4>215950)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(18000000-9000000)*0.33+(*income_b4-18000000)*0.4;
			else if(*income_b4>215950)
				*tax_sum=10275*0.05+(3300000-1950000)*0.1+(6950000-3300000)*0.2+(9000000-6950000)*0.23+(18000000-9000000)*0.33+(40000000-18000000)*0.4+(*income_b4-40000000)*0.45;
	}

	ins_tax[0]=(*tax_sum) * (ins_b4[0]/(ins_b4[0]+ins_b4[1]+ins_b4[2]));
	ins_tax[1]=(*tax_sum) * (ins_b4[1]/(ins_b4[0]+ins_b4[1]+ins_b4[2]));
	ins_tax[2]=(*tax_sum) * (ins_b4[2]/(ins_b4[0]+ins_b4[1]+ins_b4[2]));

	ins_af[0]=ins_b4[0]-ins_tax[0];
	ins_af[1]=ins_b4[1]-ins_tax[1];
	ins_af[2]=ins_b4[2]-ins_tax[2];

	*income_af=*income_b4-*tax_sum;

	//ou << a[i][j] << ",";
	ou<<"Name"<<","<<username<<","<<"Platform"<<","<<"Instagram"<<endl;
	ou<<""<<","<<"Before Tax income"<<","<<"Tax"<<","<<"After-Tax income"<<endl;
	ou<<ins_cha[0]<<","<<ins_b4[0]<<","<<ins_tax[0]<<","<<ins_af[0]<<endl;
	ou<<ins_cha[1]<<","<<ins_b4[1]<<","<<ins_tax[1]<<","<<ins_af[1]<<endl;
	ou<<ins_cha[2]<<","<<ins_b4[2]<<","<<ins_tax[2]<<","<<ins_af[2]<<endl;
	ou<<"Before Tax Total income"<<","<<*income_b4<<endl;
	ou<<"Total Tax Payable"<<","<<*tax_sum<<endl;
	ou<<"After Tax Total income"<<","<<*income_af<<endl;

	ou.close();
}

int main() {
	string utb_cha[3]= {"Video","Live","Advertising"};
	string bli_cha[5]= {"Live","Video","Event","Charging Plans","Advertising"};
	string red_cha[4]= {"Live","Advertising","Drainage and realization","Online Store"};
	string ins_cha[3]= {"Live","Advertising","Drainage and realization"};
	double utb_b4[3],bli_b4[5],red_b4[4],ins_b4[3];
	double utb_tax[3],bli_tax[5],red_tax[4],ins_tax[3];
	double utb_af[3],bli_af[5],red_af[4],ins_af[3];
	double income_b4=0,tax_sum=0,income_af=0;
	//double utb_af=0,bli_af=0,red_af=0,ins_af=0;
	
	int choose=0;
	
	while(1) {
		login_interface();
		
		string username;
		cout<<"Please enter your username: "<<endl;
		cin>>username;

		int country;
		cout<<"Please enter your country number:(1.UK/2.US/3.South Korea/4.Japan) "<<endl;
		cin>>country;
		
		cout <<"Please enter your choice number: " << endl;
		cin >> choose;	
			
		switch(choose) {
			case 1: {
				utb_cal(utb_cha,utb_b4,utb_tax,utb_af,country,&income_b4,&tax_sum,&income_af,username);
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				bli_cal(bli_cha,bli_b4,bli_tax,bli_af,country,&income_b4,&tax_sum,&income_af,username);
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				red_cal(red_cha,red_b4,red_tax,red_af,country,&income_b4,&tax_sum,&income_af,username);
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				ins_cal(ins_cha,ins_b4,ins_tax,ins_af,country,&income_b4,&tax_sum,&income_af,username);
				system("pause");
				system("cls");
				break;
			}
			case 5: {
				exit(1);
			}
		}
		break;
	}
	return 0;
}
