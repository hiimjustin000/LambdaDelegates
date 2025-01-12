#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/MessageListDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaMessageListDelegate : public cocos2d::CCObject, public MessageListDelegate {
protected:
    std::function<void(LambdaMessageListDelegate*, cocos2d::CCArray*, char const*)> m_loadMessagesFinished;
    std::function<void(LambdaMessageListDelegate*, char const*, GJErrorCode)> m_loadMessagesFailed;
    std::function<void(LambdaMessageListDelegate*, bool)> m_forceReloadMessages;
    std::function<void(LambdaMessageListDelegate*, gd::string, char const*)> m_setupPageInfo;
public:
    void loadMessagesFinished(cocos2d::CCArray* p0, char const* p1) override {
        if (m_loadMessagesFinished) return m_loadMessagesFinished(this, p0, p1);
    }
    void loadMessagesFailed(char const* p0, GJErrorCode p1) override {
        if (m_loadMessagesFailed) return m_loadMessagesFailed(this, p0, p1);
    }
    void forceReloadMessages(bool p0) override {
        if (m_forceReloadMessages) return m_forceReloadMessages(this, p0);
    }
    void setupPageInfo(gd::string p0, char const* p1) override {
        if (m_setupPageInfo) return m_setupPageInfo(this, p0, p1);
    }

    static LambdaMessageListDelegate* create(
        std::function<void(LambdaMessageListDelegate*, cocos2d::CCArray*, char const*)> const& loadMessagesFinished = [](auto*, auto*, auto const*) {},
        std::function<void(LambdaMessageListDelegate*, char const*, GJErrorCode)> const& loadMessagesFailed = [](auto*, auto const*, auto) {},
        std::function<void(LambdaMessageListDelegate*, bool)> const& forceReloadMessages = [](auto*, auto) {},
        std::function<void(LambdaMessageListDelegate*, gd::string, char const*)> const& setupPageInfo = [](auto*, auto, auto const*) {}
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
