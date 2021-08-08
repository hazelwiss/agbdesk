#pragma once

template<typename Iter, Iter beg, Iter end>
struct StaticForLoop{
private:
    static inline constexpr size_t limit{512};
    using IntSeq = std::make_integer_sequence<Iter, end-beg>;
    using RecSeq = std::make_integer_sequence<size_t, (end-beg)/limit>;
public:
    template<typename Func>
    constexpr StaticForLoop(Func&& f){ 
        static_assert(std::is_constant_evaluated(), "can only be statically evaluated");
        if constexpr(RecSeq::size())
            recurseForLoop(std::forward<const Func>(f), RecSeq{});
        else 
            forLoop(std::forward<Func>(f), IntSeq{}); 
    }
protected:
    template<typename Func, Iter... tail> 
    constexpr void forLoop(Func&& f, std::integer_sequence<Iter, tail...>) const
        { (f(std::integral_constant<Iter, beg+tail>{}), ...); }
    template<typename Func, size_t... tail>
    constexpr void recurseForLoop(Func&& f, std::integer_sequence<Iter, tail...>) const
        { (StaticForLoop<Iter, limit*tail, tail == RecSeq::size() ? end : (limit*(tail+1))-1>{f},...); }
};
