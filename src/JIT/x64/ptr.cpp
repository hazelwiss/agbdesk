#include"x64.h"

namespace x64::Ptr{
    Mem x64::Ptr::Pointer::operator[](Address&& adr) const noexcept{
        return Mem(group, adr);
    }
    const Pointer qword{BaseMem::S64};
    const Pointer dword{BaseMem::S32};
    const Pointer word{BaseMem::S16};
    const Pointer byte{BaseMem::S8};   
}