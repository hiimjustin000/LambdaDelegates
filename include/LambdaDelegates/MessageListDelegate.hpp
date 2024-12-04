#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/MessageListDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaMessageListDelegate : public cocos2d::CCObject, public MessageListDelegate {
public:
    std::function<void(cocos2d::CCArray*, char const*)> m_loadMessagesFinished;
    std::function<void(char const*, GJErrorCode)> m_loadMessagesFailed;
    std::function<void(bool)> m_forceReloadMessages;
    std::function<void(gd::string, char const*)> m_setupPageInfo;

    void loadMessagesFinished(cocos2d::CCArray* p0, char const* p1) override {
        return m_loadMessagesFinished(p0, p1);
    }
    void loadMessagesFailed(char const* p0, GJErrorCode p1) override {
        return m_loadMessagesFailed(p0, p1);
    }
    void forceReloadMessages(bool p0) override {
        return m_forceReloadMessages(p0);
    }
    void setupPageInfo(gd::string p0, char const* p1) override {
        return m_setupPageInfo(p0, p1);
    }

    static LambdaMessageListDelegate* create(
        std::function<void(cocos2d::CCArray*, char const*)> const& loadMessagesFinished = [](auto, auto) {},
        std::function<void(char const*, GJErrorCode)> const& loadMessagesFailed = [](auto, auto) {},
        std::function<void(bool)> const& forceReloadMessages = [](auto) {},
        std::function<void(gd::string, char const*)> const& setupPageInfo = [](auto, auto) {}
    ) {
        auto delegate = new LambdaMessageListDelegate();
        delegate->m_loadMessagesFinished = loadMessagesFinished;
        delegate->m_loadMessagesFailed = loadMessagesFailed;
        delegate->m_forceReloadMessages = forceReloadMessages;
        delegate->m_setupPageInfo = setupPageInfo;
        delegate->autorelease();
        return delegate;
    }
};
