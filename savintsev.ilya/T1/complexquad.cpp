#include "complexquad.hpp"
#include <cmath>

savintsev::Complexquad::Complexquad(point_t p1, point_t p2, point_t p3, point_t p4) :
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  bool wasFounded = true;
  point_t center = findLinesIntersect(p1_, p2_, p3_, p4_, &wasFounded);
  if (!wasFounded || !isTriangle(p1_, p4_, center) || !isTriangle(p2_, p3_, center))
  {
    throw std::invalid_argument("ERROR: Invalid argumets for Complexquad");
  }
}

double savintsev::Complexquad::getArea() const
{
  point_t center = getFrameRect().pos;
  return getTriangleArea(p1_, p4_, center) + getTriangleArea(p2_, p3_, center);
}

savintsev::rectangle_t savintsev::Complexquad::getFrameRect() const
{
  double mostLeft = std::fmin(std::fmin(p1_.x, p2_.x), std::fmin(p3_.x, p4_.x));
  double mostRight = std::fmax(std::fmax(p1_.x, p2_.x), std::fmax(p3_.x, p4_.x));
  double mostLow = std::fmin(std::fmin(p1_.y, p2_.y), std::fmin(p3_.y, p4_.y));
  double mostHigh = std::fmax(std::fmax(p1_.y, p2_.y), std::fmax(p3_.y, p4_.y));
  point_t center = {mostLeft + (mostRight - mostLeft) / 2, mostLow + (mostHigh - mostLow) / 2};
  return {mostRight - mostLeft, mostHigh - mostLow, center};
}

void savintsev::Complexquad::move(point_t p)
{
  point_t center = findLinesIntersect(p1_, p2_, p3_, p4_, nullptr);
  double moveByX = p.x - center.x;
  double moveByY = p.y - center.y;
  this->p1_ = {p1_.x + moveByX, p1_.y + moveByY};
  this->p2_ = {p2_.x + moveByX, p2_.y + moveByY};
  this->p3_ = {p3_.x + moveByX, p3_.y + moveByY};
  this->p4_ = {p4_.x + moveByX, p4_.y + moveByY};
}

void savintsev::Complexquad::move(double x, double y)
{
  this->p1_ = {p1_.x + x, p1_.y + y};
  this->p2_ = {p2_.x + x, p2_.y + y};
  this->p3_ = {p3_.x + x, p3_.y + y};
  this->p4_ = {p4_.x + x, p4_.y + y};
}

void savintsev::Complexquad::scale(double k)
{
  if (k <= 0)
  {
    return;
  }
  point_t center = findLinesIntersect(p1_, p2_, p3_, p4_, nullptr);
  this->p1_ = {center.x - (center.x - p1_.x) * k, center.y - (center.y - p1_.y) * k};
  this->p2_ = {center.x - (center.x - p2_.x) * k, center.y - (center.y - p2_.y) * k};
  this->p3_ = {center.x - (center.x - p3_.x) * k, center.y - (center.y - p3_.y) * k};
  this->p4_ = {center.x - (center.x - p4_.x) * k, center.y - (center.y - p4_.y) * k};
}