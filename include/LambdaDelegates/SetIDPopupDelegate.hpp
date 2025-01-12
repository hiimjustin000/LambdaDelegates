#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SetIDPopupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSetIDPopupDelegate : public cocos2d::CCObject, public SetIDPopupDelegate {
protected:
    std::function<void(LambdaSetIDPopupDelegate*, SetIDPopup*, int)> m_setIDPopupClosed;
public:
    void setIDPopupClosed(SetIDPopup* p0, int p1) override {
        if (m_setIDPopupClosed) return m_setIDPopupClosed(this, p0, p1);
    }

    static LambdaSetIDPopupDelegate* create(
        std::function<void(LambdaSetIDPopupDelegate*, SetIDPopup*, int)> const& setIDPopupClosed = [](auto*, auto*, auto) {}
    ) {
        auto delegate = new LambdaSetIDPopupDelegate();
        delegate->m_setIDPopupClosed = setIDPopupClosed;
        delegate->autorelease();
        return delegate;
    }
};
