#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SelectListIconDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSelectListIconDelegate : public cocos2d::CCObject, public SelectListIconDelegate {
protected:
    std::function<void(LambdaSelectListIconDelegate*, SelectListIconLayer*)> m_iconSelectClosed;
public:
    void iconSelectClosed(SelectListIconLayer* p0) override {
        if (m_iconSelectClosed) return m_iconSelectClosed(this, p0);
    }

    static LambdaSelectListIconDelegate* create(
        std::function<void(LambdaSelectListIconDelegate*, SelectListIconLayer*)> const& iconSelectClosed = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaSelectListIconDelegate();
        delegate->m_iconSelectClosed = iconSelectClosed;
        delegate->autorelease();
        return delegate;
    }
};
