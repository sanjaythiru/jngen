#pragma once

#include "common.h"
#include "random.h"

#include <algorithm>

namespace jngen {

// TODO: deprecate random_shuffle as done in testlib.h

template<typename Iterator>
void shuffle(Iterator begin, Iterator end) {
    ensure(end > begin, "Cannot shuffle range of negative length");
    size_t size = end - begin;
    for (size_t i = 1; i < size; ++i) {
        std::swap(*(begin + i), *(begin + rnd.next(i + 1)));
    }
}

template<typename Iterator>
typename Iterator::value_type choice(Iterator begin, Iterator end) {
    ensure(end > begin, "Cannot select from a range of negative length");
    return *(begin + rnd.next(end - begin));
}

} // namespace jngen

using jngen::shuffle;
using jngen::choice;