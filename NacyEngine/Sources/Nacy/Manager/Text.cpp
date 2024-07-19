#include "pch.h"

#include "Text.h"
#include "ResourceManager.h"

namespace Engine
{
	TextRenderer::TextRenderer() :
		transform(glm::mat4(0))
	{
		// load and configure shader
		this->textShader = ResourceManager::GetShader("textShader");
		this->textShader.use();
		this->textShader.setInt("text", 0);

		// configure VAO/VBO for texture quads
		float vertices[] = {
			 1.0f,  1.0f, 0.0f,  // top right
			 1.0f, -0.0f, 0.0f,  // bottom right
			-0.0f, -0.0f, 0.0f,  // bottom left
			-0.0f,  1.0f, 0.0f   // top left 
		};
		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 3,  // first Triangle
			1, 2, 3   // second Triangle
		};
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
	}
	TextRenderer::~TextRenderer()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	void TextRenderer::load(std::string font, uint32_t fontSize)
	{
		characters.clear();

		FT_Library ft;
		if (FT_Init_FreeType(&ft))
		{
			std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
		}

		FT_Face face;
		if (FT_New_Face(ft, font.c_str(), 0, &face))
		{
			std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
		}

		FT_Set_Pixel_Sizes(face, 0, fontSize);

		if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
		{
			std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
		}

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

		for (unsigned char c = 0; c < 128; c++)
		{
			// load character GLCall(glyph 
			if (FT_Load_Char(face, c, FT_LOAD_RENDER))
			{
				std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
				continue;
			}

			// generate texture
			unsigned int texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				GL_RED,
				face->glyph->bitmap.width,
				face->glyph->bitmap.rows,
				0,
				GL_RED,
				GL_UNSIGNED_BYTE,
				face->glyph->bitmap.buffer
			);

			// set texture options
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			// now store character for later use
			Character character = {
				texture,
				glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
				glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
				face->glyph->advance.x
			};

			characters.insert(std::pair<char, Character>(c, character));
		}

		FT_Done_Face(face);
		FT_Done_FreeType(ft);
	}

	void TextRenderer::renderText(std::string text, float x, float y, float scale, glm::vec4 color)
	{
		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


		glActiveTexture(GL_TEXTURE0);

		// activate corresponding render state	
		this->textShader.use();
		this->textShader.setVector4F("textColor", color);

		// iterate through all characters
		std::string::const_iterator c;
		for (c = text.begin(); c != text.end(); c++)
		{
			Character ch = characters[*c];

			float xpos = x + ch.Bearing.x * scale;
			float ypos = y + (this->characters['H'].Bearing.y - ch.Bearing.y) * scale;

			float w = ch.Size.x * scale;
			float h = ch.Size.y * scale;
			glm::mat4 transform(1.0f);
			// update VBO for each character
			transform = glm::translate(transform, glm::vec3(glm::vec2(xpos, ypos), 0.0f));
			transform = glm::scale(transform, glm::vec3(w, h, 1.0f));

			this->textShader.setMatrix4F("transform", transform);

			glBindTexture(GL_TEXTURE_2D, ch.TextureID);

			glBindVertexArray(this->VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

			x += (ch.Advance >> 6) * scale;
		}

		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);

		glDisable(GL_BLEND);
		glDisable(GL_CULL_FACE);
	}
	void TextRenderer::renderCenterdText(std::string text, float x, float y, float scale, glm::vec4 color)
	{
		this->renderText(text, x - (this->getTextSize(text, scale).x / 2.0f),y,scale,color);
	}
	glm::vec2 TextRenderer::getTextSize(std::string text, float scale)
	{
		std::string::const_iterator c;
		int x = 0;
		Character lastCharacter{};
		float caseY = 0;
		if (!std::all_of(text.begin(), text.end(), islower))
		{
			caseY = characters['H'].Size.y;
		}
		for (c = text.begin(); c != text.end(); c++)
		{
			Character ch = characters[*c];
			x += (ch.Advance / 64) * scale;
		}
		float y = caseY;
		return glm::vec2(x, y);

	}
	void FontRenderer::load(const char* file, float fontSize,const char* name)
	{
		ResourceManager::LoadFont(file,fontSize,name);
	}
	TextRenderer FontRenderer::getFont(const char* fontName)
	{
		return ResourceManager::GetFont(fontName);
	}
}