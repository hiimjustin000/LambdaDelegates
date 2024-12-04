#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/OptionsObjectDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaOptionsObjectDelegate : public cocos2d::CCObject, public OptionsObjectDelegate {
public:
    std::function<void(OptionsObject*)> m_stateChanged;

    void stateChanged(OptionsObject* p0) override {
        return m_stateChanged(p0);
    }

    static LambdaOptionsObjectDelegate* create(
        std::function<void(OptionsObject*)> const& stateChanged = [](auto) {}
    ) {
        auto delegate = new LambdaOptionsObjectDelegate();
        delegate->m_stateChanged = stateChanged;
        delegate->autorelease();
        return delegate;
    }
};
