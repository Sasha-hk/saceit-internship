#pragma once
#ifndef PD_H
#define PC_H

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
     * Default DHH constructor
     */
    HDD();

    /**
     * HDD costructor
     * @param Mb Count of megabytes
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

/**
 * PC class
 */
class PC {
  private:
  protected:
    HDD storage;
    string model;
    string price;

  public:
    /**
     * Default constructor
     */
    PC();

    /**
     * PC costructor
     * @param storage HDD instance
     * @param model Pointer to strign that contains PC model
     * @param price Price
     */
    PC(
      HDD storage,
      string model,
      string price
    );

    /**
     * Get storage
     * @return Storage
     */
    HDD getStorage();

    /**
     * PC destructor
     */
    ~PC();
};

/**
 * Extended PC class
 */
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
      string model,
      string price,
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
