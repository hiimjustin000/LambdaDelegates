#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/HSVWidgetDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaHSVWidgetDelegate : public cocos2d::CCObject, public HSVWidgetDelegate {
protected:
    std::function<void(LambdaHSVWidgetDelegate*, HSVWidgetPopup*, cocos2d::ccHSVValue)> m_hsvPopupClosed;
    std::function<void(LambdaHSVWidgetDelegate*, ConfigureHSVWidget*)> m_hsvChanged;
public:
    void hsvPopupClosed(HSVWidgetPopup* p0, cocos2d::ccHSVValue p1) override {
        if (m_hsvPopupClosed) return m_hsvPopupClosed(this, p0, p1);
    }
    void hsvChanged(ConfigureHSVWidget* p0) override {
        if (m_hsvChanged) return m_hsvChanged(this, p0);
    }

    static LambdaHSVWidgetDelegate* create(
        std::function<void(LambdaHSVWidgetDelegate*, HSVWidgetPopup*, cocos2d::ccHSVValue)> const& hsvPopupClosed = [](auto*, auto*, auto) {},
        std::function<void(LambdaHSVWidgetDelegate*, ConfigureHSVWidget*)> const& hsvChanged = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaHSVWidgetDelegate();
        delegate->m_hsvPopupClosed = hsvPopupClosed;
        delegate->m_hsvChanged = hsvChanged;
        delegate->autorelease();
        return delegate;
    }
};
