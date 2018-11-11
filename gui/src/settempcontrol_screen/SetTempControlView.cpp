#include <gui/settempcontrol_screen/SetTempControlView.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SetTempControlView::SetTempControlView()
{

}

void SetTempControlView::setupScreen()
{

}

void SetTempControlView::tearDownScreen()
{

}

//from presenter to view
void SetTempControlView::updateRoomTempUI(uint32_t temp)
{
    //update slider and temperature text
    slider.setValue(temp);
    Unicode::snprintf(tempTextBuffer, 3, "%d", temp);
    tempText.invalidate();
}

//from presenter to view
void SetTempControlView::updateReadRoomTempUI(uint32_t temp)
{
    Unicode::snprintf(textAreaReadTempBuffer, 3, "%d", temp);
		
		//set text color of read temp
		setReadTempColor((int)temp);
	
		//trigger redraw of this text area
    textAreaReadTemp.invalidate();
}

//from view 
void SetTempControlView::sliderMoved(int value)
{
    //report to presenter and update text
    presenter->userSetTemperatureAPP(value);
    Unicode::snprintf(tempTextBuffer, 3, "%d", value);
    tempText.invalidate();
}

//when model var changes value we set color based on val 
void SetTempControlView::setReadTempColor(int value)
{
    //if read temp is > set temp then COOLING required, Blue Text
    if(value > slider.getValue())
		{	
				//blue text
				textAreaReadTemp.setColor(touchgfx::Color::getColorFrom24BitRGB(9,60,188));
		}
		else if(value < slider.getValue())
		    //if read temp is < set temp then HEAT required, Red Text
		{
				textAreaReadTemp.setColor(touchgfx::Color::getColorFrom24BitRGB(188,9,9));
		}
		else  //equal means NO DEMAND, white text 
		{ 
				textAreaReadTemp.setColor(touchgfx::Color::getColorFrom24BitRGB(255,255,255));
		}
    textAreaReadTemp.invalidate();
}

