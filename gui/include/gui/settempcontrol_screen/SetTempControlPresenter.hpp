#ifndef SETTEMPCONTROL_PRESENTER_HPP
#define SETTEMPCONTROL_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SetTempControlView;

class SetTempControlPresenter : public Presenter, public ModelListener
{
public:
    SetTempControlPresenter(SetTempControlView& v);

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

    virtual ~SetTempControlPresenter() {};
		
		virtual void guiDataChanged();
    
		//from view to model
    void userSetTemperatureAPP(uint32_t temp);
    
		//from model to view
    void setReadRoomTemperatureUI();
    //from model to view
    void setRoomTemperature(uint32_t temp);
		

private:
    SetTempControlPresenter();

    SetTempControlView& view;
};


#endif // SETTEMPCONTROL_PRESENTER_HPP
