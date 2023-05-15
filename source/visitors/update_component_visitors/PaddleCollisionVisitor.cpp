void PaddleCollisionVisitor::visit_move_component(MoveComponent* move_component)
{
  move_component->set_speed(0);
}