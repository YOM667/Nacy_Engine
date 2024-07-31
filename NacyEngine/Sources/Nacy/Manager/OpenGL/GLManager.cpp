#include "pch.h"
#include "GLManager.h"

namespace GL
{
	void GLManager::GLEnable(uint32_t operation)
	{
		glEnable(operation);
	}
	void GLManager::GLDisable(uint32_t operation)
	{
		glDisable(operation);
	}

	void GLManager::Start(uint32_t operation, GLOperationFunc func)
	{
		GLManager::GLEnable(operation);
		func();
		GLManager::GLDisable(operation);
	}

	void GLManager::StartBlend(uint32_t sfactor, uint32_t dfactor, GLOperationFunc func)
	{
		GLManager::Blend();
		GLManager::BlendFunc(sfactor, dfactor);
		func();
		GLManager::DisableBlend();
	}

	void GLManager::Blend()
	{
		GLManager::GLEnable(NACY_GL_BLEND);
	}

	void GLManager::BlendFunc(uint32_t sfactor, uint32_t dfactor)
	{
		glBlendFunc(sfactor, dfactor);
	}
	void GLManager::CullFace()
	{
		GLManager::GLEnable(NACY_GL_CULL_FACE);
	}
	void GLManager::StartCullFace(GLOperationFunc func)
	{
		Start(NACY_GL_CULL_FACE, func);
	}
	void GLManager::DisableCullFace()
	{
		GLManager::GLDisable(NACY_GL_CULL_FACE);
	}
	void GLManager::DisableBlend()
	{
		GLManager::GLDisable(NACY_GL_BLEND);
	}
}

