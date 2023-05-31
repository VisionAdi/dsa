#include<iostream>
using namespace std;
void downadjust(int heap[],int i)
{
	int n,temp,j,flag=1;
	n=heap[0];
	while (2*i<=n && flag==1)
	 {
  		j=2*i;
  		if (j+1<=n && heap[j+1]>heap[j])
		  {
	  		j=j+1;
		  }
		if (heap[i]>heap[j])
		  {
		 	flag=0;
		  }
		  else
		  {
		     temp=heap[i];
		     heap[i]=heap[j];
		     heap[j]=temp;
		     i=j;
		  }

	 }

}

void createmax(int heap[])
{
  int i,n;
  n=heap[0];
  for (i=n/2;i>=1;i--)
  {
    downadjust(heap,i);

  }
}
void display(int heap[])
{
 	int i,n;
	n=heap[0];
	for (i=1;i<=n;i++)
	{
  		cout<<heap[i]<<" "<<"\n";
	}
}

void sort(int heap[])
{
    int last,temp;
    while(heap[0]>1)
    {
        last=heap[0];
        temp=heap[1];
        heap[1]=heap[last];
        heap[last]=temp;
        heap[0]--;
        downadjust(heap,1);
    }
}

int main()
{
  int i,n,heap[20];
  cout<<"ENTER NO OF ELEMENTS: ";
  cin>>n;
  heap[0]=n;
  cout<<"ENTER ELEMENTS: ";
  for (i=1;i<=n;i++)
  {
	cin>>heap[i];
  }
  
cout<<"The entered heap is: "<<" ";
createmax(heap);
display(heap);
cout<<"The sorted heap: "<<" ";
sort(heap);
heap[0]=n;
display(heap);
cout<<"The maximum element is : "<<heap[n];
cout<<"\nThe minimum element is : "<<heap[1];
}



























