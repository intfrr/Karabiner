#ifndef MODIFIERSTUCKFILTER_HPP
#define MODIFIERSTUCKFILTER_HPP

#include "RemapFilterBase.hpp"

namespace org_pqrs_Karabiner {
  namespace RemapFilter {
    class ModifierStuckFilter : public RemapFilterBase {
    public:
      ModifierStuckFilter(unsigned int type) : RemapFilterBase(type) {}

      void initialize(const unsigned int* vec, size_t length);
      bool isblocked(void);

    private:
      Vector_Vector_ModifierFlag targets_;
    };
  }
}

#endif
