#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/FLAlertLayerProtocol.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaFLAlertLayerProtocol : public cocos2d::CCObject, public FLAlertLayerProtocol {
protected:
    std::function<void(LambdaFLAlertLayerProtocol*, FLAlertLayer*, bool)> m_FLAlert_Clicked;
public:
    void FLAlert_Clicked(FLAlertLayer* p0, bool p1) override {
        if (m_FLAlert_Clicked) return m_FLAlert_Clicked(this, p0, p1);
    }

    static LambdaFLAlertLayerProtocol* create(
        std::function<void(LambdaFLAlertLayerProtocol*, FLAlertLayer*, bool)> const& FLAlert_Clicked = [](auto*, auto*, auto) {}
    ) {
        auto delegate = new LambdaFLAlertLayerProtocol();
        delegate->m_FLAlert_Clicked = FLAlert_Clicked;
        delegate->autorelease();
        return delegate;
    }
};
