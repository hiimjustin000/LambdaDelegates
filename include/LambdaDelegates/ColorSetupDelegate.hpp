#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/ColorSetupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaColorSetupDelegate : public cocos2d::CCObject, public ColorSetupDelegate {
public:
    std::function<void(int)> m_colorSetupClosed;

    void colorSetupClosed(int p0) override {
        if (m_colorSetupClosed) return m_colorSetupClosed(p0);
    }

    static LambdaColorSetupDelegate* create(
        std::function<void(int)> const& colorSetupClosed = [](auto) {}
    ) {
        auto delegate = new LambdaColorSetupDelegate();
        delegate->m_colorSetupClosed = colorSetupClosed;
        delegate->autorelease();
        return delegate;
    }
};
