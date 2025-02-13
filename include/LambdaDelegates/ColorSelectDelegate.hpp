#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/ColorSelectDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaColorSelectDelegate : public cocos2d::CCObject, public ColorSelectDelegate {
protected:
    std::function<void(LambdaColorSelectDelegate*, cocos2d::CCNode*)> m_colorSelectClosed;
public:
    void colorSelectClosed(cocos2d::CCNode* p0) override {
        if (m_colorSelectClosed) return m_colorSelectClosed(this, p0);
    }

    static LambdaColorSelectDelegate* create(
        std::function<void(LambdaColorSelectDelegate*, cocos2d::CCNode*)> const& colorSelectClosed = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaColorSelectDelegate();
        delegate->m_colorSelectClosed = colorSelectClosed;
        delegate->autorelease();
        return delegate;
    }
};
