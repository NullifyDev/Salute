#pragma once

#include "Misc/Ansi.h"

#include <bits/stdc++.h>
#include <iostream>

namespace Ansi
{

    // inline constexpr std::string_view ClearScreen = "\033[2J";

    class CursorCtrl
    {
    public:
        enum Controls : char
        {
            Reset,
            Normal = 'H',
            Request = 'R',
        };

        CursorCtrl()
        {
            this->setPosition(0, 0, Controls::Reset);
        }

        CursorCtrl(Controls ctrl)
        {
            this->setPosition(0, 0, Controls::Reset);
        }

        auto Controls_toValue(Controls ctrl) -> char
        {
            switch (ctrl)
            {
            case Request: return 'R';
            default:      return 'H'; // 'Controls::Normal' and 'Controls::Reset' return the same thing
            }
        }

        void setPosition(Controls ctrl)
        {
            std::cout << "\033[" << ctrl;
        }

        void setPosition(u16 x, u16 y)
        {
            std::cout << "\033["
                      << std::to_string(y) << ";"
                      << std::to_string(x) << "H";
        }

        inline auto setPosition(u16 x, u16 y, Controls ctrl) -> void
        {
            switch (ctrl)
            {
            case Reset:
                std::cout << "\033[" << ctrl;
                return;

            default:
                setPosition(x, y);
            }
        }


        auto reset()
        {
            setPosition(0,0, Reset);
        }

        // void setPosition(u16 u16, ::u16 y, Controls ctrl);

        private:
        u16 x, y;
    };

    inline auto RepeatChar(char c, u16 count) -> std::string
    {
        std::string res, character = std::to_string(c);

        res.reserve(count);
        while (count-- > 0)
            res += c;

        return res;
    }

    inline auto RepeatChar_unsafe(char c, u16 count) -> const char*
    {
        auto *const res = static_cast<char*>(malloc(count+1));
        if (!res) return "";

        res[count] = '\0';
        while (count-- > 0)
            res[count] = c;

        return res;
    }
}

