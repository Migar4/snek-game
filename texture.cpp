#include "texture.h"

texture::texture()
{
    id = -1;
}

texture::texture(int _id):id(_id){
    if(!getTextureParams())
    {
        cout << "error loading texture " << endl;
    }
}

texture::texture(string path){
    id = SOIL_load_OGL_texture(path.c_str(),
                               SOIL_LOAD_AUTO,
                               SOIL_CREATE_NEW_ID,
                               SOIL_FLAG_MULTIPLY_ALPHA || SOIL_FLAG_INVERT_Y);

    if(!getTextureParams()){
        cout << "error loading texture " << endl;
    }
}

texture::~texture(){

}

bool texture::getTextureParams(){
    if(id > 0 ){
        glBindTexture(GL_TEXTURE_2D, id);

        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);

        return true;
    }

    return false;
}


int texture::getId(){
    return id;
}

int texture::getHeight(){
    return height;
}

int texture::getWidth(){
    return width;
}
