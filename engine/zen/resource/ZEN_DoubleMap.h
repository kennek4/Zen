#pragma once

#include <map>

namespace ZEN {
template <typename A, typename B, typename C> class DoubleMap {
public:
  auto size() const {

  };

private:
  std::map<A, B> m_ABMap;
  std::map<B, C> m_BCMap;
};
}; // namespace ZEN
