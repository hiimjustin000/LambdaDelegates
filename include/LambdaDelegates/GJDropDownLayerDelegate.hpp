#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJDropDownLayerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJDropDownLayerDelegate : public cocos2d::CCObject, public GJDropDownLayerDelegate {
protected:
    std::function<void(LambdaGJDropDownLayerDelegate*, GJDropDownLayer*)> m_dropDownLayerWillClose;
public:
    void dropDownLayerWillClose(GJDropDownLayer* p0) override {
        if (m_dropDownLayerWillClose) return m_dropDownLayerWillClose(this, p0);
    }

    static LambdaGJDropDownLayerDelegate* create(
        std::function<void(LambdaGJDropDownLayerDelegate*, GJDropDownLayer*)> const& dropDownLayerWillClose = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaGJDropDownLayerDelegate();
        delegate->m_dropDownLayerWillClose = dropDownLayerWillClose;
        delegate->autorelease();
        return delegate;
    }
};
