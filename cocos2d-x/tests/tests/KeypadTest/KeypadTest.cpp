#include "KeypadTest.h"

KeypadTest::KeypadTest()
: m_bShow(true)
{
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    CCLabelTTF* label = CCLabelTTF::labelWithString("Keypad Test", "Arial", 28);
    addChild(label, 0);
    label->setPosition( ccp(s.width/2, s.height-50) );

    setIsKeypadEnabled(true);

    // create a label to display the tip string
    m_pLabel = CCLabelTTF::labelWithString("Please press any key...", "Arial", 22);
    m_pLabel->setPosition(ccp(s.width / 2, s.height / 2));
    addChild(m_pLabel, 0);
    
    m_pLabel->retain();
}

KeypadTest::~KeypadTest()
{
    m_pLabel->release();
}

void KeypadTest::keyBackClicked()
{
    m_pLabel->setString("BACK clicked!");
}

void KeypadTest::keyMenuClicked()
{
    m_pLabel->setString("MENU clicked!");
}

void KeypadTestScene::runThisTest()
{
    CCLayer* pLayer = new KeypadTest();
    addChild(pLayer);

    CCDirector::sharedDirector()->replaceScene(this);
    pLayer->release();
}
