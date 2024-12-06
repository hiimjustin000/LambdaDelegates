#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJMPDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJMPDelegate : public cocos2d::CCObject, public GJMPDelegate {
public:
    std::function<void(int)> m_joinLobbyFinished;
    std::function<void(int, GJMPErrorCode)> m_joinLobbyFailed;
    std::function<void(int)> m_didUploadMPComment;
    std::function<void()> m_updateComments;

    void joinLobbyFinished(int p0) override {
        if (m_joinLobbyFinished) return m_joinLobbyFinished(p0);
    }
    void joinLobbyFailed(int p0, GJMPErrorCode p1) override {
        if (m_joinLobbyFailed) return m_joinLobbyFailed(p0, p1);
    }
    void didUploadMPComment(int p0) override {
        if (m_didUploadMPComment) return m_didUploadMPComment(p0);
    }
    void updateComments() override {
        if (m_updateComments) return m_updateComments();
    }

    static LambdaGJMPDelegate* create(
        std::function<void(int)> const& joinLobbyFinished = [](auto) {},
        std::function<void(int, GJMPErrorCode)> const& joinLobbyFailed = [](auto, auto) {},
        std::function<void(int)> const& didUploadMPComment = [](auto) {},
        std::function<void()> const& updateComments = []() {}
    ) {
        auto delegate = new LambdaGJMPDelegate();
        delegate->m_joinLobbyFinished = joinLobbyFinished;
        delegate->m_joinLobbyFailed = joinLobbyFailed;
        delegate->m_didUploadMPComment = didUploadMPComment;
        delegate->m_updateComments = updateComments;
        delegate->autorelease();
        return delegate;
    }
};
