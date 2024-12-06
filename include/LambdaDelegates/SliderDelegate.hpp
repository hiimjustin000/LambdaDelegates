#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SliderDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSliderDelegate : public cocos2d::CCObject, public SliderDelegate {
public:
    std::function<void(Slider*)> m_sliderBegan;
    std::function<void(Slider*)> m_sliderEnded;

    void sliderBegan(Slider* p0) override {
        if (m_sliderBegan) return m_sliderBegan(p0);
    }
    void sliderEnded(Slider* p0) override {
        if (m_sliderEnded) return m_sliderEnded(p0);
    }

    static LambdaSliderDelegate* create(
        std::function<void(Slider*)> const& sliderBegan = [](auto) {},
        std::function<void(Slider*)> const& sliderEnded = [](auto) {}
    ) {
        auto delegate = new LambdaSliderDelegate();
        delegate->m_sliderBegan = sliderBegan;
        delegate->m_sliderEnded = sliderEnded;
        delegate->autorelease();
        return delegate;
    }
};
