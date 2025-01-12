#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CCCircleWaveDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCCCircleWaveDelegate : public cocos2d::CCObject, public CCCircleWaveDelegate {
protected:
    std::function<void(LambdaCCCircleWaveDelegate*, CCCircleWave*)> m_circleWaveWillBeRemoved;
public:
    void circleWaveWillBeRemoved(CCCircleWave* p0) override {
        if (m_circleWaveWillBeRemoved) return m_circleWaveWillBeRemoved(this, p0);
    }

    static LambdaCCCircleWaveDelegate* create(
        std::function<void(LambdaCCCircleWaveDelegate*, CCCircleWave*)> const& circleWaveWillBeRemoved = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaCCCircleWaveDelegate();
        delegate->m_circleWaveWillBeRemoved = circleWaveWillBeRemoved;
        delegate->autorelease();
        return delegate;
    }
};
