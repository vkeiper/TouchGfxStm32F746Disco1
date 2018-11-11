#ifndef SCREENMODBUS_VIEW_HPP
#define SCREENMODBUS_VIEW_HPP

#include <gui_generated/screenmodbus_screen/screenModbusViewBase.hpp>
#include <gui/screenmodbus_screen/screenModbusPresenter.hpp>

class screenModbusView : public screenModbusViewBase
{
public:
    screenModbusView();
    virtual ~screenModbusView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENMODBUS_VIEW_HPP
