#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GameRateDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGameRateDelegate : public cocos2d::CCObject, public GameRateDelegate {
public:
    std::function<void()> m_updateRate;

    void updateRate() override {
        return m_updateRate();
    }

    static LambdaGameRateDelegate* create(
        std::function<void()> const& updateRate = []() {}
    ) {
        auto delegate = new LambdaGameRateDelegate();
        delegate->m_updateRate = updateRate;
        delegate->autorelease();
        return delegate;
    }
};
