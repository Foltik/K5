#pragma once

#include "Frame.h"

#include <stack>
#include <memory>

namespace k5 {
    class FrameStack {
    public:
        // Forward parameters to construct in place
        template<typename... Args>
        void emplaceFrame(Args&&... args) {
            pauseTop();
            frames.emplace(std::forward<Args>(args)...);
        }

        // std::move in an existing Frame pointer
        void pushFrame(std::unique_ptr<Frame> frame);

        void popFrame();

    protected:
        FrameStack() = default;
        ~FrameStack() = default;

    private:
        void pauseTop();
        void resumeTop();

        std::stack<std::unique_ptr<Frame>> frames;
    };
}
