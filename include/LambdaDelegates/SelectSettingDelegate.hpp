#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SelectSettingDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSelectSettingDelegate : public cocos2d::CCObject, public SelectSettingDelegate {
public:
    std::function<void(SelectSettingLayer*)> m_selectSettingClosed;

    void selectSettingClosed(SelectSettingLayer* p0) override {
        if (m_selectSettingClosed) return m_selectSettingClosed(p0);
    }

    static LambdaSelectSettingDelegate* create(
        std::function<void(SelectSettingLayer*)> const& selectSettingClosed = [](auto) {}
    ) {
        auto delegate = new LambdaSelectSettingDelegate();
        delegate->m_selectSettingClosed = selectSettingClosed;
        delegate->autorelease();
        return delegate;
    }
};
