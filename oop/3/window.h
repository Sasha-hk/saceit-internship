#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>

using namespace std;

class Window {
  private:
  protected:
    int top;
    int left;
    int right;
    int bottom;
    string title;

    void drawBox(int, int, int, int);

  public:
    Window(
      int top,
      int left,
      int right,
      int bottom,
      string title
    );
    void enter();
    void display();
    void print();
    void getxy(int*);
    void close();
    void drawBox();
    ~Window();
};

Window::Window(
  int top,
  int left,
  int right,
  int bottom,
  string title
) {
  this->top = top;
  this->left = left;
  this->right = right;
  this->bottom = bottom;
  this->title = title;
}

void Window::drawBox() {

}

#endif
