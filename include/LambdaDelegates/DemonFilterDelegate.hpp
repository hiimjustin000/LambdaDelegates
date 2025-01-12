#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/DemonFilterDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaDemonFilterDelegate : public cocos2d::CCObject, public DemonFilterDelegate {
protected:
    std::function<void(LambdaDemonFilterDelegate*, int)> m_demonFilterSelectClosed;
public:
    void demonFilterSelectClosed(int p0) override {
        if (m_demonFilterSelectClosed) return m_demonFilterSelectClosed(this, p0);
    }

    static LambdaDemonFilterDelegate* create(
        std::function<void(LambdaDemonFilterDelegate*, int)> const& demonFilterSelectClosed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaDemonFilterDelegate();
        delegate->m_demonFilterSelectClosed = demonFilterSelectClosed;
        delegate->autorelease();
        return delegate;
    }
};
