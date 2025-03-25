#include <iostream>
#include<ctime>
#include <cstdlib>

using namespace std;
int *mang1(int a[][50], int n)
{
	int *b=new int[n*n];
	for(int k=0;k<n;k++)
	{
		for(int m=0;m<n;m++)
		{
			b[k*n+m]=a[k][m];
		}
	}
	return b;
}
void xuat(int **a, int n)
{	
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<n;k++)
			cout<<a[i][k]<<" ";
		cout<<endl;
	}
}
int **mang2(int a[], int n)
{
	int **b=new int *[n*n];
	 
    for (int i = 0; i < n; i++) {  
        b[i] = new int[n]; 
        for (int j = 0; j < n; j++) {  
            b[i][j] = a[i * n + j];  
        }  
    }  
    return b; 
}
void taomang (int a[][50], int &n)
{	cout<<"nhap so dong, cot ";
	cin>>n;
	int m;
	int *b=new int[n*n];
	cout<<"nhap sl so 0 ";
	cin>>m;
	while(m>(n*n)/2||m<1)	
	{
		cout<<"nhap lai sl so 0 ";
		cin>>m;
	}
	int *h=mang1(a,n); 
	int* found = new int[n * n];
	cout<<"chon cac vi tri co gia tri 0";
	for(int i=0;i<m;i++)
	{
		int index;
		cin>>index;
		
		h[index]=0;
		found[index]=1;
	}
	 for (int j = 0; j < n * n; j++) {  
        if (found[j] != 1) 
            h[j] = rand() % 100; 
        
    }	 
	int **v=mang2(h,n)	;
	xuat(v,n);
	delete []h;
	delete []found;
	for (int i = 0; i < n; i++) {  
        delete[] v[i];  // Gi?i phóng các hàng trong m?ng 2D  
    }  
    delete[] v;         // Gi?i phóng con tr? chính c?a m?ng 2D  
}  

int main() {
	int n;
	int a[50][50];
	taomang(a,n);
	
	

    return 0;
}
