	
       	#include<iostream>
#include<string.h>
	using namespace std;
	struct node{
	int duration,priority;
	int price;
	string j_name;
	
	};
	int main()
	{
	int y;
	cout<<"Enter the no. of jobs to be executed";
	cin>>y;
	node *x=new node[y];
	cout<<"Job name\t Duration \t Priority\n";
	for(int i=0;i<y;i++)
	{
	cin>>x[i].j_name;
	cin>>x[i].duration>>x[i].priority;
	x[i].price=x[i].duration/x[i].priority;
	
	}
	
	for(int i=y;i>0;i--)
	for(int j=0;j<i-1;j++)
	if(x[j].price>x[j+1].price)
	{
	node t;
	t=x[j];
	x[j]=x[j+1];
	x[j+1]=t;
	}
	cout<<"Result::\n";
	for(int i=0;i<y;i++)
	{
	cout<<x[i].j_name<<"\t"<<x[i].price<<"\n";
	}
	return 0;
	}

