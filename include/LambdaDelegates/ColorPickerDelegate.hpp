#pragma once
#include <functional>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaColorPickerDelegate : public cocos2d::CCObject, public cocos2d::extension::ColorPickerDelegate {
protected:
    std::function<void(LambdaColorPickerDelegate*, cocos2d::ccColor3B)> m_colorValueChanged;
public:
    void colorValueChanged(cocos2d::ccColor3B p0) override {
        if (m_colorValueChanged) return m_colorValueChanged(this, p0);
    }

    static LambdaColorPickerDelegate* create(
        std::function<void(LambdaColorPickerDelegate*, cocos2d::ccColor3B)> const& colorValueChanged = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaColorPickerDelegate();
        delegate->m_colorValueChanged = colorValueChanged;
        delegate->autorelease();
        return delegate;
    }
};
