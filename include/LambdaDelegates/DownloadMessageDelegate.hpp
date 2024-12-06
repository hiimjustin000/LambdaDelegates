#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/DownloadMessageDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaDownloadMessageDelegate : public cocos2d::CCObject, public DownloadMessageDelegate {
public:
    std::function<void(GJUserMessage*)> m_downloadMessageFinished;
    std::function<void(int)> m_downloadMessageFailed;

    void downloadMessageFinished(GJUserMessage* p0) override {
        if (m_downloadMessageFinished) return m_downloadMessageFinished(p0);
    }
    void downloadMessageFailed(int p0) override {
        if (m_downloadMessageFailed) return m_downloadMessageFailed(p0);
    }

    static LambdaDownloadMessageDelegate* create(
        std::function<void(GJUserMessage*)> const& downloadMessageFinished = [](auto) {},
        std::function<void(int)> const& downloadMessageFailed = [](auto) {}
    ) {
        auto delegate = new LambdaDownloadMessageDelegate();
        delegate->m_downloadMessageFinished = downloadMessageFinished;
        delegate->m_downloadMessageFailed = downloadMessageFailed;
        delegate->autorelease();
        return delegate;
    }
};
