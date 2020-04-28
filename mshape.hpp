//
//  mshape.hpp
//  proj2_hw7
//
//  Created by Chenyi Ling on 4/27/20.
//  Copyright © 2020 Chenyi Ling. All rights reserved.
//

#ifndef mshape_hpp
#define mshape_hpp

#include <iostream>
#include <memory>
#include <initializer_list>
using std::initializer_list;
#include <vector>
using std::vector;

using std::shared_ptr;
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <string>


class mShape {
public:
    virtual ~mShape() = default;
    virtual double getHeight() const = 0;
    virtual double getWidth() const = 0;
    virtual void move(int i, std::ostream& os) const = 0;
    void genPostScript(std::ostream& os){
        for (size_t i = 0; i < _shapes.size(); i++)
        {
            move(i,os);
        }
    }
private:
    std::vector<std::shared_ptr<mShape>> _shapes;
    
};

std::shared_ptr<mShape> makeLayeredShape(std::initializer_list<std::shared_ptr<mShape>> i);
std::shared_ptr<mShape> makeVerticalShape(std::initializer_list<std::shared_ptr<mShape>> i);
std::shared_ptr<mShape> makeHorizontalShape(std::initializer_list<std::shared_ptr<mShape>> i);


class LayeredShape : public mShape
{
public:
    LayeredShape(std::initializer_list<std::shared_ptr<mShape>> i);
    double getHeight() const override;
    double getWidth() const override;
    void move(int i,std::ostream& os) const override;
    void genPostScript(std::ostream& os);
private:
    std::vector<std::shared_ptr<mShape>> _shapes;
    
};

class VerticalShape : public mShape {
public:
    VerticalShape(std::initializer_list<std::shared_ptr<mShape>> i);
    double getHeight() const override;
    double getWidth() const override;
    void move(int i,std::ostream& os) const override;
    void genPostScript(std::ostream& os);
private:
    std::vector<std::shared_ptr<mShape>> _shapes;
};

class HorizontalShape : public mShape {
public:
    HorizontalShape(std::initializer_list<std::shared_ptr<mShape>> i);
    double getHeight() const override;
    double getWidth() const override;
    void move(int i,std::ostream& os) const override;
    void genPostScript(std::ostream& os);
private:
    std::vector<std::shared_ptr<mShape>> _shapes;
};

#endif /* mshape_hpp */
