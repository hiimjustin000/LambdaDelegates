#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJMPDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJMPDelegate : public cocos2d::CCObject, public GJMPDelegate {
protected:
    std::function<void(LambdaGJMPDelegate*, int)> m_joinLobbyFinished;
    std::function<void(LambdaGJMPDelegate*, int, GJMPErrorCode)> m_joinLobbyFailed;
    std::function<void(LambdaGJMPDelegate*, int)> m_didUploadMPComment;
    std::function<void(LambdaGJMPDelegate*)> m_updateComments;
public:
    void joinLobbyFinished(int p0) override {
        if (m_joinLobbyFinished) return m_joinLobbyFinished(this, p0);
    }
    void joinLobbyFailed(int p0, GJMPErrorCode p1) override {
        if (m_joinLobbyFailed) return m_joinLobbyFailed(this, p0, p1);
    }
    void didUploadMPComment(int p0) override {
        if (m_didUploadMPComment) return m_didUploadMPComment(this, p0);
    }
    void updateComments() override {
        if (m_updateComments) return m_updateComments(this);
    }

    static LambdaGJMPDelegate* create(
        std::function<void(LambdaGJMPDelegate*, int)> const& joinLobbyFinished = [](auto*, auto) {},
        std::function<void(LambdaGJMPDelegate*, int, GJMPErrorCode)> const& joinLobbyFailed = [](auto*, auto, auto) {},
        std::function<void(LambdaGJMPDelegate*, int)> const& didUploadMPComment = [](auto*, auto) {},
        std::function<void(LambdaGJMPDelegate*)> const& updateComments = [](auto*) {}
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
