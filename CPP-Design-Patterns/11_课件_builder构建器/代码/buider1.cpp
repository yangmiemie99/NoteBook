class House
{

public:
	//把这个在往外拆
	void Init(){
		this -> BuilderPart1();
		for(int i = 0; i <4; i++){
			this -> BuilderPart2();
		}
		bool flag = this -> BuilderPart3();

		if(flag){
			this -> BuilderPart4();
		}
		this -> BuilderPart5();
	}

	virtual ~HouseBuilder(){}
protected:
	virtual void BuildPart1()=0;
    virtual void BuildPart2()=0;
    virtual void BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;

}
class StoneHouse:public House{
protected:
	virtual void BuildPart1(){
	}
    virtual void BuildPart2(){

    }
    virtual void BuildPart3(){

    }
    virtual void BuildPart4(){

    }
    virtual void BuildPart5(){

    }
}
int main(){
	House* pHouse = new StoneHouse();
	pHouse -> Init();
}