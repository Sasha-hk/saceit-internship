#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>

using namespace std;

/**
 * HDD class
 */
class HDD {
  private:
  protected:
    int Mb;

  public:
    /**
     * HDD costructor
     * @param Md Count of megabytes
     */
    HDD(
      int Mb
    );

    /**
     * Get HDD size
     * @return HDD size
     */
    int getSize();

    /**
     * HDD destructor
     */
    ~HDD();
};

class PC {
  private:
  protected:
    HDD storage;
    string* model;
    int price;

  public:
    /**
     * PC costructor
     * @param storage HDD instance
     * @param model Pointer to strign that contains PC model
     * @param price Price
     */
    PC(
      HDD storage,
      string* model,
      int price
    );

    /**
     * PC destructor
     */
    ~PC();
};

class PCExtended : public PC {
  private:
  protected:
    float screenDiagonal;

  public:
    /**
     * Extended PC costructor
     * @param storage HDD instance
     * @param model Pointer to strign that contains PC model
     * @param price Price
     * @param screenDiagonal Diagonal of the monitor screen
     */
    PCExtended(
      HDD storage,
      string* model,
      int price,
      float screenDiagonal
    );

    /**
     * Get screen diagonal
     * @return Screen diagonal
     */
    int getScreenDiagonal();

    /**
     * Extended PC desctuctor
     */
    ~PCExtended();
};


#endif
