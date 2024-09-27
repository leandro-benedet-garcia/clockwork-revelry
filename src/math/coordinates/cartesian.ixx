/**
 * @brief Base abstract classes for any object that implement coordinate<br />
 *        system, for example, Vector and Point
 *
 */
module;

#include <string>

#include "constants.hpp"

export module clockwork_reverie.math.cartesian;

import clockwork_reverie.math.utils;

export namespace ClockworkReverie::Math {
template <Numeric TYPE, unsigned short int SIZE = 1> struct CartesianBase {
  virtual ~CartesianBase() {}

  virtual TYPE &operator[](unsigned short int idx) = 0;
  virtual bool operator==(CartesianBase<TYPE, SIZE> &other) = 0;
  virtual std::string to_string() = 0;
  bool
  approximately(CartesianBase<TYPE, SIZE> other,
                TYPE tolerance = std::numeric_limits<TYPE>::epsilon()) = 0;
};

template <Numeric TYPE, unsigned short int SIZE = 1>
struct Cartesian : CartesianBase<TYPE, SIZE> {};

NUMERIC_TEMPLATE struct Cartesian<TYPE, 2> {
  virtual TYPE get_x() const = 0;
  virtual TYPE get_y() const = 0;

  virtual void set_x(TYPE value) = 0;
  virtual void set_y(TYPE value) = 0;
};

template <Numeric TYPE> struct Cartesian<TYPE, 3> {
  virtual TYPE get_x() const = 0;
  virtual TYPE get_y() const = 0;
  virtual TYPE get_z() const = 0;

  virtual void set_x(TYPE value) = 0;
  virtual void set_y(TYPE value) = 0;
  virtual void set_z(TYPE value) = 0;
};

template <Numeric TYPE> struct Cartesian<TYPE, 4> {
  virtual TYPE get_x() const = 0;
  virtual TYPE get_y() const = 0;
  virtual TYPE get_z() const = 0;
  virtual TYPE get_w() const = 0;

  virtual void set_x(TYPE value) = 0;
  virtual void set_y(TYPE value) = 0;
  virtual void set_z(TYPE value) = 0;
  virtual void set_w(TYPE value) = 0;
};
} // namespace ClockworkReverie::Math
