#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/FLAlertLayerProtocol.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaFLAlertLayerProtocol : public cocos2d::CCObject, public FLAlertLayerProtocol {
public:
    std::function<void(FLAlertLayer*, bool)> m_FLAlert_Clicked;

    void FLAlert_Clicked(FLAlertLayer* p0, bool p1) override {
        return m_FLAlert_Clicked(p0, p1);
    }

    static LambdaFLAlertLayerProtocol* create(
        std::function<void(FLAlertLayer*, bool)> const& FLAlert_Clicked = [](auto, auto) {}
    ) {
        auto delegate = new LambdaFLAlertLayerProtocol();
        delegate->m_FLAlert_Clicked = FLAlert_Clicked;
        delegate->autorelease();
        return delegate;
    }
};
