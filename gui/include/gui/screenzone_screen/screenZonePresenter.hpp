#ifndef SCREENZONE_PRESENTER_HPP
#define SCREENZONE_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screenZoneView;

class screenZonePresenter : public Presenter, public ModelListener
{
public:
    screenZonePresenter(screenZoneView& v);

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

    virtual ~screenZonePresenter() {};

private:
    screenZonePresenter();

    screenZoneView& view;
};


#endif // SCREENZONE_PRESENTER_HPP
