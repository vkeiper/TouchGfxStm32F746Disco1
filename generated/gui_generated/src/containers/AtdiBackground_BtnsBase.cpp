/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/AtdiBackground_BtnsBase.hpp>
#include "BitmapDatabase.hpp"

AtdiBackground_BtnsBase::AtdiBackground_BtnsBase()  :
    buttonCallback(this, &AtdiBackground_BtnsBase::buttonCallbackHandler)
{
    setWidth(480);
    setHeight(272);

    imgAtdiCustomBackground.setXY(0, 0);
    imgAtdiCustomBackground.setBitmap(Bitmap(BITMAP_ATDI_TEMPLATE480X272_ID));

    anImgAtdiLogoBeat.setXY(106, 203);
    anImgAtdiLogoBeat.setBitmaps(BITMAP_ATDI_LOGO1_ID, BITMAP_ATDI_LOGO_2_ID);
    anImgAtdiLogoBeat.setUpdateTicksInterval(20);
    anImgAtdiLogoBeat.startAnimation(false, true, true);

    buttonSettings.setPosition(410, 204, 50, 50);
    buttonSettings.setBitmaps(Bitmap(BITMAP_GEAR_50X50_ID), Bitmap(BITMAP_GEAR_50X50_ID));
    buttonSettings.setAction(buttonCallback);

    buttonHome.setPosition(22, 205, 50, 50);
    buttonHome.setBitmaps(Bitmap(BITMAP_HOME_GRAY50X50_ID), Bitmap(BITMAP_HOME_GRAY50X50_ID));
    buttonHome.setAction(buttonCallback);

    add(imgAtdiCustomBackground);
    add(anImgAtdiLogoBeat);
    add(buttonSettings);
    add(buttonHome);
}

void AtdiBackground_BtnsBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonSettings)
    {
        //actioinSettingsBtn
        //When buttonSettings clicked change screen to SetTempControl
        //Go to SetTempControl with slide screen transition towards West
        application().gotoSetTempControlScreenSlideTransitionWest();
    }
    else if (&src == &buttonHome)
    {
        //actionHomeBtn
        //When buttonHome clicked change screen to Main
        //Go to Main with slide screen transition towards West
        application().gotoMainScreenSlideTransitionWest();
    }
}
