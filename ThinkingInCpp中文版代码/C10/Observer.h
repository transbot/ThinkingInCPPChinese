//: C10:Observer.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 观察者接口
#ifndef OBSERVER_H
#define OBSERVER_H

// 必须先声明Observable类，因为Observer接口中使用了Observable*类型
class Observable;

// 实参类，可以为空，作为传递的任何实参类型的基类
// 这样可以确保update方法能接受不同类型的数据
class Argument {};

// 观察者接口
class Observer {
public:
    // 当被观察对象发生变化时，由被观察对象调用以更新
    // 参数o是发生变化的被观察对象
    // 参数arg是传递的额外信息，可以是任意类型的对象，通过继承Argument类来实现
    virtual void update(Observable* o, Argument* arg) = 0;
    
    virtual ~Observer() {} // 虚析构函数确保正确清理资源
};
#endif // OBSERVER_H ///:~