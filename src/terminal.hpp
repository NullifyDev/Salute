#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#pragma once

// #define _GLIBCXX_USE_NANOSLEEP

#include <string>
#include <stack>
#include <sys/ioctl.h>
#include <iostream>
#include <thread>

#include "Logging/Log.h"
#include "utils/additions/BlujayEngine/ANSI.h"
#include "elements/header.hpp"

struct Element;
struct Text;
struct Square;

typedef struct windowsize {
    u16 ws_row, ws_col, px, py;
} WindowSize;

typedef enum struct drawmode {
    Normal,
    DotProduct
} DrawMode;

struct Terminal {

    Terminal() {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &this->size);
        // this->update_t = std::thread(update, &this->update_running, &this->size);
    }
    Terminal(WindowSize *size) {
        this->size = *size;
        // this->update_t = std::thread(update, &this->update_running, &this->size);
    }
    Terminal(const Terminal& terminal) : size(terminal.size) {}
    ~Terminal()
    {
        this->update_running = false;
        this->size.px = 0;
        this->size.py = 0;
        this->size.ws_col = 0;
        this->size.ws_row = 0;

        this->update_t.join();

        this->buffer.clear();
    }


    // void Draw(std::variant<const Square*, const Text*> element, u16 x, u16 y, u16 w, u16 h, DrawMode drawmode = DrawMode::Normal);
    // static void update(bool *run_update, windowsize *size) {
    //     *run_update = true;
    //     while (*run_update == true)
    //     {
    //         ioctl(STDOUT_FILENO, TIOCGWINSZ, size);
    //     }
    // }

    template<typename... Args>
    auto LogRaw(std::format_string<Args...> fmt, Args&& ...args)
    {
        std::cout << std::string(std::format(fmt, std::forward<Args>(args)...));
    }

    template<typename... Args>
    auto Log(std::format_string<Args...> fmt, Args&& ...args)
    {
        std::cout << std::string(std::format(fmt, std::forward<Args>(args)...)) << Ansi::Reset;
    }

    template<typename... Args>
    auto Logln(std::format_string<Args...> fmt, Args&& ...args)
    {
        std::cout << std::string(std::format(fmt, std::forward<Args>(args)...)) << Ansi::Reset << '\n';
    }

    // template<typename... Args>
    // auto print(std::format_string<Args...> fmt, Args&& ...args)
    // {
    //     std::cout << std::string(std::format(fmt, std::forward<Args>(args)...)) << Ansi::Reset;
    // }



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
            this->cursor.setPosition(x, posY++);
            Log("{}{}",
                Ansi::Color(
                    Ansi::Color(Ansi::Foreground, fg.r, fg.g, fg.b),
                    Ansi::Color(Ansi::Background, bg.r, bg.g, bg.b)
                ),
                content
            );
        }
    }

    WindowSize size {};
    Ansi::CursorCtrl cursor;
    std::stack<Element> stack;

private:
    Log::Logger output = Log::Logger(
        Log::Category("salute",
            Ansi::Color(
                Ansi::Color(Ansi::Background, 20,20,20),
                Ansi::Color(Ansi::Foreground, 255, 255, 255)
            )
     ),  Log::Info);

    std::string buffer;
    std::thread update_t;
    bool update_running = false;
};

#endif