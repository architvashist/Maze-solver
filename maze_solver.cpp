#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct arr
{
	int num;
	int right;
	int left;
	int up;
	int down;
	int cond;
};

void displays(stack <int> s)
{
	stack <int> news;
	int x;
	while(!s.empty())
	{
		x=s.top();
		s.pop();
		news.push(x);
	}
	while(!news.empty())
	{
		cout<<news.top()<<" ";
		news.pop();
	}
}


int main()
{
	int M,N,i,j;
	cin>>M>>N;
	arr ele[M][N];
	for(i=0;i<M;i++)
	{
		for(j=0 ; j<N ; j++)
		{
			cin>>ele[i][j].num;
			cin>>ele[i][j].up;
			cin>>ele[i][j].right;
			cin>>ele[i][j].down;
			cin>>ele[i][j].left;
			ele[i][j].cond=1;
		}
	}	
	stack <int> s;
	s.push(1);
	i=0,j=0;
	int fakei,fakej,movement;
//	right,down,up,left------>preference
	while(ele[i][j].num!=M*N && i>=0 && i<M && j>=0 && j<N)
	{
//		cout<<ele[i][j].num<<"  ";
		movement=0;
		ele[i][j].cond=2;
		if(ele[i][j].right==1 && ele[i][j+1].cond==1)
		{
			if(s.top()!=ele[i][j].num)
			{
				s.push(ele[i][j].num);
			}
			j++;
			movement=1;
		}
		else if(ele[i][j].down==1 && ele[i+1][j].cond==1)
		{
			if(s.top()!=ele[i][j].num)
			{
				s.push(ele[i][j].num);
			}
			i++;
			movement=1;
		}
		else if(ele[i][j].up==1 && ele[i-1][j].cond==1)
		{
			if(s.top()!=ele[i][j].num)
			{
				s.push(ele[i][j].num);
			}
			i--;
			movement=1;
		}
		else if(ele[i][j].left==1 && ele[i][j-1].cond==1)
		{
			if(s.top()!=ele[i][j].num)
			{
				s.push(ele[i][j].num);
			}
			j--;
			movement=1;
		}
		if(movement==0)
		{
			if(s.top()==ele[i][j].num)
			s.pop();
			ele[i][j].cond=-1;
			if(ele[i][j].right==1 && ele[i][j+1].cond==2)
			{
				j++;
			}
			else if(ele[i][j].down==1 && ele[i+1][j].cond==2)
			{
				i++;
			}
			else if(ele[i][j].up==1 && ele[i-1][j].cond==2)
			{
				i--;
			}
			else if(ele[i][j].left==1 && ele[i][j-1].cond==2)
			{
				j--;
			}
		}
		
		
	}
	s.push(ele[i][j].num);
//	cout<<ele[i][j].num;
	displays(s);
}

