#ifndef SCREENZONE_VIEW_HPP
#define SCREENZONE_VIEW_HPP

#include <gui_generated/screenzone_screen/screenZoneViewBase.hpp>
#include <gui/screenzone_screen/screenZonePresenter.hpp>

class screenZoneView : public screenZoneViewBase
{
public:
    screenZoneView();
    virtual ~screenZoneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENZONE_VIEW_HPP
