#pragma once
#include <iostream>

class DNI
{
  private:
    int DNI_[7];

  public:
    DNI();

    operator int long() const;

    bool operator==(DNI);
    bool operator<(DNI);

    int get_dig(int i) const;

    friend std::ostream &operator<<(std::ostream &os, const DNI d);
};

