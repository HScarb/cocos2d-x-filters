#include "VisibleRect.h"

Rect VisibleRect::s_visibleRect;
Size VisibleRect::_sSize;

void VisibleRect::lazyInit()
{
    if (s_visibleRect.size.width == 0.0f && s_visibleRect.size.height == 0.0f)
    {
        Director* director = Director::getInstance();
        GLView* pGLView = director->getOpenGLView();
        s_visibleRect.origin = pGLView->getVisibleOrigin();
        s_visibleRect.size = pGLView->getVisibleSize();
        _sSize = director->getWinSize();
    }
}

Rect VisibleRect::getVisibleRect()
{
    lazyInit();
    return Rect(s_visibleRect.origin.x, s_visibleRect.origin.y, s_visibleRect.size.width, s_visibleRect.size.height);
}

Size VisibleRect::getWinSize()
{
    lazyInit();
    return Size(_sSize.width, _sSize.height);
}

Point VisibleRect::left()
{
    lazyInit();
    return Point(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Point VisibleRect::left(const float &ox, const float &oy)
{
    Point __ccp = left();
    return Point(__ccp.x + ox, __ccp.y + oy);
}

Point VisibleRect::right()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Point VisibleRect::right(const float &ox, const float &oy)
{
    Point __ccp = right();
    return Point(__ccp.x + ox, __ccp.y + oy);
}

Point VisibleRect::top()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height);
}

Point VisibleRect::top(const float &ox, const float &oy)
{
    Point __ccp = top();
    return Point(__ccp.x + ox, __ccp.y + oy);
}

Point VisibleRect::bottom()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y);
}

Point VisibleRect::bottom(const float &ox, const float &oy)
{
    Point __ccp = bottom();
    return Point(__ccp.x + ox, __ccp.y + oy);
}

Point VisibleRect::center()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Point VisibleRect::center(const float &ox, const float &oy)
{
    Point __ccp = center();
    return Point(__ccp.x + ox, __ccp.y + oy);
}

Point VisibleRect::leftTop()
{
    lazyInit();
    return Point(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height);
}

Point VisibleRect::leftTop(const float &ox, const float &oy)
{
    Point __ccp = leftTop();
    return Point(__ccp.x + ox, __ccp.y + oy);
}

Point VisibleRect::rightTop()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height);
}

Point VisibleRect::rightTop(const float &ox, const float &oy)
{
    Point __ccp = rightTop();
    return Point(__ccp.x + ox, __ccp.y + oy);
}

Point VisibleRect::leftBottom()
{
    lazyInit();
    return s_visibleRect.origin;
}

Point VisibleRect::leftBottom(const float &ox, const float &oy)
{
    Point __ccp = leftBottom();
    return Point(__ccp.x + ox, __ccp.y + oy);
}

Point VisibleRect::rightBottom()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y);
}

Point VisibleRect::rightBottom(const float &ox, const float &oy)
{
    Point __ccp = rightBottom();
    return Point(__ccp.x + ox, __ccp.y + oy);
}