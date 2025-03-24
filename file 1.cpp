#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int n,k;
	ifstream file;
	file.open("capso.txt");
	file>>n>>k;
	int a[20];
	for(int i=0;i<n;i++)
	{
		file>>a[i];
	}

	//ghi file
	
	ofstream file1;
	file1.open("C:\\Users\\Admin\\Desktop\\capsoout.txt");
	for(int m=0;m<n-1;m++)
	{
		for(int j=m+1;j<n;j++)
		{
			if(a[m]+a[j]==k)
			file1<<a[m]<<" "<<a[j]<<endl;
		}
	}
	
	file1.close();
	return 0;
}

