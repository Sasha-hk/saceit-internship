#pragma once
#ifndef INHERITANCE_H
#define INHERITANCE_H

class B1 {
  private:
  protected:
    int b1;
  public:
    B1();
    B1(int b1);
};

class B2 {
  private:
  protected:
    int b2;
  public:
    B2();
    B2(int b2);
};

class D1 :
  public B1,
  private B2
{
  private:
  protected:
    int d1;
  public:
    D1();
    D1(int d1, int b1);
};

class D2 : private D1 {
  private:
  protected:
    int d2;
  public:
    D2();
    D2(int d2);
};

class B3 {
  private:
  protected:
    int b3;
  public:
    B3();
    B3(int b3);
};

class D3 :
  public D2,
  private B3
{
  private:
  protected:
    int d3;
  public:
    D3();
    D3(int d3, int d2);
};

#endif
