#include <iostream>
#include <fstream>

using namespace std;

int tongso(ifstream &file)
{
	int dem=0,temp;
	while(file>>temp)
	dem++;
	file.clear();
	file.seekg(0,ios::beg);
	return dem;
	file.close();
}
void docfile(ifstream &file, int *a, int &n)
{
	file.open("input.txt");
	n=tongso(file);
	for(int i=0;i<n;i++)
	file>>a[i];
	file.close();
}
 int ucln(int a, int b)
 {
 	while(b!=0)
 	{
 		int t=a%b;
		 a=b;b=t;	
	}
	return a;
 }
 void sntcungnhau(int a[], int n,ofstream &file)
 {
 	int dem=0;
 	for(int i=0;i<n;i++)
 	{
 		for(int j=i+1;j<n;j++)
 		{
 			if(ucln(a[i],a[j])==1) dem++;
		}
	}
	file<<"so luong snt cung nhau la "<<dem;
 }
 void hv(int &a, int &b)
 {
 	int t=a;a=b;b=t;
 }
 void selection(int a[], int n)
 {
 	
 	for(int i=0;i<n-1;i++)
 	{
 		int min_index =i;
 		for(int j=i+1;j<n;j++)
 		{
 			if(a[i]>a[j])
 			min_index=j;
		}
		hv(a[i],a[min_index]);
	}
 }
 void nhatnhi(int a[], int n, ofstream &file)
 {
 	selection(a,n);
 	file<<"gtr lon nhat "<<a[n-1]<<endl;
 	file<<" gtr lon nhi "<<a[n-2]<<endl;
 }
 void dainhat(int a[], int n, ofstream &file)
 {
 	int dem=1;
 	for(int i=0;i<n-1;i++)
 	{
 		if(a[i]<a[i+1])
 			dem++;
 		else dem=1;
	}
	file<<"day con dai nhat khong giam co "<<dem<<" phan tu";
 }
int main() {
    ifstream file;
	int n=tongso(file);
    int *a=new int [n];
    docfile(file,a,n);
    
    ofstream file1;
    file1.open("output.txt");
    
    file1<<"tong so luong phan tu la "<<n<<endl;
    sntcungnhau(a,n,file1);
    nhatnhi(a,n,file1);
    dainhat(a,n,file1);
    
    delete []a;
    file1.close();
    return 0;
}

