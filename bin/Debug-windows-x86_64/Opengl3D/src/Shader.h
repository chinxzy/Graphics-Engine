#pragma once

class Shader
{
public:

	unsigned int Program;

	Shader(const char* ShadersFilePath);


	void Use();

	void SetBool(const char* String, bool Value)const;
	void SetInt(const char* String, int Value)const;
	void SetFloat(const char* String, float Value)const;



	~Shader();
};