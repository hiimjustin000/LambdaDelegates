#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/FriendRequestDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaFriendRequestDelegate : public cocos2d::CCObject, public FriendRequestDelegate {
protected:
    std::function<void(LambdaFriendRequestDelegate*, cocos2d::CCArray*, char const*)> m_loadFRequestsFinished;
    std::function<void(LambdaFriendRequestDelegate*, char const*, GJErrorCode)> m_loadFRequestsFailed;
    std::function<void(LambdaFriendRequestDelegate*, gd::string, char const*)> m_setupPageInfo;
    std::function<void(LambdaFriendRequestDelegate*, bool)> m_forceReloadRequests;
public:
    void loadFRequestsFinished(cocos2d::CCArray* p0, char const* p1) override {
        if (m_loadFRequestsFinished) return m_loadFRequestsFinished(this, p0, p1);
    }
    void loadFRequestsFailed(char const* p0, GJErrorCode p1) override {
        if (m_loadFRequestsFailed) return m_loadFRequestsFailed(this, p0, p1);
    }
    void setupPageInfo(gd::string p0, char const* p1) override {
        if (m_setupPageInfo) return m_setupPageInfo(this, p0, p1);
    }
    void forceReloadRequests(bool p0) override {
        if (m_forceReloadRequests) return m_forceReloadRequests(this, p0);
    }

    static LambdaFriendRequestDelegate* create(
        std::function<void(LambdaFriendRequestDelegate*, cocos2d::CCArray*, char const*)> const& loadFRequestsFinished = [](auto*, auto*, auto const*) {},
        std::function<void(LambdaFriendRequestDelegate*, char const*, GJErrorCode)> const& loadFRequestsFailed = [](auto*, auto const*, auto) {},
        std::function<void(LambdaFriendRequestDelegate*, gd::string, char const*)> const& setupPageInfo = [](auto*, auto, auto const*) {},
        std::function<void(LambdaFriendRequestDelegate*, bool)> const& forceReloadRequests = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaFriendRequestDelegate();
        delegate->m_loadFRequestsFinished = loadFRequestsFinished;
        delegate->m_loadFRequestsFailed = loadFRequestsFailed;
        delegate->m_setupPageInfo = setupPageInfo;
        delegate->m_forceReloadRequests = forceReloadRequests;
        delegate->autorelease();
        return delegate;
    }
};
