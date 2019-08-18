#pragma once

namespace Demo
{
	struct Image
	{
		unsigned char* Pixels;
		int Width;
		int Height;
		int Channels;
	};

	class Texture
	{
	private:
		static const int LEVEL_OF_DETAIL = 0;
		static const int BORDER = 0;

		unsigned int id;
		unsigned int target;

	public:
		Texture(const std::string& filepath);
		~Texture();

		void Bind(unsigned int textureUnit = 0) const;
		void Unbind() const;

	private:
		Image Load(const std::string& filepath);
		void Init(const Image& image);
		void Free(const Image& image);
	};
}
