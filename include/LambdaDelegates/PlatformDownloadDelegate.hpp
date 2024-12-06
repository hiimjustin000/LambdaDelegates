#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/PlatformDownloadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaPlatformDownloadDelegate : public cocos2d::CCObject, public PlatformDownloadDelegate {
public:
    std::function<void(char const*)> m_downloadFinished;
    std::function<void(char const*)> m_downloadFailed;

    void downloadFinished(char const* p0) override {
        if (m_downloadFinished) return m_downloadFinished(p0);
    }
    void downloadFailed(char const* p0) override {
        if (m_downloadFailed) return m_downloadFailed(p0);
    }

    static LambdaPlatformDownloadDelegate* create(
        std::function<void(char const*)> const& downloadFinished = [](auto) {},
        std::function<void(char const*)> const& downloadFailed = [](auto) {}
    ) {
        auto delegate = new LambdaPlatformDownloadDelegate();
        delegate->m_downloadFinished = downloadFinished;
        delegate->m_downloadFailed = downloadFailed;
        delegate->autorelease();
        return delegate;
    }
};
