#ifndef SCREENCANBUS_VIEW_HPP
#define SCREENCANBUS_VIEW_HPP

#include <gui_generated/screencanbus_screen/screenCanbusViewBase.hpp>
#include <gui/screencanbus_screen/screenCanbusPresenter.hpp>

class screenCanbusView : public screenCanbusViewBase
{
public:
    screenCanbusView();
    virtual ~screenCanbusView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENCANBUS_VIEW_HPP
