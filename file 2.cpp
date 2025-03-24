#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
void docfile(ifstream &file, int a[][50], int &d, int &c)
{
	file.open("input.txt");
	file>>d>>c;
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)
		{
			file>>a[i][j];
		}
	}
}
int tinhtong(int a[][50], int d, int c)
{
	int tong=0;
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)
		{
			tong+=a[i][j];
		}
	}
	return tong;
}
void tongdong(int a[][50], int d, int c,ofstream &file)
{

	for(int i=0;i<d;i++)
	{	
		int tong=0;
		for(int j=0;j<c;j++)
		{
			tong=tong+a[i][j];
		}
		file<<"tong dong thu "<<i+1<<tong<<endl;
	}
}
void tongcot(int a[][50], int d, int c,ofstream &file)
{

	for(int i=0;i<c;i++)
	{	
		int tong=0;
		for(int j=0;j<d;j++)
		{
			tong=tong+a[j][i];
		}
		file<<"tong cot thu "<<i+1<<tong<<endl;
	}
}
int snt(int a)
{
	if(a<2) return 0;
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0) return 0;
	}
	return 1;
}
void ktr(int a[][50], int d, int c, ofstream &file)
{
	int le=0,chan=0,snto=0;
	for(int i=0;i<d;i++)
	{	
		for(int j=0;j<c;j++)
		{
			if(snt(a[i][j])) snto++;
			else if(a[i][j]%2==0) chan++;
			else le++;
		}
	}
	file<<"tong chan "<<chan<<endl;
	file<<"tong le "<<le<<endl;
	file<<"tong snt "<<snto<<endl;
}
int main()
{
	ifstream file;
	int d,c;
	int a[50][50];	
	docfile(file,a,d,c);
	
	ofstream file1;
	file1.open("output.txt");
	file1<<tinhtong(a,d,c)<<endl;
	tongdong(a,d,c,file1);
	tongcot(a,d,c,file1);	
	ktr(a,d,c,file1);
	file1.close();
	return 0;
}


