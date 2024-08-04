#pragma once

#include "Nacy/Core/Core.h"
#include "Nacy/Object/Components/Component.hpp"

namespace Nacy {
    class GameObject {
    public:
        NACY_API GameObject(std::string name);

        NACY_API bool GetVisible();

        NACY_API std::string GetName();

        NACY_API virtual void Render();

        NACY_API virtual void Update();

        template<class T>
        inline T *GetComponent() {
            for (auto component: this->components) {
                if (T::GetStaticType() == component->GetType()) {
                    T *t = dynamic_cast<T *>(component);
                    return t;
                }

            }
            return nullptr;
        }

        NACY_API void AddComponent(Component *component);

        NACY_API void SetVisible(bool visible);

    private:
        std::vector<Component *> components;
        std::string name;
        bool visiable;
    };
}