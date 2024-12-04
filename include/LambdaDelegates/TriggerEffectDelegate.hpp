#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TriggerEffectDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaTriggerEffectDelegate : public cocos2d::CCObject, public TriggerEffectDelegate {
public:
    std::function<void(int, bool, gd::vector<int> const&, int, int)> m_toggleGroupTriggered;
    std::function<void(int, bool, double, gd::vector<int> const&, int, int)> m_spawnGroup;
    std::function<void(GameObject*, double, gd::vector<int> const&)> m_spawnObject;

    void toggleGroupTriggered(int p0, bool p1, gd::vector<int> const& p2, int p3, int p4) override {
        return m_toggleGroupTriggered(p0, p1, p2, p3, p4);
    }
    void spawnGroup(int p0, bool p1, double p2, gd::vector<int> const& p3, int p4, int p5) override {
        return m_spawnGroup(p0, p1, p2, p3, p4, p5);
    }
    void spawnObject(GameObject* p0, double p1, gd::vector<int> const& p2) override {
        return m_spawnObject(p0, p1, p2);
    }

    static LambdaTriggerEffectDelegate* create(
        std::function<void(int, bool, gd::vector<int> const&, int, int)> const& toggleGroupTriggered,
        std::function<void(int, bool, double, gd::vector<int> const&, int, int)> const& spawnGroup,
        std::function<void(GameObject*, double, gd::vector<int> const&)> const& spawnObject
    ) {
        auto delegate = new LambdaTriggerEffectDelegate();
        delegate->m_toggleGroupTriggered = toggleGroupTriggered;
        delegate->m_spawnGroup = spawnGroup;
        delegate->m_spawnObject = spawnObject;
        delegate->autorelease();
        return delegate;
    }
};
