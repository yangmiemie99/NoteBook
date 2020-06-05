class ISubject{
public:
    virtual void process();
};


class RealSubject: public ISubject{
public:
    virtual void process(){
        //....
    }
};

class ClientApp{
    
    ISubject* subject;
    
public:
    
    ClientApp(){
        //客户程序中可能由于安全原因，性能原因等等，拿不到这个RealSubject
        subject=new RealSubject();
    }
    
    void DoTask(){
        //...
        subject->process();
        
        //....
    }
};