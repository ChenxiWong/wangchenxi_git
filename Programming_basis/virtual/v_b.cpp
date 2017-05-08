#include <iostream>
using namespace std;

class base_class
{
public:
    virtual void v_func1()
    {
        cout << "This is base_class's v_func1()" << endl;
    }
    virtual void v_func2()
    {
        cout << "This is base_class's v_func2()" << endl;
    }
    virtual void v_func3()
    {
        cout << "This is base_class's v_func3()" << endl;
    }
};

int main()
{
    typedef void(*func_pointer)(void);
    cout<<sizeof(func_pointer)<<endl;
    cout<<sizeof(func_pointer*)<<endl;
    cout<<sizeof(int*)<<endl;
    cout<<sizeof(int)<<endl;
    // 查看 base_class 的虚函数表
    base_class bc;
    cout << "base_class 的虚函数表首地址为：" << (func_pointer*)&bc << endl; // 虚函数表地址存在对象的前四个字节
    cout << "base_class 的 第一个函数首地址：" << *(func_pointer**)&bc + 0 << endl; // 指针运算看不懂？没关系，一会解释给你听
    cout << "base_class 的 第二个函数首地址：" << *(func_pointer**)&bc + 1 << endl;
    cout << "base_class 的 第三个函数首地址：" << *(func_pointer**)&bc + 2 << endl;
    cout << "base_class 的 结束标志: " << *(* (func_pointer**)&bc + 3 ) << endl;
    
    // 通过函数指针调用函数，验证正确性
    func_pointer fp = NULL;
    fp = *(*((func_pointer**)&bc)+0); // v_func1()
    fp();
    fp = *(*((func_pointer**)&bc)+1); // v_func1()
    fp();
    fp = *(*((func_pointer**)&bc)+2); // v_func1()
    fp();
#if 0
    fp = (func_pointer)(*(*((func_pointer*)&bc))); // v_func1()
    fp();
#endif
    return 0;
}
