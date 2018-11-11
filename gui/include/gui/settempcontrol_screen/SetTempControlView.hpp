#ifndef SETTEMPCONTROL_VIEW_HPP
#define SETTEMPCONTROL_VIEW_HPP

#include <gui_generated/settempcontrol_screen/SetTempControlViewBase.hpp>
#include <gui/settempcontrol_screen/SetTempControlPresenter.hpp>


class SetTempControlView : public SetTempControlViewBase
{
public:
    SetTempControlView();
    virtual ~SetTempControlView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		//event from presenter
   	void updateRoomTempUI(uint32_t temp);
		void updateReadRoomTempUI(uint32_t temp);
			
				
protected:
    virtual void sliderMoved(int value);
		virtual void setReadTempColor(int value);

};

#endif // SETTEMPCONTROL_VIEW_HPP
