#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <touchgfx/hal/GPIO.hpp>
#ifndef SIMULATOR
#include "stm32746g_discovery.h"
#endif

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{
}

void MainPresenter::activate()
{
}

void MainPresenter::deactivate()
{
}

void MainPresenter::setRoomLight(bool state)
{	
    model->userSetRoomLight(state);	  
}
