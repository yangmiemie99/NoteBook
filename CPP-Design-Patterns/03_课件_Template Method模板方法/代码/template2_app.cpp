//应用程序开发人员
#include <iostream>
#include "template2_lib.cpp"
using std::cout;
using std::endl;
class Application : public Library {
protected:
	virtual bool Step2(){
		//... 子类重写实现
		cout << "Step2" << endl;
		return true;
    }

    virtual void Step4() {
		//... 子类重写实现
		cout << "Step4" << endl;
    }
};




int main()
{
	{
	    Library* pLib=new Application();
	    pLib->Run();

		delete pLib;
	}
}




