#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/UploadPopupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaUploadPopupDelegate : public cocos2d::CCObject, public UploadPopupDelegate {
protected:
    std::function<void(LambdaUploadPopupDelegate*, UploadActionPopup*)> m_onClosePopup;
public:
    void onClosePopup(UploadActionPopup* p0) override {
        if (m_onClosePopup) return m_onClosePopup(this, p0);
    }

    static LambdaUploadPopupDelegate* create(
        std::function<void(LambdaUploadPopupDelegate*, UploadActionPopup*)> const& onClosePopup = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaUploadPopupDelegate();
        delegate->m_onClosePopup = onClosePopup;
        delegate->autorelease();
        return delegate;
    }
};
