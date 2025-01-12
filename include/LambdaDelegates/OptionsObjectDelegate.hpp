#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/OptionsObjectDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaOptionsObjectDelegate : public cocos2d::CCObject, public OptionsObjectDelegate {
protected:
    std::function<void(LambdaOptionsObjectDelegate*, OptionsObject*)> m_stateChanged;
public:
    void stateChanged(OptionsObject* p0) override {
        if (m_stateChanged) return m_stateChanged(this, p0);
    }

    static LambdaOptionsObjectDelegate* create(
        std::function<void(LambdaOptionsObjectDelegate*, OptionsObject*)> const& stateChanged = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaOptionsObjectDelegate();
        delegate->m_stateChanged = stateChanged;
        delegate->autorelease();
        return delegate;
    }
};
