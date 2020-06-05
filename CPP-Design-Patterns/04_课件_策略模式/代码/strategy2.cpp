
class TaxStrategy{
public:
    virtual double Calculate(const Context& context)=0;
    virtual ~TaxStrategy(){}
};


class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};



//扩展，在新的文件中添加新的类，单独编译
//*********************************
class FRTax : public TaxStrategy{
public:
	virtual double Calculate(const Context& context){
		//.........
	}
};

//稳定，复用
class SalesOrder{
private:
    //放置一个多态指针，指向不同的子类
    TaxStrategy* strategy;

public:
    SalesOrder(StrategyFactory* strategyFactory){
        //在工厂内部建立相应的子类
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder(){
        delete this->strategy;
    }

    public double CalculateTax(){
        //...
        //构建上下文参数
        Context context();
        
        double val = 
            strategy->Calculate(context); //多态调用
        //...
    }
    
};




