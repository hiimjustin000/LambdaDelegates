#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/ColorSetupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaColorSetupDelegate : public cocos2d::CCObject, public ColorSetupDelegate {
protected:
    std::function<void(LambdaColorSetupDelegate*, int)> m_colorSetupClosed;
public:
    void colorSetupClosed(int p0) override {
        if (m_colorSetupClosed) return m_colorSetupClosed(this, p0);
    }

    static LambdaColorSetupDelegate* create(
        std::function<void(LambdaColorSetupDelegate*, int)> const& colorSetupClosed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaColorSetupDelegate();
        delegate->m_colorSetupClosed = colorSetupClosed;
        delegate->autorelease();
        return delegate;
    }
};
