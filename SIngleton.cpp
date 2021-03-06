

#include <iostream>
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard

std::mutex mtx;

using namespace std;
class MySingleton 
{
private:
        /* So that withing this class only object can create  */
        MySingleton() 
        {
             i = 10;
            cout<<"Singleton constructor"<<endl;
        }
        MySingleton(const MySingleton&) = delete;
        MySingleton& operator=(const MySingleton&) = delete;
        static MySingleton* ptr;    
    
public:
         int i;
         /* it is static because there is no object available at client side and only one copy of
         object we want to maintain*/
         //std::lock_guard<std::mutex> lck(mtx);
         static MySingleton* getInstance()
         {
             if(ptr == NULL)
             {
                ptr = new MySingleton();
             }

             return ptr;
         }
         
         ~MySingleton()
          {
              delete ptr;
          }
             
         

};

 MySingleton* MySingleton::ptr = nullptr;    
    

/* We have to initialize  static member outside of class */

//MySingleton* MySingleton::ptr =NULL;
int main() 
{

MySingleton* FirstPtr = MySingleton::getInstance();
cout<<"Default value of i = "<<FirstPtr->i<<endl;

MySingleton* SecondPtr = MySingleton::getInstance();
FirstPtr->i = 20;
cout<<"Changed the value of i using 'FirstPtr' however accesing vlue of i by SecondPtr = " 
    <<SecondPtr->i<<endl;
    
return 0;

}
