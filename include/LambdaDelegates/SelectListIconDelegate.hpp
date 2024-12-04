#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SelectListIconDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSelectListIconDelegate : public cocos2d::CCObject, public SelectListIconDelegate {
public:
    std::function<void(SelectListIconLayer*)> m_iconSelectClosed;

    void iconSelectClosed(SelectListIconLayer* p0) override {
        return m_iconSelectClosed(p0);
    }

    static LambdaSelectListIconDelegate* create(
        std::function<void(SelectListIconLayer*)> const& iconSelectClosed = [](auto) {}
    ) {
        auto delegate = new LambdaSelectListIconDelegate();
        delegate->m_iconSelectClosed = iconSelectClosed;
        delegate->autorelease();
        return delegate;
    }
};
