
class Memento
{
    string state;
    //..很多状态
public:
    Memento(const string & s) : state(s) {}
    string getState() const { return state; }
    void setState(const string & s) { state = s; }
};



class Originator
{
    string state;
    //..很多状态
public:
    Originator() {}
    Memento createMomento() {
        Memento m(state); //具体实现可能非常复杂
        return m;
    }
    void setMomento(const Memento & m) {
        state = m.getState();
    }
};



int main()
{
    Originator orginator;
    
    //捕获对象状态，存储到备忘录
    Memento mem = orginator.createMomento();
    
    //... 改变orginator状态
    
    //从备忘录中恢复
    orginator.setMomento(memento);

   
    
}
