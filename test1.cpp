#include<iostream>
#include<cstdlib>
#include<ctime>
using std::cout;
class Grand
{
private:
	int hold;
public:
	Grand(int h=0):hold(h){}
	virtual void Speak()const{cout<<"I am a grand class!\n";}
	virtual int Value()const{return hold;}
};
class Super:public Grand
{
public:
	Super(int h=0):Grand(h){}
	void Speak()const{cout<<"I¡¡am a super class!\n";}
	virtual void Say()const{cout<<"I hold the super value of"<<Value()<<"!\n";}
};
class Magnificent:public Super
{
private:
	char ch;
public:
	Magnificent(int h=0,char c='A'):Super(h),ch(c){}
	void Speak()const{cout<<"I am a magnificent class!!!\n";}
	void Say()const{cout<<"I hold the character "<<ch<<"and the integer"<<Value()<<"!\n";}
};
Grand *GetOne();
int main()
{
	std::srand(std::time(0));
	Grand *pg;
	Super *ps;
	for(int i=0;i<5;i++)
	{
		pg=GetOne();
	    pg->Speak();
		if(ps=dynamic_cast<Super *>(pg))
			ps->Say();
	}
	std::cin.get();
	return 0;
}
Grand *GetOne()
{
	
	Grand *p;
	switch(std::rand()%3)
	{
	case 0:
		p=new Grand(std::rand()%100);
		break;
	case 1:
		p=new Super(std::rand()%100);
		break;
	case 2:
		p=new Magnificent(std::rand()%100,'A'+std::rand()%26);
		break;
	}
	return p;
}

