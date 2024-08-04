#pragma once

#include "Nacy/Core/Core.h"

namespace Nacy {
    // Texture2D is able to store and configure a texture in OpenGL.
    // It also hosts utility functions for easy management.
    class NACY_API Texture2D {
    public:
        // Holds the ID of the texture object, used for all texture operations to reference to this particlar texture
        uint32_t id;
        // Texture image dimensions
        uint32_t width, height; // Width and height of loaded image in pixels
        // Texture Format
        uint32_t internalFormat; // Format of texture object
        uint32_t imageFormat; // Format of loaded image
        // Texture configuration
        uint32_t wrapS; // Wrapping mode on S axis
        uint32_t wrapT; // Wrapping mode on T axis
        uint32_t filterMin; // Filtering mode if texture pixels < screen pixels
        uint32_t filterMax; // Filtering mode if texture pixels > screen pixels
        // Constructor (sets default texture modes)
        Texture2D();

        // Generates texture from image data
        void Generate(uint32_t width, uint32_t height, unsigned char *data);

        // Binds the texture as the current active GL_TEXTURE_2D texture object
        void Bind() const;
    };

}
