#ifndef SCREENMENU_VIEW_HPP
#define SCREENMENU_VIEW_HPP

#include <gui_generated/screenmenu_screen/screenMenuViewBase.hpp>
#include <gui/screenmenu_screen/screenMenuPresenter.hpp>

class screenMenuView : public screenMenuViewBase
{
public:
    screenMenuView();
    virtual ~screenMenuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENMENU_VIEW_HPP
