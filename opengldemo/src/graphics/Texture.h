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

		void Bind() const;
		void Unbind() const;

	private:
		const Image& Load(const std::string& filepath);
		void Init(const Image& pixels);
		void Free(const Image& pixels);
	};
}
