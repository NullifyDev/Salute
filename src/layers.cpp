#include "layers.hpp"
// #include "terminal.hpp"

// #include "elements/header.hpp"

void Layers::Add(Element element)
{
    this->elements.push_back(element);
}

void Layers::Add(std::vector<Element> element_items)
{
    for(auto e : element_items)
        this->elements.push_back(e);
}

void Layers::Print(std::weak_ptr<Terminal> screen)
{
    for (uint32_t i = 0; i < this->elements.size(); i++)
        this->elements.at(i).print(screen.lock());
}

// void Layers::Print(std::weak_ptr<Terminal> terminal)
// {
//     auto t = terminal.lock();
//     for (u32 i = 0; i < this->elements.size(); i++)
//     {
//         Element e = this->elements.at(i);
//         t->stack.push(e);
//         e.print(terminal.lock());
//         t->stack.pop();
//     }
// }

void Layers::to_str()
{
    for (u32 i = 0; i < this->elements.size(); i++)
        this->elements.at(i).to_str();
}