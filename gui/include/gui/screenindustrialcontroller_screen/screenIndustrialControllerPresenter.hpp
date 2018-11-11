#ifndef SCREENINDUSTRIALCONTROLLER_PRESENTER_HPP
#define SCREENINDUSTRIALCONTROLLER_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screenIndustrialControllerView;

class screenIndustrialControllerPresenter : public Presenter, public ModelListener
{
public:
    screenIndustrialControllerPresenter(screenIndustrialControllerView& v);

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

    virtual ~screenIndustrialControllerPresenter() {};

private:
    screenIndustrialControllerPresenter();

    screenIndustrialControllerView& view;
};


#endif // SCREENINDUSTRIALCONTROLLER_PRESENTER_HPP
