void Sphere::on_update_mv_matrix(glm::vec2 position, float scale)
{
  m_center += position;
  m_radius *= scale;
}