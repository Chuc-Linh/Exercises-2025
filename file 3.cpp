#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void docfile(ifstream &file, int a[], int &n)
{
	file.open("intput3.txt");
	file>>n;
	for(int i=0;i<n;i++)
	file>>a[i];
	file.close();
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
void demsnt(int a[], int n, ofstream &file)
{
	int dem=0;
	for(int i=0;i<n;i++)
		if(snt(a[i])==1) dem++;
	file<<"sl snt la "<<dem<<endl;
}
void tongduong(int a[], int n, ofstream &file)
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
		tong+=a[i];
	}
	file<<"tong cac so nguyen duong la "<<tong<<endl;
}
void hv(int &a, int &b)
{
	int t=a;a=b;b=t;
}
void bubble(int a[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		if(a[j]<a[j+1])
			hv(a[j],a[j+1]);	
	}
}
void sx(int a[], int n,ofstream &file)
{
	bubble(a,n);
	file<<" mang sau khi duoc xep be dan ";
	for(int k=0;k<n;k++)
		file<<a[k]<<" ";
}
int main() {

	ifstream file; int n;
	int a[50];
	docfile(file,a,n);
	ofstream file1;
	file1.open("output.txt");
	demsnt(a,n,file1);
	tongduong(a,n,file1);
	sx(a,n,file1);
	
	file1.close();
	
    return 0;
}

