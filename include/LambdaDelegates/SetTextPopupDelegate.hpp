#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SetTextPopupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaSetTextPopupDelegate : public cocos2d::CCObject, public SetTextPopupDelegate {
public:
    std::function<void(SetTextPopup*, gd::string)> m_setTextPopupClosed;

    void setTextPopupClosed(SetTextPopup* p0, gd::string p1) override {
        return m_setTextPopupClosed(p0, p1);
    }

    static LambdaSetTextPopupDelegate* create(
        std::function<void(SetTextPopup*, gd::string)> const& setTextPopupClosed = [](auto, auto) {}
    ) {
        auto delegate = new LambdaSetTextPopupDelegate();
        delegate->m_setTextPopupClosed = setTextPopupClosed;
        delegate->autorelease();
        return delegate;
    }
};
