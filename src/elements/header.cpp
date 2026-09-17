// #include "header.hpp"
#include "layers.hpp"

Element *const Element::GetElement() {
    return this;
}

void Element::prepare(i16 *x, i16 *y, u16 *w, u16 *h) const {
    const Percentage *p = std::get_if<Percentage>(&this->location);
    const Vec2       *v = std::get_if<Vec2>(&this->location);
    const Clamp      *c = std::get_if<Clamp>(&this->location);

    if (p)
    {
        *x = round(*p->refX * p->sizeX);
        *y = round(*p->refY * p->sizeY);

        if (*x == 0) *x = 1;
        if (*y == 0) *y = 1;
    }
    else if (v)
    {
        *x = v->getx();
        *y = v->gety();
    }
    else if (c) {
        *w = c->getY();
        *h = c->getX();
    }

    p = std::get_if<Percentage>(&this->size);
    v = std::get_if<Vec2>(&this->size);
    c = std::get_if<Clamp>(&this->size);

    if (p)
    {
        *w = round(*p->refX * p->sizeX);
        *h = round(*p->refY * p->sizeY);

        if (p->raw) (*h)--;

        if (*p->refX - (*w + *x) <= 2)
            *w = (*p->refX) - *x + 1;

        if (*p->refY - (*h + *y) <= 2)
            *h = (*p->refY) - *y + 1;
    }
    else if (v)
    {
        *w = v->getx();
        *h = v->gety();
    }
    else if (c)
    {
        *w = c->getX();
        *h = c->getY();

        if (*c->scale.refY - (*h + *y) <= 2)
            *h = (*c->scale.refY) - *y + 1;

    }
}

void Element::print(std::shared_ptr<Terminal> screen) const
{
    const Square *s = std::get_if<Square>(&this->element);
    const Text   *t = std::get_if<Text>(&this->element);

    if (s)
    {
        Square sq = *s;
        sq.print(screen, this);
    }
    else if (t)
    {
        Text tx = *t;
        tx.print(screen, this);
    }

    for (u8 i = 0; i < this->children.size(); i++)
    {
        Element el = this->children.at(i);
        el.print(screen);
    }
}

void Element::to_str() const
{
    const Square *s = std::get_if<Square>(&this->element);
    if (s)
    {
        // Square sq = *s;

        u16 w, h;
        i16 x, y;
        this->prepare(&x, &y, &w, &h);

        for (size_t i = 0; i < this->children.size(); i++)
            this->children.at(i).to_str();

        return;
    }

    const Text   *t = std::get_if<Text>(&this->element);
    if (t)
    {
        Text tx = *t;

        u16 w, h;
        i16 x, y;
        this->prepare(&x, &y, &w, &h);

        for (size_t i = 0; i < this->children.size(); i++)
            this->children.at(i).to_str();

        return;
    }
}

void Element::AddChild(Element e) {
    this->children.push_back(e);
}