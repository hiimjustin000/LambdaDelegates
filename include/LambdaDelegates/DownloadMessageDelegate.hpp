#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/DownloadMessageDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaDownloadMessageDelegate : public cocos2d::CCObject, public DownloadMessageDelegate {
protected:
    std::function<void(LambdaDownloadMessageDelegate*, GJUserMessage*)> m_downloadMessageFinished;
    std::function<void(LambdaDownloadMessageDelegate*, int)> m_downloadMessageFailed;
public:
    void downloadMessageFinished(GJUserMessage* p0) override {
        if (m_downloadMessageFinished) return m_downloadMessageFinished(this, p0);
    }
    void downloadMessageFailed(int p0) override {
        if (m_downloadMessageFailed) return m_downloadMessageFailed(this, p0);
    }

    static LambdaDownloadMessageDelegate* create(
        std::function<void(LambdaDownloadMessageDelegate*, GJUserMessage*)> const& downloadMessageFinished = [](auto*, auto*) {},
        std::function<void(LambdaDownloadMessageDelegate*, int)> const& downloadMessageFailed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaDownloadMessageDelegate();
        delegate->m_downloadMessageFinished = downloadMessageFinished;
        delegate->m_downloadMessageFailed = downloadMessageFailed;
        delegate->autorelease();
        return delegate;
    }
};
