#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJDropDownLayerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJDropDownLayerDelegate : public cocos2d::CCObject, public GJDropDownLayerDelegate {
public:
    std::function<void(GJDropDownLayer*)> m_dropDownLayerWillClose;

    void dropDownLayerWillClose(GJDropDownLayer* p0) override {
        return m_dropDownLayerWillClose(p0);
    }

    static LambdaGJDropDownLayerDelegate* create(
        std::function<void(GJDropDownLayer*)> const& dropDownLayerWillClose = [](auto) {}
    ) {
        auto delegate = new LambdaGJDropDownLayerDelegate();
        delegate->m_dropDownLayerWillClose = dropDownLayerWillClose;
        delegate->autorelease();
        return delegate;
    }
};
