#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SelectPremadeDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSelectPremadeDelegate : public cocos2d::CCObject, public SelectPremadeDelegate {
protected:
    std::function<void(LambdaSelectPremadeDelegate*, SelectPremadeLayer*, int)> m_selectPremadeClosed;
public:
    void selectPremadeClosed(SelectPremadeLayer* p0, int p1) override {
        if (m_selectPremadeClosed) return m_selectPremadeClosed(this, p0, p1);
    }

    static LambdaSelectPremadeDelegate* create(
        std::function<void(LambdaSelectPremadeDelegate*, SelectPremadeLayer*, int)> const& selectPremadeClosed = [](auto*, auto*, auto) {}
    ) {
        auto delegate = new LambdaSelectPremadeDelegate();
        delegate->m_selectPremadeClosed = selectPremadeClosed;
        delegate->autorelease();
        return delegate;
    }
};
