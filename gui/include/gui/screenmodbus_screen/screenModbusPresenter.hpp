#ifndef SCREENMODBUS_PRESENTER_HPP
#define SCREENMODBUS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screenModbusView;

class screenModbusPresenter : public Presenter, public ModelListener
{
public:
    screenModbusPresenter(screenModbusView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~screenModbusPresenter() {};

private:
    screenModbusPresenter();

    screenModbusView& view;
};


#endif // SCREENMODBUS_PRESENTER_HPP
