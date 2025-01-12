#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/NumberInputDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaNumberInputDelegate : public cocos2d::CCObject, public NumberInputDelegate {
protected:
    std::function<void(LambdaNumberInputDelegate*, NumberInputLayer*)> m_numberInputClosed;
public:
    void numberInputClosed(NumberInputLayer* p0) override {
        if (m_numberInputClosed) return m_numberInputClosed(this, p0);
    }

    static LambdaNumberInputDelegate* create(
        std::function<void(LambdaNumberInputDelegate*, NumberInputLayer*)> const& numberInputClosed = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaNumberInputDelegate();
        delegate->m_numberInputClosed = numberInputClosed;
        delegate->autorelease();
        return delegate;
    }
};
