#include "components/SpriteComponent.h"
#include <GL/glew.h>

SpriteComponent::draw()
{
  m_actor->vertex_array()->set_active();

  m_actor->game()->shader()->set_uniform("mv_matrix", m_actor->mv_matrix());

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}