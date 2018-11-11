#include <gui/main_screen/MainView.hpp>

MainView::MainView()
{
}

void MainView::setupScreen()
{
}

void MainView::tearDownScreen()
{
}

void MainView::updateRoomLight()
{
    //report change to presenter
    presenter->setRoomLight(onOffButton.getState());
}
