#include <iostream>

class NumberBase
{
  private:
    int B_;
    int N_;

  public:
    NumberBase(int N, int B);
    virtual ~NumberBase();
    virtual NumberBase *operator+(const NumberBase *) const = 0;
    virtual NumberBase *operator-(const NumberBase *) const = 0;
    friend std::ostream &operator<<(std::ostream &, const NumberBase *n);

  protected:
    virtual void to_base(int) = 0;
    virtual std::ostream &write(std::ostream &os) const = 0;
    virtual NumberBase *duplicate() const = 0;
};

