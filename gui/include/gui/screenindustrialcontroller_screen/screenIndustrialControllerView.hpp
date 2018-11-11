#ifndef SCREENINDUSTRIALCONTROLLER_VIEW_HPP
#define SCREENINDUSTRIALCONTROLLER_VIEW_HPP

#include <gui_generated/screenindustrialcontroller_screen/screenIndustrialControllerViewBase.hpp>
#include <gui/screenindustrialcontroller_screen/screenIndustrialControllerPresenter.hpp>

class screenIndustrialControllerView : public screenIndustrialControllerViewBase
{
public:
    screenIndustrialControllerView();
    virtual ~screenIndustrialControllerView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENINDUSTRIALCONTROLLER_VIEW_HPP
