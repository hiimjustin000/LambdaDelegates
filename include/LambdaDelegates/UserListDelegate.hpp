#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/UserListDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaUserListDelegate : public cocos2d::CCObject, public UserListDelegate {
public:
    std::function<void(cocos2d::CCArray*, UserListType)> m_getUserListFinished;
    std::function<void(UserListType, GJErrorCode)> m_getUserListFailed;
    std::function<void(cocos2d::CCArray*, UserListType)> m_userListChanged;
    std::function<void(UserListType)> m_forceReloadList;

    void getUserListFinished(cocos2d::CCArray* p0, UserListType p1) override {
        if (m_getUserListFinished) return m_getUserListFinished(p0, p1);
    }
    void getUserListFailed(UserListType p0, GJErrorCode p1) override {
        if (m_getUserListFailed) return m_getUserListFailed(p0, p1);
    }
    void userListChanged(cocos2d::CCArray* p0, UserListType p1) override {
        if (m_userListChanged) return m_userListChanged(p0, p1);
    }
    void forceReloadList(UserListType p0) override {
        if (m_forceReloadList) return m_forceReloadList(p0);
    }

    static LambdaUserListDelegate* create(
        std::function<void(cocos2d::CCArray*, UserListType)> const& getUserListFinished = [](auto, auto) {},
        std::function<void(UserListType, GJErrorCode)> const& getUserListFailed = [](auto, auto) {},
        std::function<void(cocos2d::CCArray*, UserListType)> const& userListChanged = [](auto, auto) {},
        std::function<void(UserListType)> const& forceReloadList = [](auto) {}
    ) {
        auto delegate = new LambdaUserListDelegate();
        delegate->m_getUserListFinished = getUserListFinished;
        delegate->m_getUserListFailed = getUserListFailed;
        delegate->m_userListChanged = userListChanged;
        delegate->m_forceReloadList = forceReloadList;
        delegate->autorelease();
        return delegate;
    }
};
