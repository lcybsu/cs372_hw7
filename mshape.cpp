//
//  mshape.cpp
//  proj2_hw7
//
//  Created by Chenyi Ling on 4/27/20.
//  Copyright © 2020 Chenyi Ling. All rights reserved.
//

#include "mshape.hpp"
using std::initializer_list;
using std::vector;
using std::shared_ptr;

std::shared_ptr<mShape> makeLayeredShape(std::initializer_list<std::shared_ptr<mShape>> i)
{
    return std::make_shared<LayeredShape>(i);
}

std::shared_ptr<mShape> makeVerticalShape(std::initializer_list<std::shared_ptr<mShape>> i)
{
    return std::make_shared<VerticalShape>(i);
}

std::shared_ptr<mShape> makeHorizontalShape(std::initializer_list<std::shared_ptr<mShape>> i)
{
    return std::make_shared<HorizontalShape>(i);
}

LayeredShape::LayeredShape(initializer_list<shared_ptr<mShape>> i)
{
    vector<shared_ptr<mShape>> temp(i.begin(), i.end());
    _shapes = temp;
}

double LayeredShape::getHeight() const
{
    return 0.0;
}

double LayeredShape::getWidth() const
{
    return 0.0;
}

void LayeredShape::move(int i, std::ostream& os) const
{
        _shapes[i]->genPostScript(os);
}

VerticalShape::VerticalShape(initializer_list<shared_ptr<mShape>> i)
{
    vector<shared_ptr<mShape>> temp(i.begin(), i.end());
    _shapes = temp;
}

double VerticalShape::getHeight() const
{
    return 0.0;
}

double VerticalShape::getWidth() const
{
    return 0.0;
}

void VerticalShape::move(int i, std::ostream& os) const
{
      os << "gsave\n";
      _shapes[i]->genPostScript(os);
      os << "grestore\n";
      os  << "0 " << _shapes[i]->getHeight() << " translate\n";
}

HorizontalShape::HorizontalShape(initializer_list<shared_ptr<mShape>> i)
{
    vector<shared_ptr<mShape>> temp(i.begin(), i.end());
    _shapes = temp;
}

double HorizontalShape::getHeight() const
{
    return 0.0;
}

double HorizontalShape::getWidth() const
{
    return 0.0;
}

void HorizontalShape::move(int i, std::ostream& os) const
{
      os << "gsave\n";
      _shapes[i]->genPostScript(os);
      os << "grestore\n";
      os << _shapes[i]->getWidth() <<" 0 translate\n";
}
