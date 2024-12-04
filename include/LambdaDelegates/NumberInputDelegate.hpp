#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/NumberInputDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaNumberInputDelegate : public cocos2d::CCObject, public NumberInputDelegate {
public:
    std::function<void(NumberInputLayer*)> m_numberInputClosed;

    void numberInputClosed(NumberInputLayer* p0) override {
        return m_numberInputClosed(p0);
    }

    static LambdaNumberInputDelegate* create(
        std::function<void(NumberInputLayer*)> const& numberInputClosed = [](auto) {}
    ) {
        auto delegate = new LambdaNumberInputDelegate();
        delegate->m_numberInputClosed = numberInputClosed;
        delegate->autorelease();
        return delegate;
    }
};
