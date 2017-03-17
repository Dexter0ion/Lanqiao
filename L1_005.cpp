//类对象数组初次使用！ 
#include<iostream>
#include<string>
#include<string.h>
#define maxn 1001
using namespace std;

class Student
{
	private:
		string Id;
		int preSet;
		int examSet;
	
	public:
		Student()
		{
			Id="";
			preSet=0;
			examSet=0;
		}
		Student(string& id_,int pre_,int exam_)
		{
			Id = id_;
			preSet=pre_;
			examSet=exam_;
		}
		
		int getPreSet()
		{
			return preSet;
		}
		
		void disResult()
		{
			cout<<Id<<" "<<examSet<<endl;
		}
}stu[maxn];

int main()
{
	int N;
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		string id_input;
		int pre_input,exam_input;
		cin>>id_input>>pre_input>>exam_input;
		stu[i] = Student(id_input,pre_input,exam_input);
	}
	
	int M;
	cin>>M;
	int setPick[maxn];
	memset(setPick,0,sizeof(setPick));
	for(int j=0;j<M;j++)
	{
		cin>>setPick[j];
	}
/*	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(stu[i].getPreSet()==setPick[j])
				stu[i].disResult();
		 } 
	} 
*/	
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(stu[j].getPreSet()==setPick[i])
				stu[j].disResult();
		}
	 } 

	return 0;
}
