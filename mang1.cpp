#include <iostream>
#include<ctime>
#include <cstdlib>

using namespace std;
int *taoMangNgauNhien(int &n) { 
	cout<<"nhap sl phan tu " ; cin>>n;
    int* arr = new int[n]; 
    for (int i = 0; i < n; i++) {  
        arr[i] = rand() % 100; 
    }  
    return arr; 
    
}  
void xuat(int a[],int n)
{
	for (int i = 0; i < n; i++) 
	cout<<a[i]<<" ";
	cout<<endl;
}
long long tbcongduong(int a[], int n)
{
	int tong=0,dem=0;
	for (int i = 0; i < n; i++) 
	{
		if(a[i]%2==0)
		{
			dem++;
			tong+=a[i];
		}
	}
	if(dem==0) dem=1;
	tong=tong/dem;
	return (long long)tong;
}
int snt(int a)
{
	if(a<2) return 0;
	for(int i=2;i<=a/2;i++)
		if(a%i==0)
			 return 0;
	return 1;
}
void chen(int a[], int n)
{
	for(int i=1;i<n;i++)
	{
		int x=a[i], pos=i-1;
		while(pos>=0&&x<a[pos])
		{
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}
int sntlnnhonhomang(int a[], int n)
{
	chen(a,n);
	for(int i=a[0]-1;i>=2;i--)
	{
		if(snt(i))
			{
				return i;
			}
		else if(i<2)
		return -1;
	}
	
}
void xeptheoyeucau(int a[], int n)
{
	for (int i = 0; i < n; i++) 
	{
		if(a[i]%2==0) a[i]*=-1;
	}
	chen(a,n);
	for (int j = 0; j < n; j++) 
		if(a[j]%2==0) a[j]*=-1;
	xuat(a,n);
}
int main() {
	int n;
	int *a=taoMangNgauNhien(n);//chu y
	
	xuat(a,n);
	cout<<tbcongduong(a,n)<<endl;
	cout<< sntlnnhonhomang(a,n)<<endl;
	xeptheoyeucau(a,n);
	
	delete []a;
    return 0;
}
