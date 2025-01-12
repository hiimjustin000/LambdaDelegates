#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SetTextPopupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaSetTextPopupDelegate : public cocos2d::CCObject, public SetTextPopupDelegate {
protected:
    std::function<void(LambdaSetTextPopupDelegate*, SetTextPopup*, gd::string)> m_setTextPopupClosed;
public:
    void setTextPopupClosed(SetTextPopup* p0, gd::string p1) override {
        if (m_setTextPopupClosed) return m_setTextPopupClosed(this, p0, p1);
    }

    static LambdaSetTextPopupDelegate* create(
        std::function<void(LambdaSetTextPopupDelegate*, SetTextPopup*, gd::string)> const& setTextPopupClosed = [](auto*, auto*, auto) {}
    ) {
        auto delegate = new LambdaSetTextPopupDelegate();
        delegate->m_setTextPopupClosed = setTextPopupClosed;
        delegate->autorelease();
        return delegate;
    }
};
