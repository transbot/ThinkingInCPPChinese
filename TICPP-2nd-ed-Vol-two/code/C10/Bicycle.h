//: C10:Bicycle.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Defines classes to build bicycles;
// Illustrates the Builder design pattern.
#ifndef BICYCLE_H
#define BICYCLE_H
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include "../purge.h"
using std::size_t;

class BicyclePart {
public:
  enum BPart { FRAME, WHEEL, SEAT, DERAILLEUR,
    HANDLEBAR, SPROCKET, RACK, SHOCK, NPARTS };
private:
  BPart id;
  static std::string names[NPARTS];
public:
  BicyclePart(BPart bp) { id = bp; }
  friend std::ostream&
  operator<<(std::ostream& os, const BicyclePart& bp) {
    return os << bp.names[bp.id];
  }
};

class Bicycle {
  std::vector<BicyclePart*> parts;
public:
  ~Bicycle() { purge(parts); }
  void addPart(BicyclePart* bp) { parts.push_back(bp); }
  friend std::ostream&
  operator<<(std::ostream& os, const Bicycle& b) {
    os << "{ ";
    for(size_t i = 0; i < b.parts.size(); ++i)
      os << *b.parts[i] << ' ';
    return os << '}';
  }
};

class BicycleBuilder {
protected:
  Bicycle* product;
public:
  BicycleBuilder() { product = 0; }
  void createProduct() { product = new Bicycle; }
  virtual void buildFrame() = 0;
  virtual void buildWheel() = 0;
  virtual void buildSeat() = 0;
  virtual void buildDerailleur() = 0;
  virtual void buildHandlebar() = 0;
  virtual void buildSprocket() = 0;
  virtual void buildRack() = 0;
  virtual void buildShock() = 0;
  virtual std::string getBikeName() const = 0;
  Bicycle* getProduct() {
    Bicycle* temp = product;
    product = 0;  // Relinquish product
    return temp;
  }
};

class MountainBikeBuilder : public BicycleBuilder {
public:
  void buildFrame();
  void buildWheel();
  void buildSeat();
  void buildDerailleur();
  void buildHandlebar();
  void buildSprocket();
  void buildRack();
  void buildShock();
  std::string getBikeName() const { return "MountainBike";}
};

class TouringBikeBuilder : public BicycleBuilder {
public:
  void buildFrame();
  void buildWheel();
  void buildSeat();
  void buildDerailleur();
  void buildHandlebar();
  void buildSprocket();
  void buildRack();
  void buildShock();
  std::string getBikeName() const { return "TouringBike"; }
};

class RacingBikeBuilder : public BicycleBuilder {
public:
  void buildFrame();
  void buildWheel();
  void buildSeat();
  void buildDerailleur();
  void buildHandlebar();
  void buildSprocket();
  void buildRack();
  void buildShock();
  std::string getBikeName() const { return "RacingBike"; }
};

class BicycleTechnician {
  BicycleBuilder* builder;
public:
  BicycleTechnician() { builder = 0; }
  void setBuilder(BicycleBuilder* b) { builder = b; }
  void construct();
};
#endif // BICYCLE_H ///:~
