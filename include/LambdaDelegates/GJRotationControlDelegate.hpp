#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJRotationControlDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJRotationControlDelegate : public cocos2d::CCObject, public GJRotationControlDelegate {
public:
    std::function<void(float)> m_angleChanged;
    std::function<void()> m_angleChangeBegin;
    std::function<void()> m_angleChangeEnded;

    void angleChanged(float p0) override {
        if (m_angleChanged) return m_angleChanged(p0);
    }
    void angleChangeBegin() override {
        if (m_angleChangeBegin) return m_angleChangeBegin();
    }
    void angleChangeEnded() override {
        if (m_angleChangeEnded) return m_angleChangeEnded();
    }

    static LambdaGJRotationControlDelegate* create(
        std::function<void(float)> const& angleChanged = [](auto) {},
        std::function<void()> const& angleChangeBegin = []() {},
        std::function<void()> const& angleChangeEnded = []() {}
    ) {
        auto delegate = new LambdaGJRotationControlDelegate();
        delegate->m_angleChanged = angleChanged;
        delegate->m_angleChangeBegin = angleChangeBegin;
        delegate->m_angleChangeEnded = angleChangeEnded;
        delegate->autorelease();
        return delegate;
    }
};
