#include "json.hpp"
using json=nlohmann::json;
#include <iostream>
#include <vector>
#include <map>
using namespace std;
//json序列化实例代码1
void func1()
{
    json js;
    js["msg"]="hello, what are you doing now?";
    js["msg_type"]=2;
    js["from"]="zhang san";
    js["to"]="li si";
   

    cout<<js<<endl;
}
//json序列化实例代码2
void func2()
{ 
    json js;
    // 添加数组
    js["id"] = {1,2,3,4,5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu sho"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    cout << js << endl;
}
//json序列化实例代码3
void func3()
{
    json js;
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(1);
    js["list"] = vec;
    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;

    string sendBuf=js.dump();

    cout<<sendBuf<<endl;
}
//json反序列化实例代码1
string func4()
{
    json js;
    js["msg"]="hello, what are you doing now?";
    js["msg_type"]=2;
    js["from"]="zhang san";
    js["to"]="li si";
   
    string sendBuf=js.dump();
    //cout<<js<<endl;
    return sendBuf;
}
int main()
{
    string recvBuf=func4();
    json jsonBuf=json::parse(recvBuf);
    cout<<jsonBuf["msg"]<<endl;
    cout<<jsonBuf["msg_type"]<<endl;
    cout<<jsonBuf["from"]<<endl;
    cout<<jsonBuf["to"]<<endl;
    return 0;
}