#include<iostream>
using namespace std;


class Desktop{
    string monitor;
    string keyboard;
    string CPU;
    string motherboard;
    public:
        void setmonitor(string monitor_){
            this->monitor=monitor_;
        }


        void setkeyboard(string keyboard_){
            this->keyboard=keyboard_;
        }

        void setCPU(string CPU_){
            this->CPU=CPU_;
        }

        void setmotherboard(string motherboard_){
            this->motherboard=motherboard_;
        }

        void showspecs(){
            cout<<"\nmonitor::"<<this->monitor;
            cout<<"\nkeyboard"<<this->keyboard;
            cout<<"\nCPU"<<this->CPU;
            cout<<"\nmotherboard"<<this->motherboard;
        }
};

class DesktopBuilder{
    protected:
        Desktop* desktop;
    public:
        DesktopBuilder(){
            desktop=new Desktop();
        }

        virtual void buildMonitor()=0;
        virtual void buildCPU()=0;
        virtual void buildKeyboard()=0;
        virtual void buildMotherBoard()=0;
        virtual Desktop* getDesktop(){
            return desktop;
        }
};

class DellDesktopBuilder: public DesktopBuilder{
        void buildMonitor(){
            desktop->setmonitor("dellMOnitor");
        }
        void buildCPU(){
            desktop->setCPU("dellCPU");
        }
        void buildKeyboard(){
            desktop->setkeyboard("dellKeyboard");
        }
        void buildMotherBoard(){
            desktop->setmotherboard("dellMotherboard");
        }
};

class HPDesktopBuilder: public DesktopBuilder{
        void buildMonitor(){
            desktop->setmonitor("HPMOnitor");
        }
        void buildCPU(){
            desktop->setCPU("HPCPU");
        }
        void buildKeyboard(){
            desktop->setkeyboard("HPKeyboard");
        }
        void buildMotherBoard(){
            desktop->setmotherboard("HPMotherboard");
        }
};

class DesktopDirector{
    DesktopBuilder* desktopbuilder;
    public:
        DesktopDirector(DesktopBuilder* desktopbuilder_){
            desktopbuilder=desktopbuilder_;
        }

        Desktop* getDesktop(){
            return desktopbuilder->getDesktop();
        }

        Desktop* buildDesktop(){
            desktopbuilder->buildCPU();
            desktopbuilder->buildKeyboard();
            desktopbuilder->buildMonitor();
            desktopbuilder->buildMotherBoard();
            return desktopbuilder->getDesktop();
        }
};

int main(){
    HPDesktopBuilder* hp=new HPDesktopBuilder();
    DellDesktopBuilder* dell=new DellDesktopBuilder();
    DesktopDirector *d1=new DesktopDirector(hp);
    DesktopDirector* d2 = new DesktopDirector(dell);

    Desktop *desktop1=d1->buildDesktop();
    Desktop* desktop2=d2->buildDesktop();
    desktop1->showspecs();
    desktop2->showspecs();
    return 0;
}