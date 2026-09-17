#pragma once

#include <memory>

#include "terminal.hpp"
#include "HAL/Platform.h"
#include "types/vector.hpp"
#include "types/vector3.hpp"

// struct Vec2;

namespace Engine
{
    // public:
    class Screen
    {
    public:
        Screen() = default;


        Screen(Vec2 size) : Size(size) {};

        fVec2 ToDotProduct(Vec2 point) const;
        fVec2 Translate(Vec3 point) const;
        Vec2 Project(fVec2 point, float scale) const;

        template<typename... Args>
        auto print(std::format_string<Args...> fmt, Args&& ...args)
        {
            std::cout << std::string(std::format(fmt, std::forward<Args>(args)...)) << Ansi::Reset;
        }

        void Draw(std::variant<const Square*, const Text*> element, u16 x, u16 y, u16 w, u16 h)
        {
            u16 height = h+1, posY = y;
            std::string content;
            RGB fg(0,0,0),
                bg(0,0,0);

            const auto s = std::get_if<const Square*>(&element);
            const auto t   = std::get_if<const Text*>(&element);

            if (s) {
                Square sq = **s;
                content = Ansi::RepeatChar(' ', w);
                fg = sq.Fg;
                bg = sq.Bg;
            }
            else if (t)
            {
                Text tx = **t;
                content = tx.Content;
                fg = tx.Fg;
                bg = tx.Bg;
            }
            while (--height > 0)
            {
                this->cursor.setPosition(x, posY++, Ansi::CursorCtrl::Normal);
                print("{}{}",
                    Ansi::Color(
                        Ansi::Color(Ansi::Foreground, fg.r, fg.g, fg.b),
                        Ansi::Color(Ansi::Background, bg.r, bg.g, bg.b)
                    ),
                    content
                );
            }
        }

        Ansi::CursorCtrl cursor;
        Vec2 Size;

    // private:
    //     Log::Logger output = Log::Logger(LogCategory("salute",
    //         Ansi::Color(
    //             Ansi::Color(Ansi::Background, 20,20,20),
    //             Ansi::Color(Ansi::Foreground, 255, 255, 255)
    //         )
    //     ), true);
    };
}
