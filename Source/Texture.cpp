#include "Texture.hpp"

char *textureFileNames[8] = {
    // file names for the files from which texture images are loaded
    "textures/Earth-1024x512.jpg",
    "textures/NightEarth-512x256.jpg",
    "textures/brick001.jpg",
    "textures/marble.jpg",
    "textures/mandelbrot.jpeg",
    "textures/mandelbrot.jpeg",
    "textures/earth2048.bmp",
    "textures/moon1024.bmp",
};

bool Texture::loadTexture() {
  cout << "Load texture" << endl;
  /* load an image file directly as a new OpenGL texture */

  for (int i = 0; i < 8; ++i)
  {
    GLuint textureNumber = SOIL_load_OGL_texture(
        textureFileNames[i],
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y);

    if (textureNumber == 0)
    {
      cout << "Load texture " << i << " FAIL" << endl;
      return false;
    }
    textureList.push_back(textureNumber);
  }

  return true;
}