#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/UploadMessageDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaUploadMessageDelegate : public cocos2d::CCObject, public UploadMessageDelegate {
public:
    std::function<void(int)> m_uploadMessageFinished;
    std::function<void(int)> m_uploadMessageFailed;

    void uploadMessageFinished(int p0) override {
        if (m_uploadMessageFinished) return m_uploadMessageFinished(p0);
    }
    void uploadMessageFailed(int p0) override {
        if (m_uploadMessageFailed) return m_uploadMessageFailed(p0);
    }

    static LambdaUploadMessageDelegate* create(
        std::function<void(int)> const& uploadMessageFinished = [](auto) {},
        std::function<void(int)> const& uploadMessageFailed = [](auto) {}
    ) {
        auto delegate = new LambdaUploadMessageDelegate();
        delegate->m_uploadMessageFinished = uploadMessageFinished;
        delegate->m_uploadMessageFailed = uploadMessageFailed;
        delegate->autorelease();
        return delegate;
    }
};
