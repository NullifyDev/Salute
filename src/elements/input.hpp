#ifndef INPUT_HPP
#define INPUT_HPP
#pragma once

#include <string>
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

struct Input {
    std::string content;
    Input(const std::string &txt = "") : content(txt) {}

    void async() {
        int loc = 0;
        while (true) {

            char c = 0;
            switch (c = std::cin.get()) {
                case '\n':
                case '\t':
                    continue;

                case '\b':
                    content = std::string(content.substr(0, loc).substr(loc+2, content.length()));
                    continue;

                case KEY_UP:
                    loc = content.length();
                    continue;

                case KEY_DOWN:
                    loc = 0;
                    continue;

                case KEY_LEFT:
                    --loc;
                    continue;

                case KEY_RIGHT:
                    ++loc;
                    continue;

                default:
                    content += c;
                    break;
            }
        }
    }

    void clear();
};
#endif