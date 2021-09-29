#include <iostream>
#include "thread_local_connection.hpp"
void task(const std::string &data, int id) {
    get_conn().send(data);
    for (int i = 0;i <10;i++) {
        std::cout << "I am thread:" << id << " sending data:" << data << std::endl;
    }
}
int main() {
    std::string str1 = "www.baidu.com11";
    std::string str2 = "www.baidu.com22";
    std::string str3 = "www.baidu.com33";
    boost::thread t1(&task, ref(str1), 1);
    boost::thread t2(&task, ref(str2), 2);
    boost::thread t3(&task, ref(str3), 3);
    
    t1.join();
    t2.join();
    t3.join();

    return 0;
}