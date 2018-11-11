#ifndef SCREENCANBUS_PRESENTER_HPP
#define SCREENCANBUS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screenCanbusView;

class screenCanbusPresenter : public Presenter, public ModelListener
{
public:
    screenCanbusPresenter(screenCanbusView& v);

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

    virtual ~screenCanbusPresenter() {};

private:
    screenCanbusPresenter();

    screenCanbusView& view;
};


#endif // SCREENCANBUS_PRESENTER_HPP
