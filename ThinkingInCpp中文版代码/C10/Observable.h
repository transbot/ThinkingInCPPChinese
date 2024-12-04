//: C10:Observable.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 被观察者类
#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <set>
#include "Observer.h"

class Observable {
    bool changed; // 标记是否已更改
    std::set<Observer*> observers; // 该set存储了观察者

protected:
    virtual void setChanged() { changed = true; } // 设置已更改标记
    virtual void clearChanged() { changed = false; } // 清除已更改标记

public:
    virtual void addObserver(Observer& o) { // 添加观察者
        observers.insert(&o);
    }
    virtual void deleteObserver(Observer& o) { // 删除特定观察者
        observers.erase(&o);
    }
    virtual void deleteObservers() { // 删除所有观察者
        observers.clear();
    }
    virtual int countObservers() { // 观察者数量
        return observers.size();
    }
    virtual bool hasChanged() { return changed; } // 查询是否已更改

    // 如果对象已更改，则通知所有观察者
    virtual void notifyObservers(Argument* arg = 0) {
        if (!hasChanged()) return;
        clearChanged(); // 不再“已更改”
        for (auto it = observers.begin(); it != observers.end(); ++it)
            (*it)->update(this, arg);
    }

    virtual ~Observable() {} // 虚析构函数确保正确清理资源
};
#endif // OBSERVABLE_H ///:~
