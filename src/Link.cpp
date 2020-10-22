#include "Link.h"

Link::Link(std::string path, bool internal) : _path(new char[path.length()]), _internal(internal)
{
  std::strcpy(_path, path.c_str());
}

Link::~Link()
{
  free(_path);
}

// copy constructor
Link::Link(Link const &source) : _path(new char[std::strlen(source._path)]),
                           _internal(source.isInternal()),
                           _visited(source.isVisted())
{
  std::strcpy(_path, source._path);
}

void Link::swap(Link &lhs, Link &rhs) noexcept
{
  std::swap(lhs._path, rhs._path);
  std::swap(lhs._internal, rhs._internal);
  std::swap(lhs._visited, rhs._visited);
}

// equal operator
Link & Link::operator=(Link const &source)
{
  Link copy(source);
  swap(*this, copy);
  return *this;
}

// move constructor
Link::Link(Link &&source) noexcept
{
  swap(*this, source);
  source._path = nullptr;
}

// equal move
Link & Link::operator=(Link &&source) noexcept
{
  if (this != &source)
  {
  swap(*this, source);
  source._path = nullptr;
  }
  return *this;
}

void Link::setPath(std::string path)
{
  _path = (char *)malloc(sizeof(char) * (path.length() + 1));
  strcpy(_path, path.c_str());
}

std::string Link::getPath() const
{
  return std::string(_path);
}

void Link::setInternal(bool isInternal)
{
  _internal = isInternal;
}

bool Link::isInternal() const
{
  return _internal;
}

void Link::setVisited(bool isVisted)
{
  _visited = isVisted;
}

bool Link::isVisted() const
{
  return _visited;
}
