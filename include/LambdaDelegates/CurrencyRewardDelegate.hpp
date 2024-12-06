#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CurrencyRewardDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCurrencyRewardDelegate : public cocos2d::CCObject, public CurrencyRewardDelegate {
public:
    std::function<void(CurrencyRewardLayer*)> m_currencyWillExit;

    void currencyWillExit(CurrencyRewardLayer* p0) override {
        if (m_currencyWillExit) return m_currencyWillExit(p0);
    }

    static LambdaCurrencyRewardDelegate* create(
        std::function<void(CurrencyRewardLayer*)> const& currencyWillExit = [](auto) {}
    ) {
        auto delegate = new LambdaCurrencyRewardDelegate();
        delegate->m_currencyWillExit = currencyWillExit;
        delegate->autorelease();
        return delegate;
    }
};
