#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/UploadPopupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaUploadPopupDelegate : public cocos2d::CCObject, public UploadPopupDelegate {
public:
    std::function<void(UploadActionPopup*)> m_onClosePopup;

    void onClosePopup(UploadActionPopup* p0) override {
        return m_onClosePopup(p0);
    }

    static LambdaUploadPopupDelegate* create(
        std::function<void(UploadActionPopup*)> const& onClosePopup = [](auto) {}
    ) {
        auto delegate = new LambdaUploadPopupDelegate();
        delegate->m_onClosePopup = onClosePopup;
        delegate->autorelease();
        return delegate;
    }
};
