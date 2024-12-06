#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/DemonFilterDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaDemonFilterDelegate : public cocos2d::CCObject, public DemonFilterDelegate {
public:
    std::function<void(int)> m_demonFilterSelectClosed;

    void demonFilterSelectClosed(int p0) override {
        if (m_demonFilterSelectClosed) return m_demonFilterSelectClosed(p0);
    }

    static LambdaDemonFilterDelegate* create(
        std::function<void(int)> const& demonFilterSelectClosed = [](auto) {}
    ) {
        auto delegate = new LambdaDemonFilterDelegate();
        delegate->m_demonFilterSelectClosed = demonFilterSelectClosed;
        delegate->autorelease();
        return delegate;
    }
};
