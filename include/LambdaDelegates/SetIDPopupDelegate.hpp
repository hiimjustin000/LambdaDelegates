#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SetIDPopupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSetIDPopupDelegate : public cocos2d::CCObject, public SetIDPopupDelegate {
public:
    std::function<void(SetIDPopup*, int)> m_setIDPopupClosed;

    void setIDPopupClosed(SetIDPopup* p0, int p1) override {
        return m_setIDPopupClosed(p0, p1);
    }

    static LambdaSetIDPopupDelegate* create(
        std::function<void(SetIDPopup*, int)> const& setIDPopupClosed = [](auto, auto) {}
    ) {
        auto delegate = new LambdaSetIDPopupDelegate();
        delegate->m_setIDPopupClosed = setIDPopupClosed;
        delegate->autorelease();
        return delegate;
    }
};
