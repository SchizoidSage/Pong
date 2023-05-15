BoxComponent::BoxComponent(Actor* owner, AABB& object_shape)
	: Component{ owner },
		m_object_shape{ object_shape }
{ 
	m_actor->game()->collision_engine()->add_box(this);
}

BoxComponent::~BoxComponent()
{
	m_actor->game()->collision_engine()->remove_box(this);
}

void BoxComponent::on_update_mv_matrix()
{
	m_world_box = m_object_box;
	m_world_box->on_update_mv_matrix();
}