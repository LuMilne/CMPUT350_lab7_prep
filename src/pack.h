#ifndef PACK_H
#define PACK_H

template <typename... Args>
struct Pack {};

namespace pack_detail {

    // 1.1: Size. the variable template:
    template <typename... Args>
    constexpr int packSize(Args...) {
        return sizeof...(Args);
    };

    // 1.2: Index to type. the type template:
    template <int QueryIndex, typename... Args> 
    struct _packIndexToType {
        // QueryIndex needs to be within (0..N) where N is number of Args
        static_assert(QueryIndex >= 0 && QueryIndex < packSize(Args));
        // TODO
        std::tuple<Args...> types;
        return types[QueryIndex];
    };

};

#endif  // PACK_H
