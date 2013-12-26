#include<iostream>
#include<fstream>
#include<vector>
#include<signal.h>

struct node
{
	int value;
	node * alpha[26];		
};


void addString(char * str,node * root)
{
	int k=0,j=strlen(str);
	node * p=root;
	while(k < j)	
	{
		if(str[k] >= 97)
		{
			if(p->alpha[str[k]-'a']==NULL)
			{
				p->alpha[str[k]-'a']=(node *)malloc(sizeof(node));
				p->alpha[str[k]-'a']->value=0;
				for(int i=0;i<26;i++)
					p->alpha[str[k]-'a']->alpha[i]=NULL;
			}
			p=p->alpha[str[k]-'a'];
			k++;	
		}
		else
		{
			if(p->alpha[str[k]-'A']==NULL)
			{
				p->alpha[str[k]-'A']=(node *)malloc(sizeof(node));
				p->alpha[str[k]-'A']->value=0;
				for(int i=0;i<26;i++)
					p->alpha[str[k]-'A']->alpha[i]=NULL;
			}
			p=p->alpha[str[k]-'A'];
			k++;	
			
		}
	}
		p->value=1;
	return;
}

bool searchstring(char * str,node * root)
{
	node * p=root;
	int k=0,i=0,n=strlen(str);
	while(i<n)
	{
		if(str[i]>=97)
		{
			p=p->alpha[str[i]-'a'];
			
		}
		else
		{
			p=p->alpha[str[i]-'A'];	
		}
		if(p==NULL)
		{
				k=1;
				break;
		}
			i++;		
	}
	if(k==1 || p->value==0)
		return false;
	else
		return true;
}

int main()
{
	int n;
	char str[100];
	node * root=(node *)malloc(sizeof(node));
	root->value=0;
	for(int i=0;i<26;i++)
	{
		root->alpha[i]=NULL;
	}
	std::ifstream infile("words.txt");
	while(!infile.eof())
	{
		infile.getline(str,100,'\n');
		addString(str,root);
	}
	while(1)
	{
		printf("\nEnter string   : ");
		std::cin.getline(str,100,'\n');
		if(searchstring(str,root))
			printf("Matched\n");
		else
			printf("NOT MATCHED\n");
	}	
	return 0;	
}
