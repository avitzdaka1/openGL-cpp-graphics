#include "Shader.h"

int ShaderProgram::loadShader(const string fname, int type)
{
	ifstream myfile;

	myfile.open(fname,std::ios::in);

	string line;
	string shaderSource;

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line);
			shaderSource.append(line + " \n");
	}

	}
	else
	{
		std::cerr << "Unable to load shader: " << fname << std::endl;
	}
	
	GLuint shaderID = glCreateShader(type);
	const char* data = shaderSource.c_str();
	glShaderSource(shaderID, 1, &data, 0);
	glCompileShader(shaderID);
	
	GLint success = 0;
	glGetShaderiv(shaderID,GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);
		glDeleteShader(shaderID);

	}
	return shaderID;

}

ShaderProgram::ShaderProgram(const char* vertexFile,const char* fragmentFile)
{
	this->vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
	this->fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
	this->programID = glCreateProgram();
	glAttachShader(this->programID, this->vertexShaderID);
	glAttachShader(this->programID, this->fragmentShaderID);
	bindAttributes();
	//bindAttribute(0, "position");
	glLinkProgram(this->programID);

	GLint isLinked = 0;
	glGetProgramiv(this->programID, GL_LINK_STATUS, (int*)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(this->programID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(this->programID, maxLength, &maxLength,&infoLog[0]);

		glDeleteProgram(this->programID);
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		return;
	}
	glDetachShader(this->programID, this->vertexShaderID);
	glDetachShader(this->programID, this->fragmentShaderID);


	glValidateProgram(this->programID);


}

void ShaderProgram::start()
{
		glUseProgram(this->programID);
}

void ShaderProgram::stop()
{
	glUseProgram(0);
}

void ShaderProgram::cleanUP()
{
	stop();
	glDetachShader(this->programID, this->vertexShaderID);
	glDetachShader(this->programID, this->fragmentShaderID);
	glDeleteShader(this->vertexShaderID);
	glDeleteShader(this->fragmentShaderID);
	glDeleteProgram(this->programID);
}

void ShaderProgram::bindAttribute(int attribute, const char* variableName)
{
	glBindAttribLocation(this->programID, attribute, variableName);
}

void ShaderProgram::bindAttributes()
{

}