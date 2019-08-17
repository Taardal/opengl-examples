#pragma once

namespace Demo
{
	class IndexBuffer
	{
	private:
		unsigned int id;
		unsigned int count;

	public:
		IndexBuffer(unsigned int* indices, unsigned int size);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		unsigned int GetCount() const;
	};
}