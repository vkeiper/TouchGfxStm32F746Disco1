#ifndef SCREENMENU_PRESENTER_HPP
#define SCREENMENU_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screenMenuView;

class screenMenuPresenter : public Presenter, public ModelListener
{
public:
    screenMenuPresenter(screenMenuView& v);

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

    virtual ~screenMenuPresenter() {};

private:
    screenMenuPresenter();

    screenMenuView& view;
};


#endif // SCREENMENU_PRESENTER_HPP
