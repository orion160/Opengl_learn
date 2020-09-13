#include "shader_class.h"

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
    // 1. retrieve the shader source code from filePath
    std::string vShaderCode = retrieve_source(vertexPath);
    //std::cout << vShaderCode << '\n';
    std::string fShaderCode = retrieve_source(fragmentPath);
   // std::cout << fShaderCode << '\n';



    // 2. compile shaders
    GLuint vertex = create_vertex_shader(vShaderCode.c_str());
    GLuint fragment = create_fragment_shader(fShaderCode.c_str());

    ID = create_shader_program(vertex, fragment);
    
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), static_cast<int>(value));
}
void Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

std::string Shader::retrieve_source(const std::string& path)
{
    std::string code;
    std::ifstream file;

    // ensure ifstream objects can throw exceptions:
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        /*Steps*/
        /*
            1. Open files
            2. Read file's buffer contents into streams
            3. Close file handlers
            4. Convert stream into string
        */

        // Retrieve fragment shader code
        file.open(path);
        std::stringstream shader_stream;
        shader_stream << file.rdbuf();
        file.close();
        code = shader_stream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    return code;
}

GLuint Shader::create_vertex_shader(const char* source)
{
    GLuint vertex;
    
    // fragment Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &source, nullptr);
    glCompileShader(vertex);

    // print compile errors if any
    int success;
    char infoLog[512];
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    return vertex;
}

GLuint Shader::create_fragment_shader(const char* source)
{
    GLuint fragment;

    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &source, nullptr);
    glCompileShader(fragment);
    
    // print compile errors if any
    int success;
    char infoLog[512];
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    return fragment;
}

GLuint Shader::create_shader_program(GLuint vertex, GLuint fragment)
{
    GLuint ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);


    // print linking errors if any
    int success;
    char infoLog[512];
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    return ID;
}