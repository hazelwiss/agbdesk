#include"x64.h"

namespace x64::Ptr{
    Mem x64::Ptr::Pointer::operator[](Address&& adr) const noexcept{
        return Mem(group, adr);
    }
    const Pointer QWORD{BaseMem::S64};
    const Pointer DWORD{BaseMem::S32};
    const Pointer WORD{BaseMem::S16};
    const Pointer BYTE{BaseMem::S8};   
}