// 1115. 交替打印FooBar
// 我们提供一个类：

// class FooBar {
//   public void foo() {
//     for (int i = 0; i < n; i++) {
//       print("foo");
//     }
//   }

//   public void bar() {
//     for (int i = 0; i < n; i++) {
//       print("bar");
//     }
//   }
// }
// 两个不同的线程将会共用一个 FooBar 实例。其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。

// 请设计修改程序，以确保 "foobar" 被输出 n 次。

 

// 示例 1:

// 输入: n = 1
// 输出: "foobar"
// 解释: 这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
// 示例 2:

// 输入: n = 2
// 输出: "foobarfoobar"
// 解释: "foobar" 将被输出两次。
#include <semaphore.h>
#include <functional>
#include <iostream>
#include <mutex>
class FooBar {
private:
    int n;
    std::mutex m1, m2;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            m1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            m2.unlock();
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            m2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            m1.unlock();
        }
    }
};

int main() {
    FooBar test(2);

}