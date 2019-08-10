#include "Node.hpp"
#include <iostream>
#include <assert.h>
#include <QDebug>

Node::Node(const std::string& content):  _content(content)
{
}

Node::~Node()
{
    qDebug() << "Destructing node";
}

void Node::setContent(const std::string& content)
{
    _content = content;
}

std::string Node::getContent() const
{
    return _content;
}

void Node::setX(double x)
{
    _metaData.x = x;
}

void Node::setY(double y)
{
    _metaData.y = y;
}

void Node::setWidth(double width)
{
    _metaData.width = width;
}

void Node::setHeight(double height)
{
    _metaData.height = height;
}

double Node::getX() const
{
    return _metaData.x;
}

double Node::getY() const
{
    return _metaData.y;
}

double Node::getWidth() const
{
    return _metaData.width;
}

double Node::getHeight() const
{
    return _metaData.height;
}