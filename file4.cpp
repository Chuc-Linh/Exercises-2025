#include <iostream>
#include<cmath>
#include <fstream>

using namespace std;
void docfile(ifstream &file, int a[][50], int &d, int &c)
{
	file.open("input4.txt");
	file>>d>>c;
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)
		file>>a[i][j];
	}
	file.close();
}
void xuat(int a[][50], int d, int c)
{
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
void gtnntronggtlncot(int a[][50], int d, int c)
{
	int *b = new int[c];
	for(int i=0;i<c;i++)
	{
		int max=-999;
		for(int j=0;j<d;j++)
		{
			if(a[j][i]>max)
			max=a[j][i];
		}
		b[i]=max;
	}
	int min=99;
	for(int k=0;k<c;k++)
	{
		if(b[k]<min)
		min=b[k];
	}
	cout<<"gtnntronggtlncot "<< min<<endl;
}
void taomangmoi(int a[][50], int d, int c)
{
	int *b = new int[c];
	for(int i=0;i<c;i++)
	{
		int max=-999;
		for(int j=0;j<d;j++)
		{
			if(a[j][i]>max)
			max=a[j][i];
		}
		b[i]=max;
	}
	int p[50][50];
	for(int m=0;m<c;m++)
	{
		for(int n=0;n<d;n++)
		{
		p[n][m]=a[n][m]*b[m];
	}
}
	xuat(p,d,c);
}
int main() {

	ifstream file;
	int a[50][50], d,c;
	docfile(file,a,d,c);
	xuat(a,d,c);
	gtnntronggtlncot(a,d,c);
	taomangmoi(a,d,c);
    return 0;
}
