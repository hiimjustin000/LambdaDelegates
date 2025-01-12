#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GameRateDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGameRateDelegate : public cocos2d::CCObject, public GameRateDelegate {
protected:
    std::function<void(LambdaGameRateDelegate*)> m_updateRate;
public:
    void updateRate() override {
        if (m_updateRate) return m_updateRate(this);
    }

    static LambdaGameRateDelegate* create(
        std::function<void(LambdaGameRateDelegate*)> const& updateRate = [](auto*) {}
    ) {
        auto delegate = new LambdaGameRateDelegate();
        delegate->m_updateRate = updateRate;
        delegate->autorelease();
        return delegate;
    }
};
