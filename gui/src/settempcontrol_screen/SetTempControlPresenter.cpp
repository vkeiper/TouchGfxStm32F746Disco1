#include <gui/settempcontrol_screen/SetTempControlView.hpp>
#include <gui/settempcontrol_screen/SetTempControlPresenter.hpp>

SetTempControlPresenter::SetTempControlPresenter(SetTempControlView& v)
    : view(v)
{
}


void SetTempControlPresenter::activate()
{
	//from model to view 
  view.updateRoomTempUI(model->getRoomTemperature());
}

void SetTempControlPresenter::deactivate()
{

}

//from view 
void SetTempControlPresenter::userSetTemperatureAPP(uint32_t temp)
{
	  //to model
    model->userSetTemperature(temp);
}


void SetTempControlPresenter::setReadRoomTemperatureUI()
{
    //forward new temperature to view
    view.updateReadRoomTempUI(model->getReadRoomTemperature());
}


void SetTempControlPresenter::guiDataChanged()
{
    //forward new temperature to view
    view.updateRoomTempUI(model->getRoomTemperature());
	
    //forward new read temp from model to view	  
		setReadRoomTemperatureUI();
	
		

}
