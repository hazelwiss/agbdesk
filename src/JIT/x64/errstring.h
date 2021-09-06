#pragma once

namespace x64{
    namespace ErrStrings{
        constexpr char INVOPERANDS[]        = "invalid operand combination."; 
        constexpr char INVOPERANSIZES[]     = "invalid operand size combination.";
        constexpr char INVEFFECTIVEADR[]    = "invalid effective address.";
        constexpr char INVSIB[]             = "invalid SIB information. Possibly trying to reference null pointer.";
    };
};
